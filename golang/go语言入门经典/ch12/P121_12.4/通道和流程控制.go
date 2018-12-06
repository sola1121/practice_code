package main

import (
	"fmt"
	"time"
)

func pinger(c chan string) {
	t := time.NewTicker(1 * time.Second)
	for {
		c <- "ping"
		<-t.C // 阻塞中, 直到取出t.C 中的数据
	}
}

func main() {
	message := make(chan string)
	go pinger(message)
	msg := <-message
	fmt.Println(msg)
}
