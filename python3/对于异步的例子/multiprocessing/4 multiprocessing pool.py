# coding: utf-8

import multiprocessing

def job(x):
    return x**2   # 使用pool可以使用return返回

if __name__ == '__main__':
    # 基本的Pool使用
    pool = multiprocessing.Pool(processes=2)  # 默认是使用全部的进程,这里是指定使用两个

    res = pool.map(job, range(10))   # map(self, func, iterable, chunksize=None) 可以放入能迭代的参数
    print(res)

    # 非阻塞方式, 在一个进程中只能运行一个东西
    res = pool.apply_async(job, (4,))   # 参数只能有一个
    print(res.get())

    res = [pool.apply_async(job, (x,)) for x in range(10)]   # 使用列表的迭代完成对多个参数的使用,达到map的效果
    print([r.get() for r in res])