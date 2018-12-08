package main

import (
	"log"
	"os"
)

func main() {
	// 调用系统的文件io
	f, err := os.OpenFile("logFile.log", os.O_APPEND|os.O_CREATE|os.O_RDWR, 0666)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	log.SetOutput(f) // 设置log输出

	for i := 1; i <= 10000000; i++ {
		if i%1000000 == 0 {
			log.Printf("Log iteration %d", i)
		}
	}
}
