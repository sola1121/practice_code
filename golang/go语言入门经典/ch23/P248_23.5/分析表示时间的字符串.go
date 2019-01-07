package main

import (
	"fmt"
	"log"
	"time"
)

func main() {
	s := "2006-01-02T15:04:05+08:00" // RFC3339格式的时间字符串
	t, err := time.Parse(time.RFC3339, s)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(t)
}
