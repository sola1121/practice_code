package main

import (
	"fmt"
)

type SuperHero struct {
	Name    string
	Age     int
	Address Address
}

type Address struct {
	Number int
	Street string
	City   string
}

func main() {
	e := SuperHero{
		Name: "vtuber",
		Age:  1,
		Address: Address{
			Number: 22,
			Street: "白色无垠的世界",
			City:   "电脑虚数端的某个地方",
		},
	}

	fmt.Printf("%+v\n", e)
}
