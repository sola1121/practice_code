/* 常见的处理事件 */
    on
        -abort  // 用户终止了页面的加载
        -blur   // 用户离开了对象
        -change   // 用户修改了对象
        -click   // 用户单击了对象
        -error  // 脚本遇到了一个错误
        -focus  // 用户激活了对象
        -load   // 对象完成了加载
        -mouseover   // 鼠标指针移动到对象上
        -mouseout   // 鼠标指针离开了对象
        -select   // 用户选择了对象的内容
        -submit   // 用户提交了表单
        -unload   // 用户离开了页面

/*--------------------------------------- */

/* 启动时绑定方法 */

// 在启动时绑定
window.onload = writeMessage

function writeMessage(){
    document.getElementById("helloMessage").innerHTML = "<h3>Hello, world.</h3>"
}

/* --------------------------------------- */

// 警告框
window.alert

// 确认框
window.confirm

// 确认时返回true, 否认时返回false
if (window.confirm("Are you sure?")){
    window.alert("yes")
} else {
    window.alert("no")
}

(window.confirm("Are you sure?")) ? window.alert("yes") : window.alert("no")

提示输入框
window.prompt
var msg = window.prompt("Write some thing.")
// 点击ok 返回内容, 若内容为空返回true, 点击cancel返回null
/* --------------------------------------- */

/* 重定向 */

<a href="source.html" id="redirect_link">点击</a>

// 在载入时为链接绑定重定向地址
window.onload = initAll

function initAll() {
    document.getElementById("redirect_link").onclick = initRedirect
}

function initRedirect() {
    window.location = "python.html"
    return false   // 表示停止对用户单击的处理, 这样就不会加载href的页面.
}

// 如果是用户单击链接, 用户若没有启动js, 那么就会使用原始的链接.

/* --------------------------------------- */

switch/case

switch(判断值){
    case 值1 :
        ...
        break
    case 值2 :
        ...
        break
    ...
    default:
        ...
}

/* --------------------------------------- */

/* 处理错误 */

try/throw/catch

window.onload = initAll

function initAll() {
    var ans = prompt("Enter a number", "")
    try{
        if (!ans || isNaN(ans) || ans<0){
            throw new Error("Not a valid number.")
        }
        window.alert("The square root of " + ans + "is" + Math.sqrt(ans))
    } catch (errMsg){
        window.alert("输出捕获的错误信息", errMsg.message)
    } finally {
        window.alert("不管什么都会执行的部分")
    }
}

isNaN  // 内置方法检查传递给他的参数是否是数字