package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func helloWorld(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/" {
		http.NotFound(w, r)
		return
	}

	switch r.Method {
	// 处理GET请求
	case "GET":
		for k, v := range r.URL.Query() { // 读取URL中的请求数据
			fmt.Printf("%s: %s\n", k, v)
		}
		w.Write([]byte("Received a GET request.\n"))
	// 处理POST请求
	case "POST":
		reqBody, err := ioutil.ReadAll(r.Body) // 读取请求体中的请求数据
		if err != nil {
			log.Fatal(err)
		}

		fmt.Printf("%s\n", reqBody)
		w.Write([]byte("Received a POST request.\n"))
	default:
		w.WriteHeader(http.StatusNotImplemented)                    // 在响应头中添加501状态
		w.Write([]byte(http.StatusText(http.StatusNotImplemented))) // 将int类型的501转换为对应的描述并放入响应体中
	}
}

func main() {
	http.HandleFunc("/", helloWorld)
	fmt.Print("开始监听 http://127.0.0.1:8000 \n\n")
	http.ListenAndServe(":8000", nil)
}
