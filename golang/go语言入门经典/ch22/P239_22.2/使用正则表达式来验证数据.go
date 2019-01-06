package main

import (
	"fmt"
	"regexp"
)

func main() {
	regx := regexp.MustCompile("^[a-zA-Z0-9]{5,12}$")

	fmt.Println(regx.MatchString("uqrioenvlq99"))
	fmt.Println(regx.MatchString("!adsf€88€;akf"))
	fmt.Println(regx.MatchString("roger"))
	fmt.Println(regx.MatchString("iamthebestuseofthisappevaaaaaar"))
}
