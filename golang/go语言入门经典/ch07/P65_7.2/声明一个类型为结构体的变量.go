package main

import (
	"fmt"
)

type Movie struct {
	Name   string
	Rating float32
}

func main() {
	var m Movie
	fmt.Printf("%+v\n", m)
	m.Name = "毒液"
	m.Rating = 233.33
	fmt.Printf("%+v\n", m)
}
