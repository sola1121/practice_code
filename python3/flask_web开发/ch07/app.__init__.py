# app/__init__.py
# 作为工厂函数, 延迟创建应用实例, 可以给脚本留出配置应用的时间, 还能够创建多个应用实例.

from flask import Flask
from flask import render_template
from flask_bootstrap import Bootstrap
from flask_mail import Mail
from flask_moment import Moment
from flask_sqlalchemy import SQLAlchemy
from config import CONFIG

bootstrap = Bootstrap()
mail = Mail()
moment = Moment()
db = SQLAlchemy()


def create_app(config_name):
    app = Flask(__name__)
    app.config.from_object(CONFIG[config_name])   # from_object方法直接从对象中导入响应的配置
    CONFIG[config_name].init_app(app)

    bootstrap.init_app(app)
    mail.init_app(app)
    moment.init_app(app)
    db.init_app(app)
    
    # 添加路由和自定义错误页面
    # 对app/main/__init__.py中蓝本的使用
    from .main import main 按时 main_blueprint
    app.register_blueprint(main_blueprint)

    return app