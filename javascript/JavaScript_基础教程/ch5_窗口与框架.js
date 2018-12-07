<iframe src="iframe.html" id="icontent" name="icontent"></iframe>
<a href="#">Link 1</a>
<a href="#">Link 2</a>
<a href="#">Link 3</a>

## 将内容添加至名为icontent的iframe中

window.onload = initLinks

function initLinks() {
    for (var i=0; i<document.links.length; i++){
        document.links[i].onclick = writeContent   // 为链接绑定单击时事件
        document.links[i].thisPage = i+1   // 新建的一个属性, 这个属性存储一个值
    }
}

function writeContent() {
    var newText = "<h1>hello, world.</h1><p>this.thisPage</p>"

    document.getElementById("icontent").contentWindow.document.body.innerHTML = newText   // 将改变iframe中的窗体的内容
    return false   // 停止进一步加载href
}

---------------------------------------

## 记录链接被点击的次数的iframe

window.onload = initLinks
var pageCount = new Array(0, 0, 0, 0)   // 用于记录点击次数的数组

function initLinks() {
    for (var i=0; i<document.links.length; i++){
        document.links[i].onclick = writeContent   // 为链接绑定单击时事件
        document.links[i].thisPage = i+1   // 新建的一个属性, 这个属性存储一个值
    }
}

function writeContent() {
    pageCount[this.thisPage]++   // 每单击一次, 将记录中对应的页数组值增加1

    var newText = "<h1>hello, world.</h1><p>this.thisPage</p>"
    newText += "<p>you have clicked this link"
    newText += pageCount[this.thisPage] + " times</p>"

    document.getElementById("icontent").contentWindow.document.body.innerHTML = newText   // 将改变iframe中的窗体的内容
    return false   // 停止进一步加载href
}

---------------------------------------

## 同宗文档间共享函数
## 这是写在iframe页面中的js

window.onload = initLinks

var bannerArray = new Array("images/reading1.gif", "images/reading2.gif", "images/reading3.gif")

function initLinks() {
    for (var i=0; i<parent.document.links.length; i++){   // 获取父页面中的文档中的链接
        parent.document.links[i].onclick = setBanner
    }

    setBanner()
}

function setBanner(){
    var randomNum = Math.floor(Math.random() * bannerArray.length)   // 随机生成范围内的数

    parent.document.getElementById("adbanner").src = bannerArray[randomNum]   // 对应的图片
    return false
}

---------------------------------------

## 在当前页面打开新窗口

window.onload = newWinLinks

function newWinLinks () {
    for (var i=0; i<document.links.length; i++){
        if (document.links[i].className == "newWin")
        document.links[i].onclick = newWindow
    }
}

function newWindow () {
    var newWin = window.open("images/pixel.jpg", "a cat pic", "resizable=no,width=350,height=60")   // open(url?: string, target?: string, features?: string, replace?: boolean)
}