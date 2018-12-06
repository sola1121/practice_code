package main

import "fmt"


func isEven(num int) bool {
	return num % 2 == 0
}

func main(){
	fmt.Printf("1是偶数么 %v\n", isEven(1))
	fmt.Printf("2是偶数么 %v\n", isEven(2))
}