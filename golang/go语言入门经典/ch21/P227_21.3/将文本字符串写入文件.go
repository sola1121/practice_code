package main

import (
	"fmt"
	"io/ioutil"
	"log"
)

func main() {
	s := "hello, file."
	if err := ioutil.WriteFile("example.log", []byte(s), 0644); err != nil {
		log.Fatal(err)
	}
	fmt.Println("done.")
}
