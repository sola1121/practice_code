package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
)

type User struct {
	Name string `json:"name"`
	Blog string `json:"blog"`
}

/*
1. 获取网页返回
2. 使用json.NewDecoder(r io.Reader) *Decoder 将获取到的Json格式响应的解码实例
3. 在使用Decoder解码自身, 获得解码流后的解码实例
*/

func main() {
	var u User
	res, err := http.Get("https://api.github.com/users/shapeshed")
	if err != nil {
		log.Fatal(err)
	}

	defer res.Body.Close()
	err = json.NewDecoder(res.Body).Decode(&u)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("%+v\n", u)
}
