package main

import "fmt"

var s string = "hello, programming god."   // 这样算是该文件中的全局变量了

func main() {
	fmt.Printf("从外部块中打印s的值 %v\n", s)

	var b bool = true
	if b {
		fmt.Printf("从外部块中打印b的值 %v\n", b)

		var i int = 2233
		if s != "" {
			fmt.Printf("从外部块中打印i的值 %v\n", i)			
		}
	}  
}