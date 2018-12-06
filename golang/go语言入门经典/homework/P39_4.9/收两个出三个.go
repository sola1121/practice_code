package main

import (
	"fmt"
)


func out_3(x, y int) (a, b, c int) {
	a, b, c = x, y, x+y
	return 
}

func main() {
	 a, b, c := out_3(2, 3)
	 fmt.Printf("%v + %v = %v\n", a, b, c)
}
