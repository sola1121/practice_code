package main

import "fmt"


func getPrice() (int, string) {
	var num int = 2
	var name string = "初学者魔法书"
	return num, name
}

func main() {
	quantity, price := getPrice()
	fmt.Printf("%v 只需要 %v个金币\n", price, quantity)
}