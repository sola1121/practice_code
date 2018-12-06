package main

import (
	"fmt"
)

func getMultivalue(x int, s string) (int, string) {
	return x, s
}

var i, s = getMultivalue(1, "2")

func main() {
	fmt.Println(i, s)

	// var b string // 只声明, 未初始化, 使用""
	// if b {
	// 	fmt.Println("b中有值")
	// } else {
	// 	fmt.Println("b中无值")
	// }
}
