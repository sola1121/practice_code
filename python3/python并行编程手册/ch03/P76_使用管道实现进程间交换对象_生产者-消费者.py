"""
Pipe 封装的 multiprocessing.connection.Condition 对象
"""

import multiprocessing

def create_items(pipe):
    """向pipe中生成最初的数据"""
    conn1, _ = pipe
    for item in range(10):
        conn1.send(item)   # 向通道链接conn1中发送对象, int {1 2 3 4 5 6 7 8 9}
    conn1.close()   # 发完了就关闭通道了连接了


def multiply_items(pipe1, pipe2):
    """取得pipe1中的数据, 处理后输入pipe2中"""
    pipe1_conn1, pipe1_conn2 = pipe1
    pipe1_conn1.close()  # 关闭pipe1的conn1
    pipe2_conn1, _ = pipe2
    try:
        while True:
            item = pipe1_conn2.recv()   # 使用pipe1的conn2接收
            pipe2_conn1.send(item**2)   # 向pipe2中的conn1中发送数据
    except EOFError:
        pipe2_conn1.close()   # 遇结尾关闭管道中的连接


if __name__ == "__main__":

    # 拥有数字0~9的第一个进程管道
    pipe_1 = multiprocessing.Pipe(True)
    process_pipe_1 = multiprocessing.Process(target=create_items, args=(pipe_1,))   # 用于在pipe_1中生成最开始的数据, 使用conn1
    process_pipe_1.start()

    # 第二个管道
    pipe_2 = multiprocessing.Pipe(True)
    process_pipe_2 = multiprocessing.Process(target=multiply_items, args=(pipe_1, pipe_2))   # 从pipe_1中获得数据, 处理后使用pipe_2 conn1输出
    process_pipe_2.start()

    pipe_1[0].close()
    pipe_2[0].close()

    try:
        while True:
            print(pipe_2[1].recv())   # 主进程获取管道中的数据
    except EOFError:
        print("end")
    