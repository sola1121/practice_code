package main

import "fmt"

func main() {
	a := 88
	b := 11

	if a < 200 {
		fmt.Println("Yes, a is smaller than 200.")
	} else {
		fmt.Println("No, a is not smaller than 200.")
	}

	if b > 5 && b < 10 {
		fmt.Println("Yes, b is bigger than 5 and smaller than 10.")
	} else {
		fmt.Println("No, b is out of 5 between 10.")
	}
}
