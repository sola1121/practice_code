"""
with用于处理两个相关成对操作.
在线程模块中, acquire()和release()方法所提供的全部对象可以用在with语句块中
Lock
RLock
condition
semaphore
"""

import logging
import threading

logging.basicConfig(
    level=logging.DEBUG,
    format="%(threadName)-10s %(message)s"                    
)

def threading_with(statement):
    with statement:
        logging.debug("%s acquired via with" %statement)

def threading_no_with(statement):
    statement.acquire()
    try:
        logging.debug("%s acquired directly" %statement)
    finally:
        statement.release()


if __name__ == "__main__":

    # 创建一个测试组合
    lock = threading.Lock()
    rlock = threading.RLock()
    condition = threading.Condition()
    mutex = threading.Semaphore(1)
    threading_synchronization_list = [lock, rlock, condition, mutex]

    # 在for循环中, 调用threading_with与threading_no_with函数
    for statement in threading_synchronization_list:
        th1 = threading.Thread(target=threading_with, args=(statement,))
        th2 = threading.Thread(target=threading_no_with, args=(statement,))

        th1.start()
        th2.start()

        th1.join()
        th2.join()
