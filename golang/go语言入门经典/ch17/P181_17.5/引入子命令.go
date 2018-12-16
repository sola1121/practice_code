package main

import (
	"flag"
	"fmt"
	"os"
	"strings"
)

func flagUsage() {
	usageText := `cli tool help message
to wirte some helpful information.
	`
	// 使用错误流输出信息
	fmt.Fprintf(os.Stderr, "%s\n\n", usageText)
}

func main() {
	// 重新定义flag.Usage方法
	flag.Usage = flagUsage
	// 创建两个新的子命令
	uppercaseCmd := flag.NewFlagSet("upper", flag.ExitOnError)
	lowercaseCmd := flag.NewFlagSet("lower", flag.ExitOnError)

	// 没有的参数的时候将输出flag.Usage
	if len(os.Args) == 1 {
		flag.Usage()
		return
	}

	switch os.Args[1] {
	case "uppercase":
		s := uppercaseCmd.String("s", "", "A string of text to be uppercased")
		uppercaseCmd.Parse(os.Args[2:])
		fmt.Println(strings.ToUpper(*s))
	case "lowercase":
		s := lowercaseCmd.String("s", "", "A string of text to be lowercased")
		lowercaseCmd.Parse(os.Args[2:])
		fmt.Println(strings.ToLower(*s))
	default:
		flag.Usage()
	}
}
