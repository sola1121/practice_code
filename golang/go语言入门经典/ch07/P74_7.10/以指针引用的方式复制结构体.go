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
		Name: "二锅头",
		Ice:  true,
	}

	b := &a // 引用地址, b将会是一个指针, 因为他记录了一个地址
	b.Ice = false

	fmt.Printf("%+v\n", *b) // 查看地址对应的值
	fmt.Printf("%+v\n", a)
	fmt.Printf("%p\n", b)
	fmt.Printf("%p\n", &a)
}
