import socket


def blocking_way():
    """请求指定网址的socket"""
    sock = socket.socket()
    # blocking
    sock.connect(("baidu.com", 80))
    request = "GET / HTTP/1.0\r\nHost: baidu.com\r\n\r\n"
    sock.send(request.encode("ascii"))   # Send只是将数据发送到请求队列中, 并不会造成阻塞
    response = b''
    chunk = sock.recv(4096)
    while chunk:
        response += chunk
        # blocking
    return response


def aync_way():
    res = list()
    for _ in range(10):
        res.append(blocking_way())
    return len(res)


aync_way()
