package main

import (
	"fmt"
)

func main() {
	s := "Oh sweet ignition" + " be my fuse"
	fmt.Println(s)
	s += ". Here add more."
	fmt.Println(s, len(s), s[40], string(s[40]))

	s = "hello,world"
	fmt.Println(s[1], string(s[1]), len(s))
}
