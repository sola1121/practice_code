package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func doSomething(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/" {
		http.NotFound(w, r)
		return
	}

	switch r.Method {
	case "GET":
		for k, v := range r.URL.Query() {
			fmt.Printf("%s : %s", k, v)
		}
		w.Header().Set("Content-Type", "text/html")
		index_file, err := ioutil.ReadFile("index.html")
		if err != nil {
			http.NotFound(w, r)
			return
		}
		w.Write(index_file)
	case "POST":
		req_body, err := ioutil.ReadAll(r.Body)
		if err != nil {
			w.WriteHeader(http.StatusNotImplemented)
			w.Write([]byte(http.StatusText(http.StatusNotImplemented)))
		}
		fmt.Println("Recived a POST request.")
		w.Write([]byte(req_body))
	case "DELETE":
		fmt.Println("Recived a DELETE request.")
		fmt.Println(r.Body)
	default:
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte(http.StatusText(http.StatusBadRequest)))
	}
}

func main() {
	http.HandleFunc("/", doSomething)
	fmt.Print("开始监听 http://127.0.0.1:8000\n\n")
	http.ListenAndServe(":8000", nil)
}
