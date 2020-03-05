# coding: utf-8

import threading
from queue import Queue

def thread_job(origin_data, que):
    for i in range(len(origin_data)):
        origin_data[i] = origin_data[i]**2
    que.put(origin_data)   # 线程里不能使用return, 使用队列代替, 将结果放入队列

if __name__ == "__main__":
    data = [[1, 2, 3], [4, 5, 5], [9, 7, 8], [6, 3, 9]]   # 将会分配给四个线程的数据

    que = Queue()   # 声明的队列对象

    threads = []   # 将会用来存放单个线程的列表,方便join

    for data_no in range(4):
        add_thread = threading.Thread(target=thread_job, args=(data[data_no], que))
        add_thread.start()
        threads.append(add_thread)

    for thread in threads:
        thread.join()

    results = []
    for _ in range(4):
        results.append(que.get())

    print(results, "\nFinished.")

