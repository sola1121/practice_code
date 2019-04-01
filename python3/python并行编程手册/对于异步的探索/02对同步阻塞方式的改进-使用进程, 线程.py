import socket
from concurrent import futures


def blocking_way():
    """请求指定网址的socket"""
    sock = socket.socket()
    # blocking
    sock.connect(("baidu.com", 80))
    request = "GET / HTTP1.0\r\nHost: baidu.com\r\n\r\n"
    sock.send(request.encode("ascii"))
    response = b''
    chunk = sock.recv(4096)
    while chunk:
        response += chunk
        # blocking
        chunk = sock.recv(4096)
    return response
    

def process_way():
    """使用多进程"""
    workers = 10
    with futures.ProcessPoolExecutor(workers) as executor:
        futs = {executor.submit(blocking_way) for _ in range(10)}
    return len([fut.result() for fut in futs])


def thread_way():
    workers = 10
    with futures.ThreadPoolExecutor(workers) as executor:
        futs = {executor.submit(blocking_way) for _ in range(10)}
    return len([fut.result() for fut in futs])


print("使用进程")
process_way()

print("使用线程")
thread_way()
