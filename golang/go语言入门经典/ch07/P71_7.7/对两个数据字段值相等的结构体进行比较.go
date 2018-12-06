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

	b := Drink{
		Name: "伏特加",
		Ice:  true,
	}

	if a == b {
		fmt.Println("两个相等", b)
	} else {
		fmt.Println("两个不相等", a, b)
	}
}
