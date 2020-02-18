# 使用全局变量查看递归调用次数

num_fib_calls = int()


def fib(n):
    """返回第n项的斐波那契数列值"""
    global num_fib_calls
    num_fib_calls += 1
    if n == 0 or n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)


def test_fib(n):
    for i in range(n+1):
        global num_fib_calls
        num_fib_calls = 0
        print("fib of", i, "=", fib(i))
        print("fib called", num_fib_calls, "times")


if __name__ == "__main__":
    
    test_fib(4)
