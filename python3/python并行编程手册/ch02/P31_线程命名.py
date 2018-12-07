import time
import threading


def first_function():
    print(threading.current_thread().getName() + " is starting.\n")
    time.sleep(2)
    print(threading.current_thread().getName() + " is Exiting.\n")
    return 


def second_function():
    print(threading.current_thread().getName() + " is starting.\n")
    time.sleep(2)
    print(threading.current_thread().getName() + " is Exiting.\n")
    return 


def third_function():
    print(threading.current_thread().getName() + " is starting.\n")
    time.sleep(2)
    print(threading.current_thread().getName() + " is Exiting.\n")
    return 


if __name__ == "__main__":

    th1 = threading.Thread(target=first_function, name="first_function")
    th2 = threading.Thread(target=second_function, name="second_function")
    th3 = threading.Thread(target=third_function, name="third_function")

    th1.start()
    th2.start()
    th3.start()

    th1.join()
    th2.join()
    th3.join()
