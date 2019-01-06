package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
)

type Config struct {
	Name   string `json:"name"`
	Awake  bool   `json:"awake"`
	Hungry bool   `json:"hungry"`
}

func main() {
	var err error

	file, err := ioutil.ReadFile("config.json")
	if err != nil {
		log.Fatal(err)
	}

	config := Config{}

	err = json.Unmarshal(file, &config)
	if err != nil {
		log.Fatal()
	}
	fmt.Printf("%+v\n", config)
}
