import socket
import selectors


stopped = False
selector = selectors.DefaultSelector()
urls_todo = set(['/', "/1", "/2", "/3", "/4", "/5", "/6", "/7", "/8", "/9"])


class Future:
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.result = None
        self._callbacks = list()

    def add_done_callback(self, fn):
        self._callbacks.append(fn)

    def set_result(self, result):
        self.result = result
        for fn in self._callbacks:
            fn(self)


def connect(sock, address):
    f = Future()
    sock.setblocking(False)
    try:
        sock.connect(address)
    except BlockingIOError:
        pass

    def on_connected():
        f.set_result(None)

    selector.register(sock.filno(), selectors.EVENT_WRITE, on_connected)
    yield from f
    selector.unregister(sock.fileno())


# 单次recv和读取完整的response功能

def read(sock):
    f = Future()

    def on_readable():
        f.set_result(sock.recv(4096))

    selector.register(sock.fileno(), selectors.EVENT_READ, on_readable)
    chunk = yield from f
    selector.unregister(sock.fileno())
    return chunk


def readall(sock):
    response = list()
    chunk = yield from read(sock)
    while chunk:
        response.append(chunk)
        chunk = yield from read(sock)
    return b''.join(response)


class Crawler:
    def __init__(self, url, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.url = url
        self.response = b''

    def fetch(self):
        global stopped
        sock = socket.socket()
        yield from connect(sock, ("example.com", 80))
        get = "GET {0} HTTP\r\nHost: example.com\r\n\r\n".format(slef.url)
        sock.send(get.encode("ascii"))
        self.response = yield from readall(sock)
        urls_todo.remove(self.url)
        if not urls_todo:
            stopped

