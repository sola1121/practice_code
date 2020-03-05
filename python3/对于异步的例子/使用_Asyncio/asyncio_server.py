import asyncio


class Shutdown(Exception):
    pass


class ServerProtocol(asyncio.Protocol):
    def connection_made(self, transport):
        self.transport = transport
        self.write("Welcome.")

    def data_received(self, data):
        """
        接收一个数据并尝试对该及数据进行处理, 其只接收两个命令, 
        任何为其他未定义命令都将出错.
        """
        if not data:
            return 

        message = data.decode("utf-8")
        command = message.strip().split(" ")[0].lower()
        args = message.strip().split(" ")[1:]

        if not hasattr(self, "command_%s" % command):
            self.write("Invalid command %s" % command)
            return

        try:
            return getattr(self, "command_%s" % command)
        except Exception as ex:
            self.write("Error: %s\n" % str(ex))

    def write(self, msg_string):
        """用于进行字节转换"""
        msg_string += "\n"
        self.transport.write(msg_string.encode("utf-8", "ignore"))

    def command_add(self, *args):
        args = [int(i) for i in args]
        self.write("%d" % sum(args))

    def command_shutdown(self):
        self.write("Okay. shuting down.")
        raise KeyboardInterrupt


if __name__ == "__main__":

    loop = asyncio.get_event_loop()
    coro = loop.create_server(ServerProtocol, "127.0.0.1", 8000)   # 启动服务器
    asyncio.async(coro)
    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass


# ServerProtocol类是asyncio.Protocol的子类. connection_made与data_recieve方法在基类中定义, 但不实现任何功能. 另外三方是自定义方法.