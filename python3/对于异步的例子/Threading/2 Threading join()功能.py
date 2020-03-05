# coding: utf8

import threading
import time

def thread_job():
    print("T1 start.")
    for i in range(10):
        time.sleep(0.1)
    print("Thread Finish.")

if __name__ == "__main__":
    add_thread = threading.Thread(target=thread_job, name="T1")
    add_thread.start()
    add_thread.join()   # 等待线程运行完成才会在执行主线程
    print("All Done.")
