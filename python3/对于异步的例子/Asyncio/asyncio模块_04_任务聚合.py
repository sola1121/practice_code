# 任务聚合的原因
# 在一组任务中的任何任务完成后采取某些行动.
# 在所有任务都完成后采取某些行动.

# 通过asyncio.gather 函数, 其接收一系类协程或任务, 并返回将那些任务聚合的单个任务(包装其接收的任何使用协程)
import asyncio
loop = asyncio.get_event_loop()
@asyncio.coroutine
def make_tea(variety):
    print("Now making %s tea." % variety)
    return "%s tea" % variety

meta_task = asyncio.gather(
    make_tea("red"),
    make_tea("green"),
    make_tea("herbal")
)

print(meta_task.done())
loop.run_until_complete(meta_task)
print(meta_task.done())

# asyncio.gather 函数接收三个协程对象
# 在该函数内部将所有协程包装到一个任务中, 并返回一个从当三个协程聚合的单独任务.
# 返回的结果总会是一个列表, 该列表包含被聚集的单个任务的结果.
# 返回列表中任务的顺序保证与任务聚集的顺序一致(任务的执行不一定).


# 聚合任务的回调
loop = asyncio.get_event_loop()
@asyncio.coroutine
def make_tea(variety):
    print("Now making %s tea." % variety)
    return "%s tea" % variety

def mix(future):   # 接收的是整个多个Futrue左后完成时的拼接
    print("Mixing the %s together." % " and ".join(future.result()))

meta_task = asyncio.gather(make_tea("herbal"), make_tea("green"))
meta_task.add_done_callback(mix)

loop.run_until_complete(meta_task)

# 当调用run_until_complete时首先会执行两个被聚集到meta_task中的任务. 最后只有在这两个任务完成后, 才执行mix函数.
# 这是因为只有meta_task中的所有任务完成后, meta_task才算完成, 因此只有在这两个单独任务都完成后才会触发回调.
