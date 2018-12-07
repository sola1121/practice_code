import threading


def fun(i):
    print("function called by thread %i\n" %i)


ths = list()
for i in range(5):
    th = threading.Thread(target=fun, args=(i, ))
    ths.append(th)
    th.start()
    th.join()