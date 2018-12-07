import time
import random
import threading


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
