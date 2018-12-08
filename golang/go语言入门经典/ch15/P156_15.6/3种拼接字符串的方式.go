package ex

import (
	"bytes"
	"strings"
)

// stringFromAssignment 通过赋值的方式进行字符串拼接
func stringFormAssignment(j int) string {
	var s string
	for i := 0; i < j; i++ {
		s += "a"
	}
	return s
}

// stringFromAppendJoin 通过切片的扩展append和使用切片的拼接strings.Join来对字符串拼接
func stringFromAppendJoin(j int) string {
	s := []string{} // s := []rune{}
	for i := 0; i < j; i++ {
		s = append(s, "a")
	}
	return strings.Join(s, "")
}

// stringFromBuffer 使用缓冲区对字符串进行拼接
func stringFromBuffer(j int) string {
	var buffer bytes.Buffer
	for i := 0; i < j; i++ {
		buffer.WriteString("a")
	}
	return buffer.String()
}
