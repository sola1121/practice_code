import time
import threading


class OneThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)   # super().__init__(self)
        self.message = "Hello Parallel Python CookBook.\n"

    def print_message(self):
        print(self.message)

    def run(self):
        print("Thread Starting\n")
        x = 0
        while x < 10:
            self.print_message()
            time.sleep(2)
            x += 1
        print("Thread Ended.")


print("Process Started")
one_th = OneThread()
one_th.start()
# one_th.join()  是否让进程等待线程执行完毕
print("Process Ended")
