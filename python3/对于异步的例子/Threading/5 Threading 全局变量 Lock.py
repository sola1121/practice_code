# coding: utf8

import threading

def job1():
    global A, lock
    lock.acquire()   # 上锁
    for i in range(10):
        A += 1
        print("job1: ", A)
    lock.release()   # 解锁

def job2():
    global A, lock
    lock.acquire()   # 上锁
    for i in range(10):
        A += 9
        print("job2: ", A)
    lock.release()   # 解锁


if __name__ == "__main__":
    A = 0   # 定义为全局变量

    lock = threading.Lock()   # 声明一个锁

    add_thread1 = threading.Thread(target=job1, name="T1")
    add_thread2 = threading.Thread(target=job2, name="T2")
    add_thread1.start()
    add_thread2.start()
    add_thread1.join()
    add_thread2.join()