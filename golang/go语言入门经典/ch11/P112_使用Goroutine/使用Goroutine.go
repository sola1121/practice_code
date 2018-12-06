package main

import (
	"fmt"
	"time"
)

func slowFunc() {
	time.Sleep(time.Second * 4)
	fmt.Println("sleeper() finished.")
}

func main() {
	go slowFunc()
	fmt.Println("I am now shown straightway.")
}
