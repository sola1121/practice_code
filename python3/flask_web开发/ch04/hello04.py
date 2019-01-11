from flask import Flask
from flask import request, session, render_template, redirect, url_for, flash

# flask-bootstrap
from flask_bootstrap import Bootstrap

# flask-wtf
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField
from wtforms.validators import DataRequired


app = Flask(__name__)
Bootstrap(app)
app.config["SECRET_KEY"] = "使用flask-wtf配置的秘钥"


class NameForm(FlaskForm):
    name = StringField("What's your name?", validators=[DataRequired()])
    submit = SubmitField("Submit")


# index1和index2的实现是一样的, 只是将请求的方式明确的分开了
# index3是将请求保存到会话中, 以记住请求的数据
# index4添加了flash功能, 用于在页面上闪现是否session中存储的name被改变了

# @app.route("/", methods=["GET", "POST"])
def index1():
    form_field = NameForm()
    if request.method == "GET":
        print("使用了GET方法请求", request.query_string)
        return render_template("index.html", form_field=form_field)
    if request.method == "POST":
        print("使用了POST方法请求")
        if form_field.validate_on_submit():
            name = form_field.name.data
            form_field.name.data = ""
            return render_template("index.html", name=name, form_field=form_field)
        else:
            form_field.name.data = ""
            return redirect(url_for("index1"))


app.add_url_rule("/", "index1", index1, methods=["GET", "POST"])   # 将index注册为可以处理GET和POST请求


@app.route("/index2", endpoint="index2", methods=["GET", "POST"])
def index2():
    name = None
    form_field = NameForm()
    if form_field.validate_on_submit():
        name = form_field.name.data
        form_field.name.data = ""
    return render_template("index.html", name=name, form_field=form_field)


@app.route("/index3", endpoint="index3", methods=["GET", "POST"])
def index3():
    form_field = NameForm()
    if form_field.validate_on_submit():
        session["name"] = form_field.name.data
        return redirect(url_for("index3"))
    return render_template("index.html", form_field=form_field, name=session.get("name"))


@app.route("/index4", endpoint="index4", methods=("GET", "POST"))
def index4():
    form_field = NameForm()
    if form_field.validate_on_submit():
        old_name = session.get("name")
        if old_name is not None and old_name != form_field.name.data:
            flash("Looks like you have changed your name!")   # flash, 然后在模板中使用get_flashed_messages获取闪现消息
        session["name"] = form_field.name.data
        return redirect(url_for("index4"))
    return render_template("index.html", form_field=form_field, name=session.get("name"))


if __name__ == "__main__":

    app.run(debug=True)
