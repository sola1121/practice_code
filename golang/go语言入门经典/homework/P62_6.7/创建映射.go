package main

import "fmt"

func main() {
	var mapObject = make(map[string]string)
	mapObject["p"] = "段落"
	mapObject["img"] = "图像"
	mapObject["h1"] = "一级标题"
	mapObject["h2"] = "二级标题"
	fmt.Println(mapObject)
}
