#!/usr/bin/python3

# 临时的全局请求对象
from flask import request
# 用于创建一个响应对象
from flask import make_response
# 初始化, 创建一个Flask对象, 传入当前文件的信息
from flask import Flask
app = Flask(__name__)

# 配置路由, 路由时函数和url地址的映射查询表
# 也可使用 app.add_url_rule(URL, 端点名, 视图函数) 的方式
@app.route('/')
def index():
    # 使用请求对象
    user_agent = request.headers.get("User-Agent")
    print("++ {} ++".format(user_agent))
    return '<h1> Hello, world. </h1>'


def hello():
    count_hello = request.cookies.get("hello", 0)
    response = make_response("<h1> You have said {} times hello to me.</h1>".format(count_hello))
    response.set_cookie("hello", str(int(count_hello) + 1))
    return response

app.add_url_rule('/hello', "hello", hello)


# 动态路由, URL会变化, 视图函数接收变化的参数
@app.route('/user/<name>')
def user(name):
    return '<h1> Hello, {}. </h1>'.format(name), 200


if __name__ == "__main__":

    app.run()   # 调试模式 app.run(debug=True)
