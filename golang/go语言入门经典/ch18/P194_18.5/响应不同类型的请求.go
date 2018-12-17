package main

import (
	"fmt"
	"net/http"
)

func helloWorld(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/" {
		http.NotFound(w, r)
		return
	}
	fmt.Printf("request head\n%v", *r)

	switch r.Method {
	case "GET":
		w.Write([]byte("Recived a GET request\n"))
	case "POST":
		w.Write([]byte("Recived a POST request\n"))
	default:
		w.WriteHeader(http.StatusNotImplemented)
		w.Write([]byte(http.StatusText(http.StatusNotImplemented)))
	}
}

func main() {
	http.HandleFunc("/", helloWorld)
	err := http.ListenAndServe(":8000", nil)

	if err != nil {
		fmt.Println(err)
	}
}
