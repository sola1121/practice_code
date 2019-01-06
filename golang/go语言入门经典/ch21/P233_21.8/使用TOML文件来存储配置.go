package main

import (
	"fmt"
	"log"
	"os"
	"time"

	"github.com/BurntSushi/toml"
)

type Config struct {
	Name   string
	Awake  bool
	Hungry bool
}

var err error

func main() {
	config := Config{
		Name:   "leimilia",
		Awake:  true,
		Hungry: false,
	}

	file, err := os.OpenFile("example.toml", os.O_CREATE|os.O_RDWR, 0644)
	if err != nil {
		log.Fatal(err)
	}
	// 新建一个toml文件
	encodeFile := toml.NewEncoder(file)
	err = encodeFile.Encode(config)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("60s...")
	time.Sleep(60 * time.Second)

	// 读取toml文件
	config = Config{}
	metaData, err := toml.DecodeFile("example.toml", &config)
	fmt.Printf("读取到的新建文件\n原始:\n%v\n\n结构\n%+v\n", metaData, config)

	// 最后删除文件
	err = os.Remove("example.toml")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Done.")
}
