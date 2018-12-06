package main

import "fmt"

func main() {
	var cheeses = make([]string, 2)
	cheeses[0] = "切片的第一个元素"
	cheeses[1] = "切片的第二个元素"
	cheeses = append(cheeses, "新增的切片切片第三个元素")
	fmt.Println(cheeses[2])
}
