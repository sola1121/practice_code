package main

import (
	"fmt"
)

type Movie struct {
	Name   string
	Rating float32
}

func main() {
	m := new(Movie)
	m.Name = "二愣子"
	m.Rating = 0.99
	fmt.Printf("%+v\n", m)
}
