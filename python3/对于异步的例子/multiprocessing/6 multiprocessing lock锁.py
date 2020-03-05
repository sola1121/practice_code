# coding: utf8

"""锁Lock 用于避免进程间对shared memory的争夺"""

import multiprocessing
import time

def job(val, num, lo):
    lo.acquire()   # 取得锁
    for _ in range(10):
        time.sleep(0.1)
        val.value += num
        print(val.value)
    lo.release()   # 释放锁

def multicore():
    lo = multiprocessing.Lock()   # 创建锁对象

    share_memory = multiprocessing.Value("i", 0)   # 初始化为0的一个共享int块变量

    res1 = multiprocessing.Process(target=job, args=(share_memory, 1, lo))
    res2 = multiprocessing.Process(target=job, args=(share_memory, 9, lo))
    res1.start()
    res2.start()
    res1.join()
    res2.join()

if __name__ == "__main__":
    multicore()
