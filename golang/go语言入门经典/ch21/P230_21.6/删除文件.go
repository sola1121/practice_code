package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"time"
)

func main() {
	var err error
	var bytesData []byte
	var filename string
	filename = "example_to_remove.log"

	err = ioutil.WriteFile(filename, bytesData, 0664)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("5s...")
	time.Sleep(5 * time.Second)

	// 删除文件
	err = os.Remove(filename)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("Done.")
}
