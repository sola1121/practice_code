package main

import (
	"flag"
	"fmt"
)

func main() {
	s := flag.String("s", "hello,world", "string help text")
	flag.Parse()
	fmt.Println("value of s: ", *s)
}
