package main

import (
	"fmt"
	"log"
	"time"
)

func main() {
	s1 := "2018-06-01T18:00:00+08:00"
	s2 := "2018-06-02T18:00:00+08:00"
	today, err := time.Parse(time.RFC3339, s1)
	if err != nil {
		log.Fatal(err)
	}
	tomorrow, err := time.Parse(time.RFC3339, s2)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("今天是在明天之前吗?", today.After(tomorrow))
	fmt.Println("今天是在明天之后吗?", today.Before(tomorrow))
	fmt.Println("今天和明天时同一天么?", today.Equal(tomorrow))
}
