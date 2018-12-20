import time
import random
import multiprocessing

class Producer(multiprocessing.Process):
    def __init__(self, que):
        multiprocessing.Process.__init__(self)
        self.que = que

    def run(self):
        for _ in range(10):
            item = random.randint(0, 256)
            self.que.put(item)
            print("Process Producer: item %d appended to queue %s" %(item, self.name))
            time.sleep(1)
            print("The size of queue id %s" % self.que.qsize())


class Consumer(multiprocessing.Process):
    def __init__(self, que):
        multiprocessing.Process.__init__(self)
        self.que = que

    def run(self):
        while True:
            if self.que.empty() :
                print("the queue is empty.")
                break
            time.sleep(2)
            item = self.que.get()
            print("Process Consumer: item %d poped from by %s" % (item, self.name))
            time.sleep(1)


if __name__ == "__main__":

    que = multiprocessing.Queue()
    p_producer = Producer(que)
    p_consumer = Consumer(que)

    p_producer.start()
    p_consumer.start()

    p_producer.join()
    p_consumer.join()
                