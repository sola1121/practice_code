package main

import "fmt"

var s = "在函数外省略类型"

func main(){
	s2 := "在函数内使用剪短变量声明"

	fmt.Printf("%v, %v", s, s2)
}