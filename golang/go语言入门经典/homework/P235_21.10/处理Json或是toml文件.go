package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"strings"

	"github.com/BurntSushi/toml"
)

var err error

// Pet 宠物的描述
type Pet struct {
	Category string  `json:"category"`
	Name     string  `json:"name"`
	Age      float64 `json:"age,omitempty"`
	Detail   PetDetail
}

// PetDetail 一些细节
type PetDetail struct {
	Feed   string  `json:"feed,omitempty"`
	Weight float64 `json:"weight,omitempty"`
}

func fileExist(filename string) bool {
	_, err = os.Stat(filename)
	return err == nil || os.IsExist(err)
}

func main() {
	mypet := Pet{
		Category: "cat",
		Name:     "Tom",
		Age:      2.0,
	}

	// 创建json文件
	jsonBytes, err := json.Marshal(mypet)
	if err != nil {
		log.Fatal(err)
	}
	jsonFile, _ := os.OpenFile("pet.json", os.O_CREATE|os.O_RDWR, 0644)
	defer jsonFile.Close()
	jsonFile.Write(jsonBytes)

	// 创建toml文件
	tomlFile, _ := os.OpenFile("pet.toml", os.O_CREATE|os.O_RDWR, 0644)
	defer tomlFile.Close()
	tomlEncoder := toml.NewEncoder(tomlFile)
	err = tomlEncoder.Encode(mypet)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("文件创建完毕")
	fmt.Print("输入c(to contine), 输入其他退出: ")
	input := bufio.NewReader(os.Stdin)
	inputText, err := input.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}
	inputText = strings.Replace(inputText, "\n", "", -1)
	if strings.ToLower(inputText) != "c" {
		// 处理残留并退出
		if fileExist("pet.json") {
			os.Remove("pet.json")
		}
		if fileExist("pet.toml") {
			os.Remove("pet.toml")
		}
		os.Exit(0)
	}
	fmt.Println("将开始读取创建的两个文件")

	// 读取json文件
	var (
		petDataShowJson Pet
		petDataShowToml Pet
	)
	readJson, _ := ioutil.ReadFile("pet.json")
	err = json.Unmarshal(readJson, &petDataShowJson)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("来自Json的数据: \n%+v\n\n", petDataShowJson)

	// 读取toml文件
	_, err = toml.DecodeFile("pet.toml", &petDataShowToml)
	fmt.Printf("来自Toml的数据: \n%+v\n", petDataShowToml)

	// 处理残留
	if fileExist("pet.json") {
		err = os.Remove("pet.json")
		if err == nil {
			fmt.Println("\n删除pet.json")
		}
	}

	if fileExist("pet.toml") {
		err = os.Remove("pet.toml")
		if err == nil {
			fmt.Println("\n删除pet.toml")
		}
	}
}
