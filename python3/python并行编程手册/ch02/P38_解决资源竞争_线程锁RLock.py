import time
import threading


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
        self.execute(1)
        Box.lock.release()

    def remove(self):
        Box.lock.acquire()
        self.execute(-1)
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