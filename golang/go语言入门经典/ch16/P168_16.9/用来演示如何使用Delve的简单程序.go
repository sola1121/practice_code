package main

import (
	"bufio"
	"fmt"
	"os"
)

func echo(s string) {
	fmt.Println(s)
}

func main() {
	s := "Hello World"
	t := "Goodby Cruel World"
	// echo(s)
	// echo(t)
	fmt.Println(s)
	fmt.Println(t)
	reader := bufio.NewReader(os.Stdin)
	print("press any to quit")
	reader.ReadSlice('\n')
}
