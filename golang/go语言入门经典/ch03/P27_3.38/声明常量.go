package main

import (
	"fmt"
	"reflect"
)

const greeting string = "一旦初始化后的常量可以引用但就是不能修改"

func main() {
	fmt.Print(reflect.TypeOf(greeting), greeting, "\n")
}