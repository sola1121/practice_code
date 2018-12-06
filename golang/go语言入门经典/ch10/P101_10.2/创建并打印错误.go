package main

import (
	"errors"
	"fmt"
)

func main() {
	err := errors.New("错误相当于一个变量, Go中的错误时完全自定义的, 实现error接口")
	if err != nil {
		fmt.Println(err)
	}
}
