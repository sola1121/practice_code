package main

import (
	"fmt"
	"regexp"
)

func main() {
	usernames := [4]string{
		"slimshady99",
		"!asdα33α3",
		"roger",
		"Iamthebestuserofthisappevaaaar",
	}

	regx1 := regexp.MustCompile("^[a-zA-Z0-9]{5, 12}")
	regx2 := regexp.MustCompile("[[:^alpha:]]")

	for _, username := range usernames {
		if len(username) > 12 {
			username = username[:12]
			fmt.Printf("trimmed username to %v\n", username)
		}
		// 不匹配就替换
		if !regx1.MatchString(username) {
			username = regx2.ReplaceAllString(username, "x")
			fmt.Printf("rewrote username to %v\n", username)
		}
	}
}
