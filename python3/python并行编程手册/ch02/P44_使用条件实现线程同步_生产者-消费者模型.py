import time
import threading


items = list()
condition = threading.Condition()

class Consumer(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def consume(self):
        global condition
        global items
        condition.acquire()   # 需要共享资源, 接下来会上锁
        if len(items) == 0:
            condition.wait()
            print("Consumer notify: no item to consume")
        items.pop()
        print("Consumer notify: consume 1 item")
        print("Consumer notify: items to consume are " + str(len(items)))
        condition.notify()
        condition.release()

    def run(self):
        for _ in range(20):
            time.sleep(5)
            self.consume()


class Producer(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)
    
    def produce(self):
        global condition
        global items
        condition.acquire()   # 需要共享资源, 接下来会上锁
        if len(items)  == 10:
            condition.wait()
            print("Producer notify: items produced are " + str(len(items)))
            print("Producer notify: stop the condition!!")
        items.append(1)
        print("Producer notify: total items producerd " + str(len(items)))
        condition.notify()
        condition.release()
    
    def run(self):
        for _ in range(20):
            time.sleep(2.5)
            self.produce()


if __name__ == "__main__":

    producer = Producer()
    consumer = Consumer()

    producer.start()
    consumer.start()

    producer.join()
    consumer.join()
