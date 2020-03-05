# coding: utf8

import threading

# 查看自己电脑的线程
def check_thread():
    print(threading.active_count())   # 查看当前活动的线程数
    print(threading.enumerate())   # 列举活动的线程
    print(threading.current_thread())   # 查看当前的线程

def job():
    print("This is an added thread, No. %s." %threading.current_thread())

def add_thread():
    add_thread = threading.Thread(target=job)
    add_thread.start()
    add_thread.join()

if __name__ == '__main__':
    add_thread()
