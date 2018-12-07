## 由图片触发的翻转器

// onmouseover, onmouseout, document.images

<a href="next.html" onmouseover="document.images['arraw'].src=images/arrow_on.gif" onmouseout="document.images['arraw'].src='images/arraw_off.gif">
    <img src="image/arraw_on.gif" id="arraw"></img> 
</a>
// document.images中保存了页面上的所有图片


// 先将所有图片加载到本地后, 在实现翻转器, 避免网络延迟

<a><img src="images/button1_off.gif" id="button1"></img></a>
<a><img src="images/button2_off.gif" id="button2"></img></a>

window.onload = rolloverInit

function rolloverInit() {
    for (var i=0; i<document.images.length; i++){
        if (document.images[i].parentNode.tagName == "A"){   // 检测父节点是否是<a>标签, 
            setupRollover(document.images[i])
        }
    }
}

function setupRollover(theImage) {
    // 图片off时使用
    theImage.outImage = new Image()   // 创建新的属性, 这个属性是一个图像对象
    theImage.outImage.src = theImage.src   // 让新建的图像对象src属性等于原始值
    theImage.onmouseout = function(){   // 当img图片对象鼠标移下后
        this.src = this.outImage.src
    }

    // 图片on时使用
    theImage.overImage = new Image()   // 创建新的属性, 这个属性是一个图像对象
    theImage.overImage.src = "images/" + theImage.id + "_on.gif"   // 传入图像的id, 让新建的图像对象src属性等于新值
    theImage.onmouseover = function(){   // 当img图片对象鼠标移上后
        this.src = this.overImage.src
    }

    // 图片click时使用
    theImage.clickImage = new Image()
    theImage.clickImage.src = "images" + theImage.id + "_click.gif"
    theImage.onclick = function(){
        this.src = this.clickimage.src
    }
}

// parentNode当前对象的父节点, tagName当前对象的标签名称
// 相当于在载入时, 创建了两个新的图像, 并在旧的图像对象上绑定了鼠标事件, 当触发时, 其src会随之改变

---------------------------------------

## 由链接触发的翻转器

<a href="next.html" id="arrow">这是一条链接</a>
<img src="images/arraw_off.gif" id="arrowImg"></img>

window.onload = rolloverInit

function rolloverInit() {
    for (var i=0; i<document.links.length; i++){   // document.links 所有的链接对象
        var linkObj = document.links[i]
        if (linkObj.id) {
            var imgObj = document.getElementById(linkObj.id + "Img")
            if (imgObj) {
                setupRollover(linkObj, imgObj)
            }
        }
    }
}

function setupRollover(theLink, theImage) {
    theLink.imgToChange = theImage
    theLink.onmouseout = function(){
        this.imgToChange.src = this.outImage.src
    }

    theLink.onmouseover = function(){
        this.imgToChange.src = this.overImage.src
    }

    thelink.outImage = new Image()
    theLink.outImage.src = theImage.src

    theLink.overImage = new Image()
    theLink.overImage.src = "images/" + theLink.id + "_on.gif"
}


---------------------------------------

## 处理多个翻转器

<div id="captionDiv">
    <img src="images/DaVinci.jpg"></img>
    <img src="images/bg.gif" id="captionField"></img>
</div>
<div id="inventionDiv">
    <img src="images/leoText.gif" id="heading"></img>
    <a href="flyPage.html" class="captionField" id="flyer"><img src="images/flyer.gif" id="flyerImg"></img></a>
    <a href="tankPage.html" class="captionField" id="tank"><img src="images/tank.gif" id="tankImg"></img></a>
    <a href="heliPage.html" class="captionField" id="helicopter"><img src="images/helicopter.gif" id="helicopterImg"></img></a>
</div>

window.onload = rolloverInit

function rolloverInit() {
    for (var i=0; i<document.links.length; i++){   // 遍历所有links, 就是拥有href的a标签
        var linkObj = document.links[i]   // 获取每个标签对象
        if (linkObj.className) {   // 如果该标签对象具有class属性
            var imgObj = document.getElementById(linkObj.id + "Img")  // 获取a标签下的每个img对象 
            if (imgObj) {
                setupRollover(linkObj, imgObj)
            }
        }
    }
}

function setupRollover(thisLink, textImage){
    theLink.imageToChange = new Array
    theLink.outImage = new Array
    theLink.overImage = new Array

    theLink.imgToChange[0] = textImage   // 等于原先的img对象
    theLink.onmouseout = rollOut
    theLink.onmouseover = rollOver

    theLink.outImage[0] = new Image()
    theLink.outImage[0].src = textImage.src   // 等于原先的图像对象的src

    theLink.overImage[0] = new Image()
    theLink.overImage[0].src = "images/" + theLink.id + "Text.gif"   // 设置img的新的src

    var rolloverObj = document.getElementById(theLink.id + "Img")
    if (rolloverObj) {
        theLink.imgToChange[1] = rolloverObj

        theLink.outImage[1] = new Image()
        theLink.outImage[1].src = rolloverObj.src

        theLink.overImage[1] = new Image()
        theLink.overImage[1].src = "images/" + theLink.id + "_on.gif"
    }
}

function rollOver(){
    for (var i=0; i<this.imgToChange.length; i++){
        this.imgToChange[i].src = this.overImage[i].src
    }
}

function rollOut(){
    for (var i=0; i<this.imgToChange.length; i++){
        this.imgToChange[i].src = this.outImage[i].src
    }
}


---------------------------------------

## 循环的广告条

<div class="centered">
    <a href="ad1.html"><img src="images/reading1.gif" id="adBanner"></img></a>
</div>

window.onload = initBannerLink

var theAd = 0
var adURL = new Array("bilibili.com", "acfun.cn", "niconico.jp")
var AdImages = new Array("images/reading1.gif", "images/reading2.gif", "images/reading3.gif")

function initBannerLink() {
    if (document.getElementById("adBanner").parentNode.tagName == "A"){
        document.getElementById("adBanner").parentNode.onclick = newLocation   // 绑定窗口的href
    }

    rotate()   // 调用rotate, rotate将会触发setTimeout, 这将会一直使rotate运行下去
}

function newLocation() {
    document.location.href = "http://www." + adURL[theAd]
    return false   // 告诉浏览器不在加载这个href
}

function rotate() {
    theAd++   // 相当于一个基于时间的循环了
    if (theAd == adImages.length){
        theAd == 0
    }
    document.getElementById("adBanner").src = adImages[theAd]   // 更换图片src

    setTimeout(rotate, 3*1000)   // 每3秒执行rotate
}

---------------------------------------

## 建立循环式幻灯片

<div class="centered">
    <img src="images/robot1.jpg" id="myPicture"></img>
    <a href="previous.html" id="prevLink">Previous</a>
    <a href="next.html" id="nextLink">Next</a>
</div>

window.onload = initLinks

var thePic = 0
var myPix = new Array("images/robots.jpg", "images/tobot2.jpg", "images/robot3.jpg")

function initLinks () {
    document.getElementById("prevLink").onclick = processPrev
    document.getElementById("nextLink").onclick = processNext
}


function processPrev () {   // 实现向前看
    if (thePic == 0){
        thePic = myPix.length
    }
    thePic--
    document.getElementById("myPicture").src = myPix[thePic]
    return false
}

function processNext() {   // 实现向后看
    thePic++ 
    if (thePic == myPix.length) {
        thePic = 0
    }
    document.getElementById("myPicture").src = myPix[thePic]
    return false
}

---------------------------------------

## 显示随机图像

<img src="images/spacer.gif" id="myPicture"></img>

window.onload = choosePic

var myPix = new Array("images/lion.jpg", "images/tiger.jpg", "images/bear.jpg")

function choosePic() {
    var randomNum = Math.floor(Math.random * myPix.length)   // 生成个数内随机数
    document.getElementById("myPicture").src = myPix[randomNum]   // 生成随机图片的src
}

---------------------------------------

## 随机开始循环显示图像

<div class="created">
    <img src="images/spacer.gif" id="adBanner"></img>
</div>

window.onload = choosePic

var theAd = 0   // 图片下标

var adImages = new Array("images/reading1.gif", "images/reading2.gif", "images/reading3.gif")

function choosePic() {
    theAd = Math.floor(Math.random * adImages.length)   // 生成个数内随机数
    document.getElementById("adBanner").src = adImages[theAd]   // 随机切换图片

    rotate()   // 然后开始循环
}

function rotate() {
    theAd++

    if (theAd == adImages.length){
        theAd = 0
    }

    document.getElementById("adBanner").src = adImages[theAd]

    setTimeout(rotate, 3*1000)
}

