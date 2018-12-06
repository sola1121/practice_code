package main

import (
	"fmt"
)

func main() {
	var cheeses [2]string
	cheeses[0] = "数组的第一个元素"
	cheeses[1] = "数组的第二个元素"
	fmt.Println(cheeses[0])
	fmt.Println(cheeses[1])
	fmt.Println(cheeses)
}
