package main

import (
	"fmt"
)

type Movie struct {
	Name   string
	Rating float32
}

func main() {
	m := Movie{
		Name:   "毒液",
		Rating: 233.33,
	}

	fmt.Println(m.Name, m.Rating)
}
