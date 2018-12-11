import time
import random
import threading


items = list()
event = threading.Event()

"""
将items对象和event对象作为参数传递给了生产者和消费者
这两个相当于全局的传递, 因为他们也是使用元数据的内存地址的, 及引用传递
在python中变量的传递都是引用传递, 当不可变变量发生改变时, 才会发生值传递
可变变量:   list,  dict, set,      bytearray
不可变变量: tuple,     , frozenset, bytes,   int, float, string
"""

class Consumer(threading.Thread):
    def __init__(self, items, event):
        threading.Thread.__init__(self)
        self.items = items
        self.event = event
    
    def run(self):
        for _ in range(11):
            time.sleep(2)   # 3. 睡眠等待生产
            self.event.wait()   # 1. 等待时间flag为True
            item = self.items.pop()   # 2. 删除生成的元素
            print("Consumer notify: %d popped from list by %s" % (item, self.name))
            # print("C items对象的地址: ", id(self.items), "event对象的地址: ", id(self.event))

    
class Producer(threading.Thread):
    def __init__(self, items, event):
        threading.Thread.__init__(self)
        self.items = items
        self.event = event

    def run(self):
        for _ in range(10):
            time.sleep(2)   # 4. 睡眠给消费时间
            item = random.randint(0, 256)
            self.items.append(item)   # 1. 生成元素
            print("Producer notify: item %d appended to list by %s" % (item, self.name))
            print("Producer notify: event set by %s" % self.name)
            self.event.set()   # 2. 将事件flag变为True
            print("Produce notify: event cleared by %s\n" % self.name)
            # print("P items对象的地址: ", id(self.items), "event对象的地址: ", id(self.event))
            self.event.clear()   # 3. 还原事件flag为False


if __name__ == "__main__":
    
    th1 = Producer(items, event)
    th2 = Consumer(items, event)

    th1.start()
    th2.start()

    th1.join()
    th2.join()

