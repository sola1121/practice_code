""" 基于事件循环+回调
创建Crawler 实例；
调用fetch方法，会创建socket连接和在selector上注册可写事件；
fetch内并无阻塞操作，该方法立即返回；
重复上述3个步骤，将10个不同的下载任务都加入事件循环；
启动事件循环，进入第1轮循环，阻塞在事件监听上；
当某个下载任务EVENT_WRITE被触发，回调其connected方法，第一轮事件循环结束；
进入第2轮事件循环，当某个下载任务有事件触发，执行其回调函数；此时已经不能推测是哪个事件发生，因为有可能是上次connected里的EVENT_READ先被触发，也可能是其他某个任务的EVENT_WRITE被触发；（此时，原来在一个下载任务上会阻塞的那段时间被利用起来执行另一个下载任务了）
循环往复，直至所有下载任务被处理完成
退出事件循环，结束整个下载程序
"""

import socket
import selectors


stopped = False
selector = selectors.DefaultSelector()
urls_todo = set(['/', "/1", "/2", "/3", "/4", "/5", "/6", "/7", "/8", "/9"])


class Crawler:
    def __init__(self, url, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.url = url
        self.sock = None
        self.response = b''

    def fetch(self):
        """配置socket, 建立socket连接, 向selector注册可写文件流"""
        self.sock = socket.socket()
        self.sock.setblocking(False)
        try:
            self.sock.connect(("example.com", 80))
        except BlockingIOError:
            pass
        selector.register(self.sock.fileno(), selectors.EVENT_WRITE, self.connected)

    def connected(self, key, mask):
        """取消文件流的注册, 注册新的只读文件流到selector"""
        selector.unregister(key.fd)
        get = "GET {0} HTTP/1.0\r\n\r\nHost: example.com\r\n\r\n".format(self.url)
        self.sock.send(get.encode("ascii"))
        selector.register(key.fd, selectors.EVENT_READ, self.read_response)

    def read_response(self, key, mask):
        """接收包, 取消文件流的注册, 移除urls_todo中对应的url"""
        global stopped
        # 如果响应大于4kB, 下一次循环会继续
        chunk = self.sock.recv(4096)
        if chunk:
            self.response += chunk
        else:
            selector.unregister(key.fd)
            urls_todo.remove(self.url)
            if not urls_todo:
                stopped = True

# 把I/O事件的等待和监听任务交给了 OS，那 OS 在知道I/O状态发生改变后（例如socket连接已建立成功可发送数据），
# 它又怎么知道接下来该干嘛呢？只能回调。

def loop():
    """开始使用select()阻塞等待发生"""
    while not stopped:
        # 阻塞, 直到一个事件发生
        events = selector.select()
        for event_key, event_mask in events:
            callback = event_key.data
            callback(event_key, event_mask)


if __name__ == "__main__":
    import time

    start = time.time()
    for url in urls_todo:
        crawler = Crawler(url)
        crawler.fetch()
    
    loop()
    print(time.time()-start)