package main

import "fmt"

func main() {
	var cheeses = make([]string, 3) // 一个长度为三的切片
	cheeses[0] = "切片元素1"
	cheeses[1] = "切片元素2"
	var smellyCheeses = make([]string, 2)
	copy(smellyCheeses, cheeses)
	fmt.Println(smellyCheeses)
	fmt.Println("cheeses的长度: ", len(cheeses), "smellyCheeses的长度: ", len(smellyCheeses))
}
