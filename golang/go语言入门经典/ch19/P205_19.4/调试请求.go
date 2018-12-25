package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"net/http/httputil"
	"os"
)

func main() {
	debug := os.Getenv("DEBUG")                                        // 获取环境中的DEBUG变量的值
	client := &http.Client{}                                           // 自定义客户端
	reuqest, err := http.NewRequest("GET", "https://ifconfig.co", nil) // 发起请求
	if err != nil {
		log.Fatal(err)
	}

	if debug == "1" {
		debugRequest, err := httputil.DumpRequestOut(reuqest, true) // 查看请求体
		if err != nil {
			log.Fatal(err)
		}
		fmt.Printf("请求体:\n%s\n", debugRequest)
	}

	response, err := client.Do(reuqest)
	defer response.Body.Close()

	if debug == "1" {
		debugRespose, err := httputil.DumpResponse(response, true) // 查看响应体
		if err != nil {
			log.Fatal(err)
		}
		fmt.Printf("响应体:\n%s\n", debugRespose)
	}
	body, err := ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%s\n", body)
}
