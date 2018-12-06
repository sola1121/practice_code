package main

import (
	"fmt"
)

type Triangle struct {
	base   float64
	height float64
}

func (t Triangle) changeBase(f float64) { // 使用的是值引用改变结构体的值, 而这样根本改变不了关联的结构体的值
	t.base = f
	return
}

func main() {
	t := Triangle{base: 3, height: 1}
	t.changeBase(4)
	fmt.Println(t.base)
}
