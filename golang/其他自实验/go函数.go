package main

import "fmt"

type PInt func(int, int) // 定义函数类型

func (f PInt) MyFunc() {
	fmt.Println("调用函数的方法")
}

func doThing(int, int) {
	fmt.Println("外部方法")
}

func main() {
	a := PInt(doThing) // 类型转换, 将外部的函数转换?
	a(1, 2)            // 直接调用就是外部转换后的方法, 使用外部函数
	a.MyFunc()         // 使用内部方法
}

// 估计能转换的条件就是外部函数和内部函数的各签名相同?
