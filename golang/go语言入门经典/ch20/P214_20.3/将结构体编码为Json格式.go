package main

import (
	"encoding/json"
	"fmt"
	"log"
)

type Person struct {
	Name    string
	Age     int
	Hobbies []string
}

func main() {
	hobbies := []string{"抽烟", "喝酒", "烫头"}
	p := Person{
		Name:    "二蛋",
		Age:     20,
		Hobbies: hobbies,
	}

	fmt.Printf("%+v\n", p)
	jsonByteData, err := json.Marshal(p)
	if err != nil {
		log.Fatal(err)
	}
	jsonStringData := string(jsonByteData)
	fmt.Println("Original bytes: \n", jsonByteData)
	fmt.Println("String format: \n", jsonStringData)
}
