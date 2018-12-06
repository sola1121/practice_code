package main

import (
	"fmt"
	"strings"
)

func main() {
	// 转换小写
	fmt.Println(strings.ToLower("JUST A MESAGE."))

	// 在字符串中查找子串
	fmt.Println(strings.Index("surface", "face"))
	fmt.Println(strings.Index("moon", "aer"))

	// 删除字符串中的空格
	fmt.Println(strings.TrimSpace(" I don't need all this space. ")) // 将会将前后两个空格删除
}
