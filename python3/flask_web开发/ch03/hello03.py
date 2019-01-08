from flask import Flask
from flask import request
from flask import render_template

from flask_bootstrap import Bootstrap
from flask_moment import Moment

from datetime import datetime


app = Flask(__name__)
bootstrap = Bootstrap(app)   # 使用bootstrap, 这样网页中就可以使用bootstrap了
moment = Moment(app)   # 集成moment.js, 用于处理时间


@app.route("/")
def index():
    return render_template("index.html", current_time=datetime.utcnow())


@app.route("/user/<name>")
def user(name):
    return render_template("user.html", name=name)


@app.errorhandler(404)
def page_not_found(e):
    return render_template("404.html"), 404


@app.errorhandler(500)
def internal_server_error(e):
    return render_template("500.html"), 500
