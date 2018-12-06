package main

import (
	"fmt"
)

func main() {
	var cheeses = make([]string, 3)
	cheeses[0] = "切片元素1"
	cheeses[1] = "切片元素2"
	cheeses[2] = "切片元素3"
	fmt.Println("切片", cheeses[2:])
	fmt.Println(len(cheeses))
	fmt.Println(cheeses)
	cheeses = append(cheeses[:2], cheeses[2+1:]...)
	fmt.Println(len(cheeses))
	fmt.Println(cheeses)
}
