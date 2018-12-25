"""
管理器对象会控制一个服务端进程, 该进程持有python对象, 并可以让其他进程操作这些对象, 
当有人修改这些对象时, 管理器会确保没有其他的进程在使用这些对象.
"""

import multiprocessing

def worker(dictionary, key, item):
    dictionary[key] = item

if __name__ == "__main__":

    mgr = multiprocessing.Manager()
    dictionary = mgr.dict()   # manage中有管理者的数据结构对象
    # 一个Process列表
    jobs = [multiprocessing.Process(target=worker, args=(dictionary, i, i*2)) for i in range(10)]
    for j in jobs:
        j.start()
    for j in jobs:
        j.join()
    print("Result:", dictionary)
