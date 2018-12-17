import time
import multiprocessing


def foo():
    name = multiprocessing.current_process().name  # 使用current_process得到当前方法所在的进程
    print("Starting %s \n" %name)
    time.sleep(1.5)
    print("Exiting %s \n" %name)


if __name__ == "__main__":

    process_with_name = multiprocessing.Process(target=foo, name="foo_process")   # deamon=Ture 也可写在这参数里面
    process_with_name.deamon = True
    
    process_with_default_name = multiprocessing.Process(target=foo)

    process_with_name.start()
    process_with_default_name.start()
