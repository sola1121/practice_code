package main

import "fmt"

type TheS struct {
	Name string
}

func (s TheS) M1() {
	s.Name = "value"
}

func (s *TheS) M2() {
	s.Name = "pointer"
}

func main() {
	var s1 = TheS{"new"}
	var s2 = &s1
	s1.M2()
	fmt.Printf("%+v, %+v\n", s1, s2)

	s1 = TheS{"new"}
	s2 = &s1
	s2.M1()
	fmt.Printf("%+v, %+v\n", s1, s2)
}
