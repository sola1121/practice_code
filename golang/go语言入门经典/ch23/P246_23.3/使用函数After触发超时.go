package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("You have 3s to caculate 19*4")
	for {
		select {
		case <-time.After(3 * time.Second):
			fmt.Println("Time's up, The ansewer is", 19*4)
			return
		}
	}
}
