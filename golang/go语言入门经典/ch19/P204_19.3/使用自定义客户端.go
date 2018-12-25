package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func main() {
	client := &http.Client{}                                          // 使用http提供的默认的客户端
	request, err := http.NewRequest("GET", "http://ifconfig.co", nil) // 一个GET请求体
	if err != nil {
		log.Fatal(err)
	}

	response, err := client.Do(request) // 使用客户端发起请求并接收响应
	defer response.Body.Close()
	body, err := ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%s", body)
}
