package main

import "fmt"

type Person struct {
	Name    string
	Age     int
	Hobbies []string
}

func main() {
	hobbies := []string{"抽烟", "喝酒", "烫头"}
	p := Person{
		Name:    "二哈子",
		Age:     20,
		Hobbies: hobbies,
	}
	fmt.Printf("%+v\n", p)
}
