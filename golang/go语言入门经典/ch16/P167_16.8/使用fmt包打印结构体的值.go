package main

import "fmt"

type animal struct {
	Name  string
	Color string
}

func main() {
	a := animal{
		Name:  "cat",
		Color: "black and white",
	}

	fmt.Printf("%v\n", a)
	fmt.Printf("%+v\n", a)
}
