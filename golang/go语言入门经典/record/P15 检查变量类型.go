package main

import (
	"fmt"
	"reflect"   // go标准库中提供的可以访问类型的底层包
)

func main(){
	var s string = "这是一个字符串"
	var i int = 2233
	var f float32 = 22.33

	fmt.Println(reflect.TypeOf(s))
	fmt.Println(reflect.TypeOf(i))
	fmt.Println(reflect.TypeOf(f))
}