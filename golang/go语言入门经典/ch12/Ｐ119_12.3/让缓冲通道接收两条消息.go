package main

import (
	"fmt"
	"time"
)

func slowFunc(c chan string) {
	time.Sleep(time.Second * 2)
	c <- "sleeper() finish."
}

// 整个程序也就两秒完成了, 循环中go关键字会将函数并发执行, 脱离了主线程
func main() {
	ch := make(chan string, 2)
	for i := 0; i < 2; i++ {
		go slowFunc(ch)
	}
	// 这里会造成阻塞, 等待从通道中获取值
	msg1 := <-ch
	msg2 := <-ch
	fmt.Println(msg1, "\n", msg2)
}
