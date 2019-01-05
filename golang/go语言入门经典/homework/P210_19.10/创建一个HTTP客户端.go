package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"net/http/httputil"
	"time"
)

func doRequest(ch *chan []byte, client http.Client, req *http.Request) {
	reqContent, err := httputil.DumpRequestOut(req, true)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%s\n", reqContent)
	res, err := client.Do(req)
	defer res.Body.Close()
	if err != nil {
		log.Fatal(err)
	}
	body, err := ioutil.ReadAll(res.Body)
	if err != nil {
		log.Fatal(err)
	}
	ch <- body
}

func main() {
	ch := make(chan []byte, 3)

	// 创建一个客户端
	client := http.Client{
		Timeout: 20 * time.Second,
	}

	req1, _ := http.NewRequest("GET", "https://google.com/404", nil)
	req2, _ := http.NewRequest("POST", "https://httpbin.org/post", nil)
	req3, _ := http.NewRequest("GET", "https://httpbin.org/user-agent", nil)
	req3.Header.Set("User-Agent", "Golangbot")

	go doRequest(&ch, client, req1)
	go doRequest(&ch, client, req2)
	go doRequest(&ch, client, req3)

	for {
		select {
		case msg := <-ch:
			fmt.Printf("%s\n==================\n", msg)
		case <-time.After(30 * time.Second):
			break
		}
	}
}
