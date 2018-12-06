package main

import (
	"fmt"
	"io/ioutil"
)

func main() {
	file, err := ioutil.ReadFile("这是一个没有的文件.没有")
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Printf("%s\n", file)
}
