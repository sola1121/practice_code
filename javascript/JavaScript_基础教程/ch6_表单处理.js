<form action="gotoLocation.cgi">
    <select id="newLocation">
        <option value="goto1.html">跳转网页1</option>        
        <option value="goto2.html">跳转网页2</option>
        <option value="goto3.html">跳转网页3</option>
        <option value="goto4.html">跳转网页4</option>
        <option value="goto5.html">跳转网页5</option>        
    </select>
    <noscript>
        <input type="submit" value="jump">
    </noscript>
</form>
/</form>

## 使用表单实现站点导航

window.onload = initForm
window.onunload = function(){}   // 当窗口卸载时, 处理一些浏览器的特殊行为, 这里将其设为空了

function initForm() {
    document.getElementById("newLocation").selectedIndex = 0
    document.getElementById("newLocation").onchange = jumpPage   // 发生改变时做出反应
}

function jumpPage() {
    var newLoc = document.getElementById("newLocation")
    var newPage = newLoc.options[newLoc.selectedIndex].value   // 获取select标签中的value值

    if (newPage != ""){
        window.location = newPage   // 跳转到新的页面
    }
}

## 动态的显示, 例如月份

<form action="#">
    <select id="months">
        <option value="">Month</option>
        <option value="0">January</option>
        <option value="1">February</option>
        <option value="2">March</option>
        <option value="3">April</option>
        <option value="4">May</option>
        <option value="5">June</option>
        <option value="6">July</option>
        <option value="7">August</option>
        <option value="8">September</option>
        <option value="9">October</option>
        <option value="10">November</option>
        <option value="11">December</option>
    </select>
    <select id="days">
        <option>Day</option>
    </select>
</form>
/</form>

window.onload = initForm

function initForm() {
    document.getElementById("months").selectedIndex = 0
    document.getElementById("months").onchange = populateDays
}

function populateDays (){
    var monthDays = new Array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)  // 每月对应的天数
    var monthStr = this.options[this.selectedIndex].value

    if (monthStr !=""){
        var theMonth = parseInt(monthStr)   // 对应标签中的0~11
        document.getElementById("days").options.length = 0   // 改变Day菜单时, 首先将它的选项长度设置为零, 这会消除以前操作的影响.
        for (var i=0; i<monthDays[theMonth]; i++){
            document.getElementById("days").options[i] = new Option(i + 1)   // 遍历所选月份中的每一天, 并将Option对象赋予它
        }
    }
}


## 建立必须填写的字段

input.invalid{
    background-color: #FF9;
    border: 2px red inset;
}
label.invalid{
    color: #F00;
    font-weight: bold;
}

<form>
    <p><label for="userName">Your Name:<input type="text" size="30" id="userName" class="reqd"></input></label></p>
    <p><label for="passwd1">Choose a password:<input type="password" size="30" id="passwd1" class="reqd"></input></label></p>
    <p><label for="passwd2">Verify password:<input type="password" size="30" id="passwd2" class="reqd passwd1"></input></label></p>
    <input type="submit" value="提交按钮">
</form>
</form>

window.onload = function() {
    document.forms[0].onsubmit = validForm
}

function validForm() {
    var allGood = true
    var allTags = document.forms[0].getElementsByTagName("*")   // 表单内所有的tag标签

    for (var i=0; i<allTags.length; i++){   // 对每个tag对象调用validTag方法验证标签内容
        if (!validTag(allTags[i])){
            allGood = false
        }
    }
    return allGood

    function validTag(thisTag) {   
        var outClass = ""
        var allClasses = thisTag.className.split(" ")   // 以空格分开为数组, 如class="reqd passwd1" 的passwd2

        for (var j=0; j<allClasses.length; j++){   // 对allClasses中的每一个class进行循环, 已检查其中的表示的内容, 如reqd就是需要填写的字段
            outClass += validBasedOnClass(allClasses[j] + " ")
        }

        thisTag.className = outClass   // 重新返回className, 这会改变在标签中的class的值, 那么当遇到为空的字段会被添上invalid, 可以对上相应的css

        if (outClass.indexOf("invalid") > -1){   // 如果在class中添加了invalid, 检验在数组中是否存在invalid值
            invalidLabel(thisTag.parentNode)   // 用于标记无效字段
            thisTag.focus()        // 获取当前标签的焦点
            if(thisTag.nodeName == "INPUT"){   // 如果当前标签的节点为input
                thisTag.select()   // 符合条件选择当前标签的值
            }
            return false
        }
        return true

        function validBasedOnClass(thisClass){   // 用于监测class的值, 是否如描述, 如 reqd是必填字段, 那么需要其不为空
            var classBack = ""   // 想要返回的类的值

            switch(thisClass){
                case "":
                case "invalid":
                    break
                case "reqd":
                    if (allGood && thisTag.value == ""){
                        classBack = "invalid"
                    }
                    classback += thisClass
                    break
                default:
                    if (allGood && !crossCheck(thisTag, thisClass)){   // 校验
                        classBack = "invalid"
                    }
                    classBack += thisClass
            }
            return classBack
        }

        function crossCheck(inTag, otherFieldID){   // 校验两值是否相等
            if (!document.getElementById(otherFieldID)){
                return false
            }
            return (inTag.value == document.getElementById(otherFieldID).value)
        }

        function invalidLabel(parentTag){   // 用于标记无效字段的label标签
            if (parentTag.nodeName == "LABEL"){
                parentTag.className += " invalid"   // 将满足条件的标签的class添加一个invalid
            }
        }
    }
}

