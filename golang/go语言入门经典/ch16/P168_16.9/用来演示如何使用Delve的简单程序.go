package main

import (
	"bufio"
	"fmt"
	"os"
)

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
