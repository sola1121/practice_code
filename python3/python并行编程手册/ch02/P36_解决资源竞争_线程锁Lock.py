import threading

shared_resource_with_lock = 0
shared_resource_with_no_lock = 0

COUNT = 100000
shared_resource_lock = threading.Lock()   # 锁对象

### 锁管理 ###
def increament_with_lock():
    global shared_resource_with_lock
    for _ in range(COUNT):
        shared_resource_lock.acquire()   # 上锁
        shared_resource_with_lock += 1
        shared_resource_lock.release()   # 解锁

def decrement_with_lock():
    global shared_resource_with_lock
    for _ in range(COUNT):
        shared_resource_lock.acquire()   # 上锁
        shared_resource_with_lock -= 1
        shared_resource_lock.release()   # 解锁

### 无锁管理 ###
def increment_without_lock():
    global shared_resource_with_no_lock
    for _ in range(COUNT):
        shared_resource_with_no_lock += 1

def decrement_without_lock():
    global shared_resource_with_no_lock
    for _ in range(COUNT):
        shared_resource_with_no_lock -= 1


if __name__ == "__main__":
    
    th_with_lock1 = threading.Thread(target=increament_with_lock)
    th_with_lock2 = threading.Thread(target=decrement_with_lock)

    th_no_lock1 = threading.Thread(target=increment_without_lock)
    th_no_lock2 = threading.Thread(target=decrement_without_lock)

    th_with_lock1.start()
    th_with_lock2.start()
    th_no_lock1.start()
    th_no_lock2.start()

    th_with_lock1.join()
    th_with_lock2.join()
    th_no_lock1.join()
    th_no_lock2.join()

    print("具有锁的shared_resouce_with_lock: ", shared_resource_with_lock)
    print("没有加锁的shared_resource_with_no_lock: ", shared_resource_with_no_lock)

# 如果状态为未上锁, 调用acquire()会将状态改为上锁
# 如果状态为上锁, 调用acquire()会阻塞, 直到自己或其他线程调用release()为止
# 如果状态为未上锁, 调用release()会导致RuntimeError异常
# 如果状态为上锁, 调用release()会将状态改为未上锁