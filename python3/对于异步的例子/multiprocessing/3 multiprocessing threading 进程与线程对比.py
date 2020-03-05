# coding: utf-8

import multiprocessing
import threading
import time

limit = 999999

def job(q):
    res = 0
    for i in range(limit):
        res += i+i**2+i**3
    q.put(res)

def normal_run(q):
    """普通执行"""
    start_time = time.time()
    res = 0
    for _ in range(2):
        for i in range(limit):
            res += i+i**2+i**3
    end_time = time.time()
    print("Normal: ", res, " with ", end_time-start_time)

def multi_thread(que):
    """多线程"""
    start_time = time.time()
    res1 = threading.Thread(target=job, args=(que,))
    res2 = threading.Thread(target=job, args=(que,))
    res1.start()
    res2.start()
    res1.join()
    res2.join()
    q1 = que.get()
    q2 = que.get()
    end_time = time.time()
    print("multithread: ", q1+q2, " with ", end_time-start_time)

def multi_process(que):
    """多进程"""
    start_time = time.time()
    res1 = threading.Thread(target=job, args=(que,))
    res2 = threading.Thread(target=job, args=(que,))
    res1.start()
    res2.start()
    res1.join()
    res2.join()
    q1 = que.get()
    q2 = que.get()
    end_time = time.time()
    print("multiprocess: ", q1+q2, " with ", end_time - start_time)

if __name__ == "__main__":
    que = multiprocessing.Queue()

    normal_run(que)
    multi_thread(que)
    multi_process(que)


