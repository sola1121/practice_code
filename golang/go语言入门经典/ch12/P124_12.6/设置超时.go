package main

import (
	"fmt"
	"time"
)

func ping1(c chan string) {
	time.Sleep(time.Second * 1)
	c <- "ping1 finished."
}

func ping2(c chan string) {
	time.Sleep(time.Second * 2)
	c <- "ping2 finished."
}

func main() {
	ch1 := make(chan string)
	ch2 := make(chan string)

	go ping1(ch1)
	go ping2(ch2)

	select {
	case msg1 := <-ch1:
		fmt.Println(msg1)
	case msg2 := <-ch2:
		fmt.Println(msg2)
	case <-time.After(500 * time.Millisecond):
		fmt.Println("Time Out.")
	}
}
