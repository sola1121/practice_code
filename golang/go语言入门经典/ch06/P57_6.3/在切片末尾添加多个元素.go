package main

import (
	"fmt"
)

func main() {
	var cheeses = make([]string, 2)
	cheeses[0] = "切片的第一个元素"
	cheeses[1] = "切片的第二个元素"
	cheeses = append(cheeses, "在填元素3", "在填元素4", "在填元素5")
	fmt.Println(cheeses)
}
