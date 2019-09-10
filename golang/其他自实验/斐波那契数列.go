package main

import "fmt"

func main() {
	fmt.Println(fib(5))
}

func fib(num int) []int {
	arr := []int{0}
	if num <= 0 {
		return arr
	}
	if num == 1 {
		return append(arr, 1)
	}
	a, b := 1, 1
	for i := 0; i < num; i++ {
		a, b = b, a+b
		arr = append(arr, b)
	}
	return arr
}
