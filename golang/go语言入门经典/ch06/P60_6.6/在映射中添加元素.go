package main

import "fmt"

func main() {
	var players = make(map[string]int)
	players["value1"] = 111
	players["value2"] = 222
	players["value3"] = 333
	fmt.Println(players)
	fmt.Println(players["value3"])
}
