import time
import random
import threading
import queue


class Producer(threading.Thread):
    def __init__(self, queue):
        threading.Thread.__init__(self)
        self.queue = queue

    def run(self):
        for _ in range(10):   # 每秒将会向队列中添加一个元素
            item = random.randint(0, 256)
            self.queue.put(item)
            print("Producer notify: item %d appended to queue by %s\n" % (item, self.name))
            time.sleep(1)


class Consumer(threading.Thread):
    def __init__(self, queue):
        threading.Thread.__init__(self)
        self.queue = queue

    def run(self):
        while True:
            item = self.queue.get()

            # 停止线程
            if item == "stop":
                print("break %s" % self.name)
                break

            print("Consumer notify: %d poped from queue by %s" % (item, self.name))
            self.queue.task_done()


if __name__ == "__main__":

    que = queue.Queue()   # 都将使用的队列

    th1 = Producer(que)
    th2 = Consumer(que)
    th3 = Consumer(que)
    th4 = Consumer(que)

    th1.start()
    th2.start()
    th3.start()
    th4.start()

    # 用于停止线程
    que.join()
    for _ in range(3):
        que.put("stop")

    th1.join()
    th2.join()
    th3.join()
    th4.join()
    
