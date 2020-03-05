# 在asyncio中使用的大多数函数都是协程
# 协程是一种被设计用于在时间循环中执行的特殊函数
# 可以通过@asyncio.coroutine 将一个函数装饰为协程
import asyncio
@asyncio.coroutine
def coro_sum(*args):
    answer = 0
    for i in args:
        answer += i
    print(answer)

loop = asyncio.get_event_loop()
loop.run_until_complete(coro_sum(1,2,3,4,5))

# 协程实际上是一个由事件循环消费的特殊生成器
# 底层实现如下
try:
    next(coro_sum(1,2,3,4,5))
except StopIteration as ex:
    ex.value


# 协程提供了一种以模仿顺序编程的方式来调用其他协程的机制, 即Future实例
# 通过使用yield from 语句, 一个协程可以执行另外一个协程, 并由语句返回结果. 这是一种以顺序方式编写异步代码的可用机制.

@asyncio.coroutine
def nested(*args):
    print("The `nested` function ran with args: %r" % (args,))
    return [i + 1 for i in args]

@asyncio.coroutine
def outer(*args):
    print("The `outer` function ran with args: %r" % (args,))
    answer = yield from nested(*[i*2 for i in args])
    print(answer)

loop = asyncio.get_event_loop()
loop.run_until_complete(outer(2,4,6,8))
# 名为outer的协程在遇到yield from 语句时挂起, 名为nested的鞋蹭被放入事件循环并执行. 
# outer协程在nested完成并返回结果之前并不会继续执行.
# 因为nested是一个协程, 不能直接调用, 又因为协程是一个特殊的生成器, 所以使用yield from