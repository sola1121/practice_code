"""
Lock
    该对象可以处于上锁与未上锁状态. 锁对象有两个方法: acquire()与release(), 用于管理对共享资源的访问.
RLock
    定义了递归的Lock对象. RLock的方法和功能与threading模块中的一样.
Event
    他实现了进程间的简单通信, 一个进程会发出事件, 其他进程会等待事件. Event对象有两个方法: set()与clear(), 用于管理内部标记. 
Conditon
    该对象用于同步串行或是并行进程中的部分工作流. 他有两个基本方法, wait() 用于等待条件, 而notify_all()则用于与所应用的条件进行同行.
Semaphore
    用于共享公共资源, 比如, 支持固定数量的同时连接.
Barrier
    将一个程序划分为几个阶段, 因为他要求所有进程都达到后才能开始执行. 屏障后的代码不能与屏障前的代码并发执行
"""

import time
import datetime
import multiprocessing
from multiprocessing import Barrier, Lock, Process


def test_with_barrier(synchronizer, serializer):
    name = multiprocessing.current_process().name
    synchronizer.wait()   # 这里使用Barrier
    now = time.time()
    with serializer:   # 这里使用锁
        print("process %s ----> %s" %(name, datetime.datetime.fromtimestamp(now)))


def test_without_barrier():
    name = multiprocessing.current_process().name
    now = time.time()
    print("process %s ----> %s" %(name, datetime.datetime.fromtimestamp(now)))


if __name__ == "__main__":

    synchronizer = Barrier(2)  # 表示将要管理的进程数量
    serializer = Lock()

    Process(name="p1 - test_with_barrier", target=test_with_barrier, args=(synchronizer, serializer)).start()
    Process(name="p2 - test_with_barrier", target=test_with_barrier, args=(synchronizer, serializer)).start()
    Process(name="p3 - test_without_barrier", target=test_with_barrier).start()
    Process(name="p4 - test_without_barrier", target=test_with_barrier).start()
