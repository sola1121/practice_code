import time
import threading


exit_flag = 0


class OneThread(threading.Thread):
    def __init__(self, threadId, name, counter):
        threading.Thread.__init__(self)
        self.threadId = threadId
        self.name = name
        self.counter = counter

    def run(self):
        print("Starting " + self.name)
        print_time(self.name, self.counter, 5)
        print("Exiting " + self.name)


def print_time(threadName, delay, counter):
    while counter:
        if exit_flag:
            return
        time.sleep(delay)
        print("%s: %s" %(threadName, time.ctime(time.time())))
        counter -= 1


th1 = OneThread(1, "Thread-1", 1)
th2 = OneThread(2, "Thread-2", 2)

th1.start()
th2.start()

th1.join()
th2.join()
print("Exiting Main Thread.")
