package main

import (
	"fmt"
	"time"
)

func sender(c chan string) {
	t := time.NewTicker(time.Second)
	defer t.Stop()
	for {
		c <- "I'm sending a message"
		<-t.C
	}
}

func main() {
	message := make(chan string)
	stop := make(chan bool)

	go sender(message)
	go func() {
		time.Sleep(time.Second * 20)
		fmt.Println("Time is Up.")
		stop <- true
	}()

	for {
		select {
		case <-stop:
			return
		case msg := <-message:
			fmt.Println(msg)
		}
	}
}
