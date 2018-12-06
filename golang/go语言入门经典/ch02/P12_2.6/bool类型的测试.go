package main

import (
	"fmt"
)

func main(){
	var a bool
	fmt.Println("未初始化的bool", a)
	var b bool = false
	fmt.Println("初始化为false的bool", b)
}