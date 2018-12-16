package main

import (
	"net/http"
)

func helloWorld(w http.ResponseWriter, r *http.Request) {
	// 检查request的url是否是/ , 如果不是, 将会返回404状态
	if r.URL.Path != "/" {
		http.NotFound(w, r)
		return
	}
	w.Write([]byte("Hello, world.\n"))
}

func main() {
	http.HandleFunc("/", helloWorld)
	http.ListenAndServe("8000", nil)
}
