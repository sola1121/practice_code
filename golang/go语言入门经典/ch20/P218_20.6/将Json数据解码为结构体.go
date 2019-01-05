package main

import (
	"encoding/json"
	"fmt"
	"log"
)

// Person 将会被解码的目标格式
// 这里的标签对应传递过来的json格式的键
type Person struct {
	Name    string   `json:"name"`
	Age     int      `json:"age"`
	Hobbies []string `json:"hobbies"`
}

func main() {
	jsonStringData := `{"name":"二孙子", "age":20, "hobbies":["抽烟","喝酒","烫头"]}`
	jsonByteData := []byte(jsonStringData)
	var p Person
	err := json.Unmarshal(jsonByteData, &p)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%+v\n", p)
}
