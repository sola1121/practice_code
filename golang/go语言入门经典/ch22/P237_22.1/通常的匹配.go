package main

import (
	"fmt"
	"log"
	"regexp"
)

func main() {
	needle := "chocolate"
	haystack := "Chocolate coffee is tasty."
	match, err := regexp.MatchString(needle, haystack)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(match)
}
