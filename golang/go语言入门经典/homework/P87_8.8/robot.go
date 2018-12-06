// robot.go
package main

import (
	"errors"
	"fmt"
)

type Robot interface {
	PowerOn() error
	Talk(string) string
}

type T850 struct {
	Name string
}

type R2D2 struct {
	Broken bool
}

func (t *T850) PowerOn() error {
	return nil
}

func (r *R2D2) PowerOn() error {
	if r.Broken {
		return errors.New("R2D2 is broken")
	} else {
		return nil
	}
}

func (t *T850) Talk(words string) string {
	return words
}

func (r *R2D2) Talk(words string) string {
	return words
}

func Boot(ro Robot, str string) {
	err := ro.PowerOn()
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println("Yes, this robot is working.")
	}
	fmt.Println(ro.Talk(str))
}

func main() {
	t := T850{Name: "the Terminator"}
	Boot(&t, "I'll be back.")

	r := R2D2{Broken: true}
	Boot(&r, "yes, broken again.")
}
