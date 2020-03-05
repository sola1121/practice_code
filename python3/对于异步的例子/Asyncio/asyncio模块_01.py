import asyncio
import functools
import time

# 大多数异步应用程序实现异步的基本机制是通过在后台执行的事件循环
# 当有代码需要执行时, 这些代码才会被注册到事件循环中
# 将一个函数注册到事件循环会导致他变为一个任务

# 代码 --注册-> 后台的事件循环 --变为-> 任务 --交由-> 系统执行

# 获取一个事件循环对象
loop = asyncio.get_event_loop()   # 其将返回一个BaseEventLoop对象, 其是一个子类, 获得循环对象时, 其并不会执行
print(loop.is_running())   # 判断loop是否在运行, 返回False

# 使用BaseEventLoop.run_forever()执行运行, 但因为上事件并未注册任何有用程序, 将会是一个死循环
# 注册任务并执行
def hello_world():
    time.sleep(3)   # 异步执行, 将会和stop一起在循环中执行
    print("hello workd.")

def stop_loop(running_loop):
    running_loop.stop()
    print("stop loop")

# loop.call_soon(hello_world)
loop.call_later(10, hello_world)   # 延迟10s但是如果使用call_soon 的 stop_loop的话, 就不管执行多少秒了ヽ(￣▽￣)ﾉ
loop.call_soon(functools.partial(stop_loop, loop))
loop.run_forever()

# call_soon 表示方法是注册后执行时立即执行
# 可以使用 call_later 表示注册后延迟一段时间执行

# functools.partial方法接受参数和关键字参数, 这些参数在底层函数被调用时传递给底层函数
# 传入的参数被封装到partial对象中, 这样便可以完成需要参数的函数的调用

# hello_world函数与 functools.partial(print, "hello world.") 等价


# 在任务结束前执行循环
loop = asyncio.get_event_loop()
@asyncio.coroutine
def trivial():
    print("hello world.")
    time.sleep(3)

loop.run_until_complete(trivial())   # 这样会暂停三秒结束, 不加括号An asyncio.Future, a coroutine or an awaitable is required

# @asyncio.coroutine 通过将普通的函数转换为一个协程
# run_until_complete 会将任务注册并在任务结束前执行循环

# 在线程中, 即程序后台中执行后台循环, 使用线程 threading
import threading

def run_loop_forever_in_background(loop):
    def thread_func(fun):
        asyncio.set_event_loop(fun) 
        fun.run_forever()
    th = threading.Thread(target=thread_func, args=(loop,))
    th.start()
    return th

loop = asyncio.get_event_loop()
run_loop_forever_in_background(loop)
print("loop in thread is running: ", loop.is_running())

# 这样将stop_loop将会在线程中失效, 从而无法停止事件循环
# 可以使用loop.call_soon_threadsafe(functools.partial(print, "hello world.")) 来保证线程安全
# call_soon_threadsafe函数返回一个Handle对象, 该对象只有一个方法cancel, 在合适时, 会取消任务