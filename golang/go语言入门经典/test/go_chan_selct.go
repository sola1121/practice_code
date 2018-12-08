package main

import (
	"fmt"
	"time"
)

type Counter struct {
	Count uint64
}

func (c *Counter) addCounter(ch chan<- uint64, i uint64) {
	for loop := 0; loop < 90000000; loop++ {
		ch <- i
		c.Count += i
	}
}

func main() {
	count := Counter{Count: 0}
	ch := make(chan uint64, 10)

	go count.addCounter(ch, 1)

	for {
		select {
		case m := <-ch:
			fmt.Print(m)
		case <-time.After(1 * time.Second):
			fmt.Println("Counter: ", count.Count)
			return
		}
	}
}
