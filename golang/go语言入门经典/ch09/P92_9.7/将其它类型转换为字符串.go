package main

import (
	"fmt"
	"strconv"
)

func main() {
	var i int = 1
	var s string = " egg"
	intToString := strconv.Itoa(i)
	var breakfast string = intToString + s
	fmt.Println(breakfast)

	var otherInt int = 116 // 233
	var otherStr string = " kids"
	other := string(otherInt) + otherStr // 这尼玛直接把233 转换成了对应的Unicode字符
	fmt.Println(other)
}
