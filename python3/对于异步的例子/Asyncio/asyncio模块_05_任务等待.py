# asyncio.wait协程接受一系列协程或任务(在任务中包装任意协程), 一旦完成后就返回结果.
# 与gather接受位置参数以聚合不同, wait接受一个列表, wait接受一个用于在任何任务完成后返回的参数, 而无需等待任务完成.
# wait方法总是返回两个部分, 第一个元素已经完成的Futrue对象, 第二个元素还没有完成的部分.
import asyncio
loop = asyncio.get_event_loop()

@asyncio.coroutine
def make_tea(variety):
    print("Now making %s tea." % variety)
    return "%s tea" % variety

coro = asyncio.wait([make_tea("red"), make_tea("green")])

loop.run_until_complete(coro)

# 与gather方法不同, wait方法返回一个协程, 该协程带有值
# 无法将回调直接附加到wait返回的协程上, 如果需要这样做, 可以用asyncio.async创建任务
# 返回结果, gather函数将结果聚合到一个列表中并返回, 而wait的返回值是一个包含Future对象(其自身包含返回值)的两部分容器.
# wait将返回的Futrue对想重新组织, 一部分是已经完成的, 另一部分是还未完成的.


# 超时
# 将timeout关键字参数传递给asyncio.wait, 让协程在指定时间后返回结果, 无论任务是否完成
print("超时.....")
loop = asyncio.get_event_loop()
coro = asyncio.wait([asyncio.sleep(5), asyncio.sleep(1)], timeout=3)
loop.run_until_complete(coro)

# 如果指定协程提前完成, 那么就会提前返回结果.


# 等待任意任务
# asyncio.wait可以在其包含的任意Future对象完成后 即可返回协程.
# asyncio.wait函数可接受return_when关键字参数. 
# 通过给该关键字传递一个特殊变量(asyncio.FIRST_COMPLETED), 一旦任意任务完成后, 即可完成该协程, 不在需要等待所有任务都完成.
print("等待任意任务....完成后返回....")
loop = asyncio.get_event_loop()

coro = asyncio.wait(
    [asyncio.sleep(3), asyncio.sleep(2), asyncio.sleep(1)],
    return_when=asyncio.FIRST_COMPLETED
)
loop.run_until_complete(coro)

# 首先完成的协程使得wait协程完成. 因此返回两部分结果集, 其中第一部分结果集只包含一个项(已完成的任务), 第二个结果集包含两个项(任然挂起的任务)


# 等待异常
# 对于asyncio.wait的调用已经完成, 可以然任务引发异常, 而不是正常完成.
loop = asyncio.get_event_loop()

@asyncio.coroutine
def raise_ex_after(seconds):
    yield from asyncio.sleep(seconds)
    raise RuntimeError("Raising an exception.")

coro = asyncio.wait(
    [asyncio.sleep(1), raise_ex_after(2), asyncio.sleep(3)],
    return_when=asyncio.FIRST_EXCEPTION
)
loop.run_until_complete(coro)

# asyncio.wait协程在其中一个任务引发异常后立刻停止.
# 等待1s的sleep成功执行后, 其将在第一个返回集中, raise_ex_after成功执行, 也将在第一集合中, 3s的将会被异常终止, 挂起在第二个结果集中


# 所有任务都不引发异常(也是通常最常见的情况). 在这种情况下, 就和正常情况一样, 需要等待所有任务完成后wait才完成.
loop = asyncio.get_event_loop()

coro = asyncio.wait(
    [asyncio.sleep(1), asyncio.sleep(2)],
    return_when=asyncio.FIRST_EXCEPTION
)
loop.run_until_complete(coro)
