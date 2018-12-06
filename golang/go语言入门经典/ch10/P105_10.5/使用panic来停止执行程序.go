package main

import (
	"fmt"
)

func main() {
	fmt.Println("This is Excuted.")
	panic("Here to raise panic and terminate the process.")
	fmt.Println("This will never be runned.")
}
