package main

import (
	"fmt"
	"io/ioutil"
	"log"
)

func main() {
	fileBytes, err := ioutil.ReadFile("/home/sola1121/文档/资料文件/00 python工具的使用/virtualenv_虚拟环境.txt")
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(fileBytes)
	fileString := string(fileBytes)
	fmt.Println(fileString)
}
