package main

import (
	"fmt"
	"time"
)

func slowFunc() {
	time.Sleep(time.Second * 3)
	fmt.Println("sleeper() finished")
}

func main() {
	go slowFunc()
	fmt.Println("I am not show until slowFunc() completes")
	time.Sleep(time.Second * 5)
}
