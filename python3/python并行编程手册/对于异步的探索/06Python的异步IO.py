"""
生成器（Generator），它的特点和协程很像。
每一次迭代之间，会暂停执行，继续下一次迭代的时候还不会丢失先前的状态。
便有了PEP 342，此时的生成器可以通过yield 暂停执行和向外返回数据，也可以通过send()向生成器内发送数据，还可以通过throw()向生成器内抛出异常以便随时终止生成器的运行。

"""

import socket
import selectors


stopped = False
selector = selectors.DefaultSelector()
urls_todo = set(['/', "/1", "/2", "/3", "/4", "/5", "/6", "/7", "/8", "/9"])

# 不使用回调的方式, 实现Future对象来知道异步调用的结果
# 未来对象有一个result属性，用于存放未来的执行结果。
# 还有个set_result()方法，是用于设置result的，并且会在给result绑定值以后运行事先给future添加的回调。
# 回调是通过未来对象的add_done_callback()方法添加的。
class Future:
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.result = None
        self._callbacks = list()

    def add_done_callback(self, fn):
        self._callbacks.append(fn)

    def set_result(self, result):
        self.result = result
        for fn in self._callbacks:
            fn(self)


class Crawler:
    def __init__(self, url, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.url = url
        self.response = b''

    def fetch(self):
        sock = socket.socket()
        sock.setblocking(False)
        try:
            sock.connect(("example.com", 80))
        except BlockingIOError:
            pass

        f = Future()

        def on_connected():
            f.set_result(None)

        selector.register(sock.fileno(), selectors.EVENT_WRITE, on_connected)
        yield f
        selector.unregister(sock.fileno())
        get = "GET {0} HTTP / 1.0\r\n\r\n".format(self.url)
        sock.send(get.encode("ascii"))

        global stopped
        while True:
            f = Future()

            def on_readable():
                f.set_result(sock.recv(4096))

            selector.register(sock.fileno(), selectors.EVENT_READ, on_readable)
            chunk = yield f
            selector.unregister(sock.fileno())
            if chunk:
                self.response += chunk
            else:
                urls_todo.remove(self.url)
                if not urls_todo:
                    stopped = True
                break


# 用于恢复生成器的执行, 管理生成器的状态
# 上述代码中Task封装了coro对象，即初始化时传递给他的对象，被管理的任务是待执行的协程，故而这里的coro就是fetch()生成器。
# 它还有个step()方法，在初始化的时候就会执行一遍。
# step()内会调用生成器的send()方法，初始化第一次发送的是None就驱动了coro即fetch()的第一次执行。

# send()完成之后，得到下一次的future，然后给下一次的future添加step()回调。
# 原来add_done_callback()不是给写爬虫业务逻辑用的。此前的callback可就干的是业务逻辑呀。

# 再看fetch()生成器，其内部写完了所有的业务逻辑，包括如何发送请求，如何读取响应。
# 而且注册给selector的回调相当简单，就是给对应的future对象绑定结果值。
# 两个yield表达式都是返回对应的future对象，然后返回Task.step()之内，这样Task, Future, Coroutine三者精妙地串联在了一起。

# 初始化Task对象以后，把fetch()给驱动到了第44行yied f就完事了
class Task:
    def __init__(self, coro, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.coro = coro
        f = Future()
        f.set_result(None)
        self.step(f)

    def step(self, future):
        try:
            # send会进入到coro执行, 即fetch, 知道下次yield
            # next_future为yield返回对象
            next_future = self.coro.send(future.result)
        except StopIteration:
            return 
        next_future.add_done_callback(self.step)


# 现在loop有了些许变化，callback()不再传递event_key和event_mask参数。
# 也就是说，这里的回调根本不关心是谁触发了这个事件，结合fetch()可以知道，它只需完成对future设置结果值即可f.set_result()。
# 而且future是谁它也不关心，因为协程能够保存自己的状态，知道自己的future是哪个。
# 也不用关心到底要设置什么值，因为要设置什么值也是协程内安排的
def loop():
    while not stopped:
        # 阻塞, 直到一个事件发生
        events = selector.select()
        for event_key, event_mask in events:
            callback = event_key.data
            callback()
            

if __name__ == "__main__":
    import time

    start = time.time()

    for url in urls_todo:
        crawler = Crawler(url)
        Task(crawler.fetch)
    loop()

    print(time.time()-start)
    