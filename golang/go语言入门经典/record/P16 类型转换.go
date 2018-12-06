package main

import (
	"fmt"
	"strconv"   // 用于转换字符串或将字符串转换为其他类型
	"reflect"
)

func main(){
	var b bool = true
	fmt.Println("b的类型是: ", reflect.TypeOf(b))
	var s string = strconv.FormatBool(true)
	fmt.Println("字符是的类型是", reflect.TypeOf(s), "  值为", s)
}