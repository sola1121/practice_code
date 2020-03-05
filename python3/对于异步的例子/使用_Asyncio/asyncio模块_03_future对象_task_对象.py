# 在遇到特殊问题时的一种应对机制是使用Future对象
# Future对象是用来通知异步函数状态的对象, 包含函数执行中, 已完成, 已取消
# Future是一个独立的对象, 并不依赖正在执行的函数. 该对象仅仅用于存储状态和结果信息, 此外别无它用.

# Task对象是Future对象的子类. 每当一个协程在时间循环中被安排执行后, 协程就会被Task对象包装.
# 将任务放入时间循环的主要方式, 使用asyncio.async, 之前介绍的run_until_complete也能将任务放入事件循环(但这不是主要的)

import asyncio

@asyncio.coroutine
def make_tea(variety):
    print("Now making %s tea." % variety)
    asyncio.get_event_loop().stop()   # 解决了开始循环后(使用run_forever)不会停
    return "%s tea" % variety

task = asyncio.async(make_tea("red"))   # 使用asyncio.async创建一个Task对象

# 可以通过done和result方法查看task对象的状态

# print(task.done())
# print(task.result())

# 开始循环, 使用run_forever不会一直陷入循环中
loop = asyncio.get_event_loop()
loop.run_forever()


# 使用Future对象(包括Task)完成回调
# 回调是一个Future完成后执行的一个函数(或协程), 该函数接受Futrue作为参数
# 在某种程度上, 回调代表了和yield from模型相反的模型.
# 当一个协程使用yield from时, 该协程会确保嵌套协程在其之前或被同时执行.
# 当注册一个回调时, 顺序相反. 回调被附加到原始的任务, 他在任务执行之后再执行回调.

# 使用对象的add_done_callback方法将一个回调添加到任何Future对象.
# 回调接收一个参数, 即为Future对象本身(该对象包含状态和结果信息, 如果存在底层任务, 则为底层任务的状态或结果)
# 不能将一个协程作为回调发送

loop = asyncio.get_event_loop()

@asyncio.coroutine
def make_tea(variety):
    print("Now making %s tea." % variety)
    return "%s tea" % variety

def confirm_tea(future):
    print("The %s is made." % future.result())

task = asyncio.async(make_tea("green"))
task.add_done_callback(confirm_tea)   # 将confirm_tea方法作为回调赋值给task
loop.run_until_complete(task)

# 如果future.result()的结果没有被正确返回, Task将会引发异常, 可能会使用Future.cancel()取消任务. 标记为Cancelled
# 在内部, 由asyncio通知Future对象已经完成. Futrue对象接受接下来对所有已注册到Futrue的回调, 并对其调用call_soon_threadsalfe函数
# 对于回来说, 并不能保证执行的顺序.


# 回调系统的一个限制是回调接收作为位置参数的Futrue对象, 当不能接收其他参数.
# 可以通过使用functools.partial函数将其他参数发送给回调. 但如果这样做, 回调必须任然接受作为位置参数的Futrue.
# 在回调被调用之前, Future会俯角到位置参数列表的结尾处.

import functools

loop = asyncio.get_event_loop()
@asyncio.coroutine
def make_tea(variety):
    print("Now making %s tea." % variety)
    return "%s tea" % variety

def add_ingredient(ingredient, future):
    print("Now adding %s to the %s." % (ingredient, future.result()))

task = asyncio.async(make_tea("herbal"))
task.add_done_callback(functools.partial(add_ingredient, "honey"))   # 使用functools.partial传入参数

loop.run_until_complete(task)

