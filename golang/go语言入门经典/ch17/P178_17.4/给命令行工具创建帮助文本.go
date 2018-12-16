package main

import (
	"flag"
	"fmt"
	"os"
)

func main() {
	flag.Usage = func() {
		UsageText := `
			Here to show some help text.
			using original string.
		`
		// 使用错误流输出信息
		fmt.Fprintf(os.Stderr, "%s\n", UsageText) // 将会重新对标准的错误输出进行新的定义形式
	}
	s := flag.String("s", "hello,world", "String help text")
	i := flag.Int("i", 1, "Int help text.")
	b := flag.Bool("b", false, "Bool help text.")
	flag.Parse()
	fmt.Println("value of s: ", s)
	fmt.Println("value of i: ", i)
	fmt.Println("value of b: ", b)
}
