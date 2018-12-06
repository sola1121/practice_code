package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

func randomMsg(c chan<- string) {
	randNum := rand.New(rand.NewSource(time.Now().UnixNano()))

	num := randNum.Intn(10)
	numStr := strconv.Itoa(num) + "s"
	fmt.Println("随机时间: ", numStr)

	d, _ := time.ParseDuration(numStr)
	for {
		time.Sleep(d)
		c <- "send a message."
	}
}

func main() {
	var timeOut time.Duration // int64 表示基础单位纳秒
	timeOut = time.Second * 5
	ch := make(chan string)

	go randomMsg(ch)

	for {
		select {
		case <-time.After(timeOut): // 没有获得到数据将会在秒数外return
			fmt.Printf("超时%ds返回\n", timeOut/1e9)
			return
		case msg := <-ch:
			fmt.Println("正从消息通道中获取消息: ", msg)
		}
	}
}
