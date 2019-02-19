from flask import Flask
from flask import request, make_response, jsonify

html = """\
<body>
    <button id="get_method">GET</button>
    <button id="post_method">POST</button>
    <button id="put_method">PUT</button>
    <button id="delete_method">DELETE</button>
    <div id="show"></div>
</body>
<script>
    show_board = document.getElementById("show")
    var buttons = document.getElementsByTagName("button")
    for (var i=0; i<buttons.length; i++){
        button = buttons[i]
        switch (button.getAttribute("id").split("_")[0].toLowerCase()){
            case "get":
                button.addEventListener("click", function(){do_request("GET")}, false)
                break
            case "post":
                button.addEventListener("click", function(){do_request("POST")}, false)
                break
            case "put":
                button.addEventListener("click", function(){do_request("PUT")}, false)
                break
            case "delete":
                button.addEventListener("click", function(){do_request("DELETE")}, false)
                break
        }
    }


    function do_request(method){
        var xhr = new XMLHttpRequest()
        // 监控状态, 当到达第四步, 并成功时
        xhr.onreadystatechange = function(){
            if (xhr.readyState == 4 && xhr.status == 200){
                var res_text = xhr.responseText
                var res_json = JSON.parse(res_text)
                show_board.innerHTML = res_text + " --> result :" + res_json["result"]
            }
        }
        // 进行请求, xhr.open(方法, 地址, 异步, user, password)
        switch (String(method).toUpperCase()){
            case "GET":
                xhr.open("GET", "/?req=get&des=发起get请求")
                xhr.send()
                break
            case "POST":
                xhr.open("POST", "/")
                /* 普通的POST传递数据 */
                // xhr.setRequestHeader("Content-type","application/x-www-form-urlencoded")
                // xhr.send("req=post&des=发起post请求")
                /* POST发送Json */
                xhr.setRequestHeader("Content-type","application/json;charset=utf-8")
                xhr.send(JSON.stringify({req:"post", des: "发起post请求"}))
                break
            case "PUT":
                xhr.open("PUT", "/?req=put&des=发起put请求")
                xhr.send()
                break
            case "DELETE":
                xhr.open("DELETE", "/?req=delete&des=发起delete请求")
                xhr.send()
                break
        }
    }

</script>
"""


app = Flask(__name__)


@app.route("/", methods=("GET", "POST", "PUT", "DELETE"))
def index():
    res = None
    is_first = request.cookies.get("is_first", 1)
    if int(is_first):
        res = make_response(html)
        res.set_cookie("is_first", "0", max_age=25)   # 过期时间25s
    else:
        # args用于处理url中字符串数据
        # form用于处理post请求传递的数据
        # get_json()用于接收发过来的Json格式数据
        req_text = request.args or request.form or request.get_json()
        print("\n发起了\n", req_text, end="\n\n")
        res_dict = dict(result=None)
        if request.method == "GET":
            res_dict["result"] = "GET用来查询"
        if request.method == "POST":
            res_dict["result"] = "POST用来增加"
        if request.method == "PUT":
            res_dict["result"] = "PUT用来修改"
        if request.method == "DELETE":
            res_dict["result"] = "DELETE用来删除"
        # 始终返回一个Json格式的数据
        res = make_response(jsonify(res_dict))
    return res


if __name__ == "__main__":

    app.run(debug=True)
