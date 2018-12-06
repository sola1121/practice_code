package main

import(
	"fmt"
	"strconv"
	"reflect"
)


func main(){
	var a int = 2233
	var b string = "3322"

	fmt.Println("TypeOf(a)", reflect.TypeOf(a), a)
	var x1 string = strconv.FormatInt(int64(a), 10)
	x2 := strconv.Itoa(a)
	fmt.Println("TypeOf(x1)", reflect.TypeOf(x1), x1)
	fmt.Println("TypeOf(x2)", reflect.TypeOf(x2), x2)

	fmt.Println("TypeOf(b)", reflect.TypeOf(b), b)
	y1, err := strconv.ParseInt(b, 10, 64)
	if err != nil {
		panic(err)
	}
	y2, err := strconv.Atoi(b)
	fmt.Println("TypeOf(y1)", reflect.TypeOf(y1), y1)
	fmt.Println("TypeOf(y2)", reflect.TypeOf(y2), y2)

	var z float32 = 3.1415
	var z_ = int32(z)
	fmt.Println("浮点与整数见转换", z, " --> ", z_)

}
