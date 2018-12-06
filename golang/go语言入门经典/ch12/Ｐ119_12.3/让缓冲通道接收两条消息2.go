package main

import (
	"fmt"
	"time"
)

// func slowFunc(c chan string) {
// 	time.Sleep(time.Second * 2)
// 	c <- "sleeper() finished."
// }

func receiver(c chan string) { // 使用for range 遍历缓冲通道, 读取其中的信息
	for msg := range c {
		fmt.Println(msg)
	}
}

func main() {
	message := make(chan string, 2)
	message <- "hello"
	message <- "world"
	close(message) // 关闭通道, 这意味着不能在像通道中发送信息
	fmt.Println("Pushed two message onto Channel with no receivers, 通道长度: ", len(message))
	time.Sleep(time.Second * 1)
	receiver(message)
}
