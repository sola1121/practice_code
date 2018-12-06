package main

import "fmt"

func main(){
	var a int
	var b float32
	var c bool
	var d string

	fmt.Printf("a %v, b %v, c %v, d %v \n" , a, b, c, d)

	if d == ""{
		fmt.Println("d是空值, 这里啥都没显示.")
	}
}