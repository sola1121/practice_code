// bingo 游戏
// 5 * 5 格子

<table>
    <tr>
        <td>B</td>
        <td>I</td>
        <td>N</td>
        <td>G</td>
        <td>O</td>
    </tr>
    <tr>
        <td id="square0"></td>
        <td id="square5"></td>
        <td id="square10"></td>
        <td id="square14"></td>
        <td id="square19"></td>
    </tr>
    <tr>
        <td id="square1"></td>
        <td id="square6"></td>
        <td id="square11"></td>
        <td id="square15"></td>
        <td id="square20"></td>
    </tr>
    <tr>
        <td id="square2"></td>
        <td id="square7"></td>
        <td id="squareFree">Free</td>
        <td id="square16"></td>
        <td id="square21"></td>
    </tr><tr>
        <td id="square3"></td>
        <td id="square8"></td>
        <td id="square12"></td>
        <td id="square17"></td>
        <td id="square22"></td>
    </tr><tr>
        <td id="square4"></td>
        <td id="square9"></td>
        <td id="square13"></td>
        <td id="square18"></td>
        <td id="square23"></td>
    </tr>
</table>


// 随机生成Bingo列中的数字, 保证每列中不重复
window.onload = initAll

var usedNum = new Array(76)   // 用来保存数字是否使用的76个元素的数组

function initAll() {
    if (document.getElementById){   // 对象探测, 浏览器是否支持
        newCard()
        document.getElementById("reload").onclick = anotherCard   // 重开新的bingo
    } else {
        window.alert("Sorry, your browser doesn't supprt this script")
    }
}

function newCard(){
    for (var i=0; i<24; i++){   // 生成对应的squareID的ID号, 一共25个
        setSquare(i)
    }
}

function setSquare(thisSquare){   // 用于生成在<td>中的数字, thisSquare就是对应的id, 1~25
    var currSquare = "square" + thisSquare   // 对应的<td>id属性
    var colPlace = new Array(0,0,0,0,0, 1,1,1,1,1, 2,2,2,2, 3,3,3,3,3, 4,4,4,4,4)   // 每列对应的基数
    var colBasis = colPlace[thisSquare] * 15   // 通过与每列基数相乘, 获得值, 范围是15
    var newNum   // 用来记录新数的

    do {  // 先执行在判断的循环
        newNum = colBasis + getNewNum() + 1
    } while (usedNum[newNum])   // 查询生成的数在记录数组中是否已经记录了, 如果已经记录了, 将会执行此循环, 重新生成数

    usedNum[newNum] = true   // 生成了新数后记录在usedNum中, 每个数对应数组中一个值, 存在就设为true
    document.getElementById(currSquare).innerHTML = newNum

    // 添加的css效果
    document.getElementById(currSquare).className = ""
    document.getElementById(currSquare).onmousedown = toggleColor
}

function getNewNum() {
    return Math.floor(Math.random() * 15)   // 生成限制15数值内随机新数
}

function anotherCard() {   // 生成新的bingo游戏
    for (var i=1; i<usedNum.length; i++){
        usedNum[i] = false
    }

    newCard()
    return false
}

function toggleColor(evt){   // 更改className来切换界面样式
    if (evt) {   // 现代浏览器会将一个参数传递给调用者
        var thisSquare = evt.target   // 获得对象
    } else {
        var thisSquare = window.event.srcElement   // IE
    }
    if (thisSquare.className == "") {
        thisSquare.className = "pickBG"
    } else {
        thisSquare.className = ""
    }
    checkWin()   // 每次点击检查是否获胜了
}

// 算法判断是否获胜
function checkWin() {
    var winningOption = -1   // 存储用户可能遇到的获胜选项(如果有)
    var setSquares = 0   // 存储已经单击的格子
    var winners = new Array(31,992,15360,501904,541729,557328,1083458,2162820,4329736,8519745,8659472,16252928)   // 有效获胜组合的编码值

    for (var i=0; i<24; i++){
        var currSquare = "square" + i
        if (document.getElementById(currSquare).className != ""){   // 遍历了所有没有被选中的格子
            document.getElementById(currSquare).className = "pickBG"
            setSquares = setSquares | Math.pow(2, i)
        }
    }

    for (var i=0; i<winners.length; i++){
        if ((winners[i] & setSquares) == winners[i]){
            winningOption = 1
        }
    }

    if (winningOption > -1){
        for (var i=0; i<24; i++){
            if (winners[winningOption] & Math.pow(2, i)){
                currSquare = "square" + i
                document.getElementById(currSquare).className = "winnerBG"
            }
        }
    }

}