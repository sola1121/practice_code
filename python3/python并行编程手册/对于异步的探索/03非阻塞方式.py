import socket


def nonblocking_way():
    sock = socket.socket()
    sock.setblocking(False)   # 告诉OS, 让socket上阻塞调用都改为非阻塞的方式, send, recv将不会阻塞
    try:
        sock.connect(("baidu.com", 80))
    except BlockingIOError:
        # 非阻塞连接过程中也会抛出异常
        pass
    request = "GET / HTTP1.0\r\nHost: baidu.com\r\n\r\n"
    data = request.encode("ascii")
    # 不知道socket何时就绪, 所以不断的尝试发送
    while True:
        try:
            sock.send(data)
            # 知道send不抛出异常, 则发送完成
            break
        except OSError:
            pass
    
    response = b''
    while True:
        try:
            chunk = sock.recv(4096)
            while chunk:
                response += chunk
                chunk = sock.recv(4096)
            break
        except OSError:
            pass
    return response


def sync_way():
    res = list()
    for _ in range(10):
        res.append(nonblocking_way())
    return len(res)


sync_way()