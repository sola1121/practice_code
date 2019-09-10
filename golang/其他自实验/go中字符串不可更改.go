package main

import "fmt"

var value int

func main() {
	s := "Aa你"
	fmt.Println("字符串长度为: ", len(s))
	for i := 0; i < len(s); i++ {
		fmt.Println("字符中", s[i])
	}

	s = "更改字符将会出错" // 使用:=将会出错
	t := s
	t += s
	fmt.Println("t的值", t, "   s的值", s)
	// s[0] := 'L'   // 这明显是不行的
	fmt.Println("尝试更改s中某个值", s)
}
