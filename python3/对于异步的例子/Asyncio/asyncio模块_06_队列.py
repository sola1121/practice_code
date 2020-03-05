# 队列是一个由任务执行器处理的任务集合.
import asyncio
queue = asyncio.Queue()
queue.put_nowait("foo")
print(queue.qsize())
print(queue.get_nowait())
print(queue.qsize())

# 以上是一个非常典型的先进先出队列.
# 使用put_nowait和get_nowait方法. 这两个方法用于立刻从队列中添加或移除项.
# 当队列为空时, get_nowait方法会返回QueueEmpty的异常.
# 使用get方法, 获取对象, 队列为空将不会引发异常, 其将会等待(会阻塞)队列的添加并返回新添加的元素.
print("使用get方法获取队列.")
loop = asyncio.get_event_loop()
queue = asyncio.Queue()
queue.put_nowait("foo")
loop.run_until_complete(queue.get())   # 没有元素会引起阻塞

# 使用wait 中的timeout防止阻塞

loop = asyncio.get_event_loop()
queue = asyncio.Queue()
task = asyncio.async(queue.get())
coro = asyncio.wait([task], timeout=1)
loop.run_until_complete(coro)

# 因为队列中没有元素, 所以在等待一秒后, 事件结束, 可以使用回调继续执行
print("使用回调, 永远执行")
import functools
loop = asyncio.get_event_loop()
queue = asyncio.Queue()
task = asyncio.async(queue.get())
queue.put_nowait("bar")
def stop(loop, future):
    loop.stop()

task.add_done_callback(functools.partial(stop, loop))
loop.run_forever()

# 使用maxsize关键字参数可以设置queue对象的最大队列长度.