package main

import "fmt"

func main() {
	var theSlice = make([]string, 4)
	a := 1
	theSlice[0] = "value1"
	theSlice[1] = "value2"
	theSlice[2] = "value3"
	theSlice[3] = "value4"
	fmt.Println(theSlice)
	var theSlice2 = make([]string, 2)
	copy(theSlice2, theSlice[2:])
	fmt.Println("经过复制:", theSlice2)
	fmt.Println("theSlice地址: ", &theSlice, "\ntheSlice2地址: ", &theSlice2, &a)
}
