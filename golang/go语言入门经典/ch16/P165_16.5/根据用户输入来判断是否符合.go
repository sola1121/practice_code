package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Guess the name of my pet: ")
	text, _ := reader.ReadString('\n')
	text = strings.Replace(text, "\n", "", -1)

	if text == "John" {
		fmt.Println("You won!")
	} else {
		fmt.Println("You got a wrong answer.")
	}
}
