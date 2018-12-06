package main

import (
	"fmt"
	"strconv"
)


func main() {
	var variable string = "这是一个字符串"
	fmt.Println("我将打印variable ", variable)

	variable = "这是一个改变了的变量字符串"
	fmt.Println("我将打印改变了的variable ", variable)

	variable = "42"
	variable = strconv.FormatInt(int64(46), 10)
	fmt.Println("再次改变变量variable, 将其变为整数", variable)
}