package main

import "fmt"


func anotherFunction(f func() string) string {
	return f()
}

func main() {
	fn := func() string {   // 匿名函数
		return "function called"
	}
	fmt.Println(anotherFunction(fn))
}
