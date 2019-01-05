package main

import (
	"encoding/json"
	"fmt"
	"log"
)

// Switch 验证json中bool与go中对应的bool
type Switch struct {
	On bool `json:"on"`
}

func main() {
	jsonStringData := `{"on":"false"}` // 这里使用的不是bool类型的表示, 而是一个字符串, 会出错.
	jsonByteData := []byte(jsonStringData)
	s := Switch{}
	err := json.Unmarshal(jsonByteData, s)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("%+v\n", s)
}
