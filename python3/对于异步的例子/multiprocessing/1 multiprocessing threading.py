# coding: utf-8

"""对比线程方法和进程方法的相似性"""

import threading   # 线程
import multiprocessing    # 进程

def job(a, b, c):
    print("aaaaa", c)


if __name__ =="__main__":
    """线程和进程都必须放在main中才能正确执行"""

    t1 = threading.Thread(target=job, args=(1,2,"这里是线程Thread"))   # 调用一个函数是要加括号的,但是引用不加
    m1 = multiprocessing.Process(target=job, args=(1,2,"这里是进程Process"))

    t1.start()
    m1.start()

    t1.join()
    m1.join()



