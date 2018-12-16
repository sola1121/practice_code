package main

import (
	"flag"
	"fmt"
)

func main() {
	s := flag.String("s", "hello,world", "string value to describe something")
	i := flag.Int("i", 233, "the number to describe something")
	b := flag.Bool("b", false, "the boolean value to describe something")
	flag.Parse()
	fmt.Println("the value of s: ", *s)
	fmt.Println("the value of i: ", *i)
	fmt.Println("the value of b: ", *b)
}
