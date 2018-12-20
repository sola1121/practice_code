import time
import multiprocessing

"""
后台运行就是主进程结束时结束, 而一般的都是自身运行完毕结束
"""

def fun():
    name = multiprocessing.current_process().name
    print("Starting %s \n" % name)
    time.sleep(3)
    print("Exiting %s \n" % name)


if __name__ == "__main__":

    background_process = multiprocessing.Process(target=fun, name="background_process")
    background_process.daemon = True   # 实现进程的后台运行
    
    no_background_process = multiprocessing.Process(target=fun, name="no_background_process")
    no_background_process.daemon = False   # 未实现进程的后台运行

    background_process.start()
    no_background_process.start()