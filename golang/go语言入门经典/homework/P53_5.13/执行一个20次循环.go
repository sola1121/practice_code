package main

import (
	"fmt"
)

func main() {
	for i := 0; i < 20; i++ {
		fmt.Println(i)
	}

	var m = 0

	for m < 20 {
		fmt.Println(m)
		m++
	}
}
