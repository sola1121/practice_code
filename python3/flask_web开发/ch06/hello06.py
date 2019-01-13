import os
import threading

from flask import Flask
from flask import render_template, session, request, redirect, url_for
# bootstrap
from flask_bootstrap import Bootstrap
# 表单
from flask_wtf import FlaskForm
from wtforms.fields import StringField, SubmitField
from wtforms.validators import DataRequired
# 数据库
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
# 邮件
from flask_mail import Mail, Message

BASE_DIR = os.path.abspath(os.path.dirname(__file__))

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = "sqlite:///" + os.path.join(BASE_DIR, "data.sqlite")
app.config["SQLALCHEMY_TRAK_MODIFICATIONS"] = False
app.config["SECRET_KEY"] = "配置用于csrf防御的秘钥"

# 配置邮箱服务器
app.config["MAIL_SERVER"] = "smtp.qq.com"
app.config["MAIL_PORT"] = 587
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.environ.get("mail_user")
app.config["MAIL_PASSWORD"] = os.environ.get("mail_pass")

# 自定义的一些配置
app.config["FLASKY_MAIL_SUBJECT_PREFIX"] = "[Flasky]"
app.config["FLASKY_MAIL_SENDER"] = "电子邮箱服务的邮箱地址"
app.config["FLASKY_ADMIN"] = os.environ.get("flasky_admin")

Bootstrap(app)
db = SQLAlchemy(app)
# 没有配置将会使用本地计算机作为邮件发送服务器
mail = Mail(app)
Migrate(app, db)


class User(db.Model):
    __tablename__ = "users"
    id = db.Column(db.Integer, primary_key = True)
    username = db.Column(db.String(64), unique=True)


class NameForm(FlaskForm):
    name = StringField("What is your name?", validators=[DataRequired()])
    submit = SubmitField("confirm")


def send_async_mail(app, msg):
    """单独打包发送方法, 用于异步发送, 减少因为网络延迟造成的阻塞"""
    with app.app_context():
        mail.send(msg)


def send_mail(to, subject, template, **kwargs):
    """构成邮件, 并调用发送"""
    msg = Message(app.config["FLASKY_MAIL_SUBJECT_PREFIX"] + subject,
                  sender=app.config["FLASKY_MAIL_SENDER"], recipients=to)
    msg.body = render_template(template + ".txt", **kwargs)
    msg.html = render_template(template + ".html", **kwargs)
    th = threading.Thread(target=send_async_mail, args=(app, msg))
    th.start()
    return th


def index():
    form_field = NameForm()
    if form_field.validate_on_submit():
        user = User.query.filter_by(username=form_field.name.data).first()
        if user is None:
            new_user = User(username=form_field.name.data)
            db.session.add(new_user)
            db.session.commit()
            session["known"] = False
            if app.config["FLASKY_ADMIN"]:   # 有在环境中配置FLASKY_ADMIN才会向管理员发送邮件
                send_mail(app.config["FLASKY_ADMIN"], "New User", "mail/new_user", 
                          new_user=new_user.username, host=request.host)
        else:
            session["known"] = True
        session["name"] = form_field.name.data
        form_field.name.data = ""
        return redirect(url_for("index"))
    return render_template("index.html", form_field=form_field, name=session.get("name"), 
                           known=session.get("known", False))


app.add_url_rule("/", endpoint="index", view_func=index)


if __name__ == "__main__":
    
    app.run(debug=True)
