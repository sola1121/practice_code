package main

import (
	"fmt"
	"time"
)

func slowFunc(ch chan string) {
	fmt.Println("在调用函数中的通道: ", &ch)
	time.Sleep(time.Second * 2)
	ch <- "sleeper() finished"
}

func main() {
	ch := make(chan string)
	fmt.Println("在主函数中的通道: ", &ch)
	go slowFunc(ch)
	msg := <-ch
	fmt.Println(msg)
}
