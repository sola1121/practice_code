import time
import multiprocessing

"""
使用terminate()方法要注意, 如果当前进程在使用管道或队列, 那么退出可能会顺坏管道或队列, 造成其他进程无法使用
"""

def fun():
    print("Starting function")
    time.sleep(0.1)
    print("Finished function")


if __name__ == "__main__":

    ps = multiprocessing.Process(target=fun)
    print("Process before execution: ", ps, ps.is_alive())
    ps.start()
    print("Process running: ", ps, ps.is_alive())
    ps.terminate()
    print("Process terminated: ", ps, ps.is_alive())
    ps.join()
    print("Process joined: ", ps, ps.is_alive())
    print("Process exit code: ", ps.exitcode)