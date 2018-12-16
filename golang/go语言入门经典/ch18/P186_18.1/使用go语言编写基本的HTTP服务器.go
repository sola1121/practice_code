package main

import (
	"fmt"
	"net/http"
)

// 符合接口标准的响应函数
func helloWorld(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Request Header: \n", *r)
	w.Write([]byte("Hello, World.\n"))
}

func main() {
	// 路由器
	http.HandleFunc("/", helloWorld)
	// 监听服务器
	http.ListenAndServe(":8000", nil)
}
