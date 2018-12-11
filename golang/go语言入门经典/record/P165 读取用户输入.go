package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)   // 读取系统标准输入流
	fmt.Print("Guess the name of my pet: ")
	text, _ := reader.ReadString('\n')   // 将缓冲中的数据转换为字符并获取
	text = strings.Replace(text, "\n", "", -1)

	if strings.ToLower(text) == "john" {
		fmt.Println("You won!")
	} else {
		fmt.Println("You got a wrong answer.")
	}
}
