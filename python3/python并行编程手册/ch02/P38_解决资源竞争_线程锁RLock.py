import time
import threading

"""
RLock 又叫做递归锁, 其同一锁可以多次acquire, 但是就如同递归一样, 上了多少层, 就得下多少层回来, 所以也要对等数量的release
"""

class Box:
    lock = threading.RLock()
    def __init__(self):
        self.total_items = 0
    
    def execute(self, n):
        Box.lock.acquire()
        self.total_items += n
        Box.lock.release()

    def add(self):
        Box.lock.acquire()
        self.execute(1)   # 也有Box.lock.acquire
        Box.lock.release()

    def remove(self):
        Box.lock.acquire()
        self.execute(-1)   # 也有Box.lock.acquire
        Box.lock.release()


## 这两个函数在单独的线程中运行n次
## 并调用Box
def adder(box, items):
    while items > 0:
        print("adding 1 item in the box\n")
        box.add()
        time.sleep(5)
        items -= 1


def remover(box, itmes):
    while items > 0:
        print("removing 1 item in the box\n")
        box.remove()
        time.sleep(5)
        itmes -= 1


if __name__ == "__main__":

    items = 5
    print("putting %s items in the box" % items)
    box = Box()
    th1 = threading.Thread(target=adder, args=(box, items))
    th2 = threading.Thread(target=remover, args=(box, items))

    th1.start()
    th2.start()

    th1.join()
    th2.join()

    print("%s items still remain in the box "%box.total_items)

    # RLock允许在同一线程中被多次acquire
    # 每个add 和 remove中都包含Rlock的acquire, 而其调用的execute也包含Rlock的acquire,
    # 就像递归一样, 如果使用普通的Lock, 这将会引发异常.

    # 只想让获取锁的线程来释放锁, 就需要使用RLock
    # 如果希望在类外面能实现线程安全的访问, 同时又使用类里面的方法, RLock就很有用
    # 因为不用担心acquire冲突, 每个方法中都可以包含acquire