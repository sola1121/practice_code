package main

import "fmt"

func showMemoryAddress(x *int){
	fmt.Println("指针的值是", x)   // 会创建元数据的一个指向指针
}

func showValue(x int) {
	fmt.Println("数据的地址是", &x)   // 会创建元数据的副本
}

func main() {
	var num int = 1
	fmt.Print("元数据地址: ", &num, "\n")

	showValue(num)
	showMemoryAddress(&num)
}