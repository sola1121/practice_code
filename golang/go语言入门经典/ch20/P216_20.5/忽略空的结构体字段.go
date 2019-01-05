package main

import (
	"encoding/json"
	"fmt"
	"log"
)

// Person 指定忽略空标签
type Person struct {
	Name    string   `json:"name,omitempty"`
	Age     int      `json:"age,omitempty"`
	Hobbies []string `json:"hobbies,omitempty"`
}

func main() {
	hobbies := []string{"抽烟", "喝酒", "烫头"}
	p := Person{
		Name: "二傻子",
		// 将会对零值进行忽略
		// Age:     20,
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
