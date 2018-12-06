package main

import (
	"fmt"
	"time"
)

func slowFun() {
	time.Sleep(time.Second * 2)
	fmt.Println("sleeper() finished.")
}

func main() {
	slowFun()
	fmt.Println("I am not shown until slowFunc() completes")
}
