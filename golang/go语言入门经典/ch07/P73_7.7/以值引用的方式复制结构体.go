package main

import (
	"fmt"
)

type Drink struct {
	Name string
	Ice  bool
}

func main() {
	a := Drink{
		Name: "伏特加",
		Ice:  true,
	}

	b := a // 将会进行值传递, 可以通过下面打印出的值和地址来判断
	b.Ice = false

	fmt.Printf("%+v\n", b)
	fmt.Printf("%+v\n", a)
	fmt.Printf("%p\n", &b)
	fmt.Printf("%p\n", &a)
}
