# coding: utf-8

import multiprocessing

def job(q):
    res = 0
    for i in range(1000):
        res += i + i**2 + i**3
    q.put(res)   # queue 队列, 添加终值到队列中, 使用process是没法使用return的

if __name__ == "__main__":
    que = multiprocessing.Queue()

    mp1 = multiprocessing.Process(target=job, args=(que,))
    mp2 = multiprocessing.Process(target=job, args=(que,))

    mp1.start()
    mp2.start()

    mp1.join()
    mp2.join()

    res1 = que.get()
    res2 = que.get()

    print(res1+res2)