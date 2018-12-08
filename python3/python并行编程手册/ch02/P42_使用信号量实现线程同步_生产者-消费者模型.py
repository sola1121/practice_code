import time
import random
import threading

"""
信号量（英语：Semaphore）又称为信号标，是一个同步对象，用于保持在0至指定最大值之间的一个计数值。
当线程完成一次对该semaphore对象的等待（wait）时，该计数值减一；
当线程完成一次对semaphore对象的释放（release）时，计数值加一。
当计数值为0，则线程等待该semaphore对象不再能成功直至该semaphore对象变成signaled状态。
semaphore对象的计数值大于0，为signaled状态；计数值等于0，为nonsignaled状态.

semaphore对象适用于控制一个仅支持有限个用户的共享资源，是一种不需要使用忙碌等待（busy waiting）的方法。
"""

semaphore = threading.Semaphore(value=0)   # 默认值为1, 赋值小于0会ValueError异常


def consumer():
    print("consumer is waiting.")
    semaphore.acquire()   # 获取信号量
    print("Consumer notify: consumered item number %s" %item)


def producer():
    global item
    time.sleep(10)
    item = random.randint(0, 1000)
    print("Producer notify: producer item number %s" %item)
    # 释放信号量, 将内部的counter值加1, 当其值等于0时, 另一个线程会在此等待它的值变为大于0, 并唤醒该线程.
    semaphore.release()


if __name__ == "__main__":

    for _ in range(5):
        th1 = threading.Thread(target=producer)
        th2 = threading.Thread(target=consumer)

        th1.start()
        th2.start()

        th1.join()
        th2.join()

    print("program terminated.")
