import os

from flask import Flask
from flask_mail import Mail, Message

app = Flask(__name__)
app.config["MAIL_SERVER"] = "smtp.qq.com"
app.config["MAIL_PORT"] = 587
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.environ.get("mail_user")
app.config["MAIL_PASSWORD"] = os.environ.get("mail_pass")

mail = Mail(app)

msg = Message("Mail From Flask(test)", sender="发送@qq.com", recipients=["收件@qq.com", "收件@qq.com"])
msg.body = """使用flask-mail插件来进行邮件发送
这是使用普通文.
"""
msg.html = """<h2>使用flask-mail插件来进行邮件发送</h2>
<p>这是用于html的文本.</p>
"""

with app.app_context():
    mail.send(msg)
