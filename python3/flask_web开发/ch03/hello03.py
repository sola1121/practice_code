from flask import Flask
from flask import request
from flask import render_template


app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")


@app.route("/user/<name>")
def user(name):
    return render_template("user.html", name=name)
