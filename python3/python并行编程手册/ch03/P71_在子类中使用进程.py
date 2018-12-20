"""
定义一个新的Process的子类
重写__init__(self [,args])方法增加额外的参数
重写run(self [,args])方法实现Process启动后需要做的事情
"""

import multiprocessing

class OneProcess(multiprocessing.Process):
    def run(self):
        print("called run method in process: %s" % self.name)


if __name__ == "__main__":

    jobs = list()
    for _ in range(5):
        ps = OneProcess()
        jobs.append(ps)
        ps.start()
        ps.join()

