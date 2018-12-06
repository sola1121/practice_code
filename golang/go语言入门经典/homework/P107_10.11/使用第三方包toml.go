package main

import (
	"bytes"
	"fmt"
	"log"

	"github.com/BurntSushi/toml"
)

func main() {
	var anyThing *toml.Encoder

	var songs []map[string]string // map[string]interface{} 这样键后值就可以对应不同类型
	songs = []map[string]string{
		{"Name": "aaaaa", "Duration": "2m3s"},
		{"Name": "bbbbb", "Duration": "4m3s"},
		{"Name": "ccccc", "Duration": "3m0s"},
	}

	buf := new(bytes.Buffer) // 返回一块缓冲地址, 对应io.Write
	anyThing = toml.NewEncoder(buf)
	fmt.Printf("Indent: %v\n\n\n", anyThing.Indent)
	for _, song := range songs { // 每个song将会单个单个的加入同一块内存地址
		// When encoding TOML hashes (i.e., Go maps or structs), keys without any sub-hashes are encoded first.
		if err := toml.NewEncoder(buf).Encode(song); err != nil { // newEncoder -> *Encoder, func (e *Encoder) Encode(v interface{}) error
			log.Fatal(err)
		}
		fmt.Println(buf.String())
	}
}
