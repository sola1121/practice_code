package main

import (
	"fmt"
	"time"
)

func pinger(c chan string) {
	t := time.NewTicker(1 * time.Second)
	for {
		c <- "ping"
		<-t.C // 时间阻塞, 将会每一秒阻塞一次
	}
}

func main() {
	message := make(chan string)
	go pinger(message)
	for {
		msg := <-message
		fmt.Println(msg)
	}
}
