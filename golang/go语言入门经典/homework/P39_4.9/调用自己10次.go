package main

import (
	"fmt"
)


func self_10(count int) {
	if count > 9 {
		return
	}
	fmt.Println(count)
	count += 1
	self_10(count)
}

func main() {
	self_10(0)
}