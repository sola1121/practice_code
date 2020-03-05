# coding: utf8

"""在不同CPU核中的可以共同使用,相当于进程间的全局变量"""

import multiprocessing

share_value = multiprocessing.Value("d", 15.63)   # 参数d表示这是一个double变量

share_array = multiprocessing.Array("I", [1 ,2, 3, 4, 5])   # 参数I表示这是一个unsigned int变量集合(数组)

