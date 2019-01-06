package main

import (
	"fmt"
	"io"
	"log"
	"os"
)

func main() {
	// 源文件
	from, err := os.Open("example.txt")
	if err != nil {
		log.Fatal(err)
	}

	defer from.Close()

	// 目标文件
	to, err := os.OpenFile("example_copy.log", os.O_RDWR|os.O_CREATE, 0644)
	if err != nil {
		log.Fatal(err)
	}
	defer to.Close()

	// 进行复制
	var i int64
	i, err = io.Copy(to, from)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("written", i)
}
