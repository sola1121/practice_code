# app/main/__init__.py
# 主蓝本
# 因为在app/__init__.py中才会创建app, 若在之后才开始创建路由和错误处理页面就会太晚
# 使用蓝本来对路由和错误处理页面进行事先的处理

from flask import Blueprint

main = Blueprint("main", __name__)

from . import views, errors
