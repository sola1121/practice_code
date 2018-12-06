package main

import (
	"fmt"
	"reflect"
)

type Drink struct {
	Name string
	Ice  bool
}

func main() {
	a := Drink{
		Name: "伏特加",
		Ice:  false,
	}

	var b = new(Drink) // 生成b指针
	b.Name = "伏特加"
	b.Ice = false

	if reflect.TypeOf(a) == reflect.TypeOf(b) {
		fmt.Println("他两的类型相同", reflect.TypeOf(a))
	} else {
		fmt.Println("他两的类型不同.", reflect.TypeOf(a), reflect.TypeOf(*b))
	}
}
