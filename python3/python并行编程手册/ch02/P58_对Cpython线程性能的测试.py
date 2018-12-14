import threading


# 1 线程对象
class ThreadsObject(threading.Thread):
    def run(self):
        function_to_run()


# 1 非线程对象
class NothreadObject:
    def run(self):
        function_to_run()


# 2 使用线程对象的方法
def threaded(num_threads):   # 根据输入的num_threads参数多次执行线程
    funcs = list()
    for _ in range(int(num_threads)):
        funcs.append(ThreadsObject())
    for fun in funcs:
        fun.start()
    for fun in funcs:
        fun.join()


# 2 使用非线程对象的方法
def non_threaded(num_iter):   # 根据输入的num_iter参数执行多次函数
    funcs = list()
    for _ in range(int(num_iter)):
        funcs.append(NothreadObject())
    for fun in funcs:
        fun.run()


# 测试段代码
def function_to_run():
    # 在这里写测试的代码片段
    pass


# 用于最后的格式化输出
def show_results(func_name, results):
    print("%-23s %4.6f seconds" % (func_name, results))


if __name__ == "__main__":

    import sys
    import timeit

    repeat = 100
    number = 1
    num_threads = [1, 2, 4, 8]

    print("Starting tests\n")

    for i in num_threads:
        # timeit.Timer(stmt='pass', setup='pass', timer=<timer function>, globals=None)
        # 接受以文本表示的代码段参数, 将其放入Timer中, 使用repeat设置重复执行次数, 最后用min找出用时最小的打印

        t = timeit.Timer("non_threaded(%s)" % i, "from __main__ import non_threaded")  # 执行代码片段 non_threaded(i)
        best_result = min(t.repeat(repeat=repeat, number=number))
        show_results("non_threaded(%s iters)" % i, best_result)

        t = timeit.Timer("threaded(%s)" % i, "from __main__ import threaded")   # 执行代码片段 threaded
        best_result = min(t.repeat(repeat=repeat, number=number))
        show_results("threaded (%s threads)" % i, best_result)

    print("\nIterations completed.")
