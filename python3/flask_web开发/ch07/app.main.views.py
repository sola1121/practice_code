# app/main/views.py

from datetime import datetime
from flask import render_template, session, redirect, url_for
from . import main
from .forms import NameForm
from .. import db
from ..models import User

@main.route("/", method=("GET", "POST"))
def index():
    # 路由函数
    # url_for("main.index") 要指明名称空间, 也可以写成 .index
    pass