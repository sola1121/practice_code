package main

import (
	"fmt"
)


func sumNums(nums...int) (int, int) {
	var count int = 0
	var total int = 0

	for _, num := range nums {
		total += num
		count ++
	}
	return count, total
}


func main() {
	count, result := sumNums(1, 2, 3, 4, 5, 6)
	fmt.Printf("一共有%v个数相加, 结果为%v\n", count, result)
}