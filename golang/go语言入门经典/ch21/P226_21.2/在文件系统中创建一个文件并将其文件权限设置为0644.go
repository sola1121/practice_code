package main

// 在go中使用unix的文件权限系统
// ---------- 字符表示共十位
// 0000 数字表示共三位

import (
	"io/ioutil"
	"log"
)

func main() {
	b := make([]byte, 0)                            // 写入的内容, 这里是空字节
	err := ioutil.WriteFile("example.log", b, 0644) // -rw-r--r--
	if err != nil {
		log.Fatal(err)
	}
}
