package main

import (
	"encoding/json"
	"fmt"
	"log"
)

// Person 结构体添加上标签, 这样在json编码时就会使用标签上的字串作为键
type Person struct {
	Name    string   `json:"name"`
	Age     int      `json:"age"`
	Hobbies []string `json:"hobbies"`
}

func main() {
	hobbies := []string{"抽烟", "喝酒", "烫头"}
	p := Person{
		Name:    "二愣子",
		Age:     20,
		Hobbies: hobbies,
	}

	fmt.Printf("%+v\n", p)
	jsonByteData, err := json.Marshal(p)
	if err != nil {
		log.Fatal(err)
	}

	jsonStringData := string(jsonByteData)
	fmt.Println(jsonStringData)
}
