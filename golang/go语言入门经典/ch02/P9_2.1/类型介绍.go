package main

import (
	"fmt"
)

func saySomething(s string) string{
	return "You had told me " + s 
}

func main(){
	fmt.Println(saySomething("好好学习, 天天向上. /a"))
}
