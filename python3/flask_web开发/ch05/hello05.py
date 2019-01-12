import os
from flask import Flask
from flask import session, redirect, url_for, render_template
# 使用boostrap
from flask_bootstrap import Bootstrap
# 使用wtform
from flask_wtf import FlaskForm
import wtforms
# 使用sqlalchemy
from flask_sqlalchemy import SQLAlchemy
# 使用alembic
from flask_migrate import Migrate


basedir = os.path.abspath(os.path.dirname(__file__))

app = Flask(__name__)
app.config["SECRET_KEY"] = "配置表单使用的秘钥, 用于csrf"
# 数据库配置, 这里使用的sqllite, 因没有服务, 就配置文件地址, 使用bind还可以绑定多个数据库
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///" + os.path.join(basedir, "data.sqlite")   
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False

Bootstrap(app)
db = SQLAlchemy(app)   # 获取app中的数据库配置, 并生成数据库映射对象, 然后返回
migrate = Migrate(app, db)   # 实现数据库迁移功能

# 定义模型
class Role(db.Model):
    __tablename__ = "roles"
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(64), unique=True)
    users = db.relationship("User", backref="role", lazy="dynamic")   # 主键

    def __repr__(self):
        return "<Role %r>" % self.name


class User(db.Model):
    __tablename__ = "users"
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(64), unique=True, index=True)
    role_id = db.Column(db.Integer, db.ForeignKey("roles.id"))   # 外键

    def __repr__(self):
        return "<User %r>" % self.username


@app.shell_context_processor
def make_context():
    """使用flask shell时将会自动导入"""
    return dict(db=db, User=User, Role=Role)


# 定义表单
class NameForm(FlaskForm):
    name = wtforms.fields.StringField("what is your name?", validators=[wtforms.validators.required(),])
    submit = wtforms.fields.SubmitField("confirm")


# 定义视图
@app.route("/", endpoint="index", methods=("GET", "POST"))
def index():
    form_field = NameForm()
    if form_field.validate_on_submit():
        user = User.query.filter_by(username=form_field.name.data).first()   # 获取数据库中满足查询的一条数据
        if user is None:
            # 没有在数据库中查到相应的名字, 就将新的添加到数据库
            # new_user = User(username=form_field.name.data, role_id=2)
            new_user = User(username=form_field.name.data)
            db.session.add(new_user)
            db.session.commit()
            # 设置会话中的值指示
            session["known"] = False
        else:
            session["known"] = True
        # 处理POST, 将会把名字放入会话中, 然后清空表单, 最后重定向
        session["name"] = form_field.name.data
        form_field.name.data = ""
        return redirect(url_for("index"))
    # 返回网页
    return render_template("index.html", 
            form_field=form_field, name=session.get("name"), known=session.get("known", False))


if __name__ == "__main__":

    app.run(debug=True)
