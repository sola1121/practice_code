package main

import (
	"fmt"
	"time"
)

func main() {
	now := time.Now()
	christmas := time.Date(now.Year(), 12, 25, 0, 0, 0, 0, time.Local)
	newYear := time.Date(now.Year()+1, 1, 1, 0, 0, 0, 0, time.Local)

	fmt.Println("圣诞节后还有多少天就是新年了: ", (newYear.Sub(christmas)).Hours()/float64(24.0))

	intervalHours := "1600h"
	intervalDuration, _ := time.ParseDuration(intervalHours)
	fmt.Println("圣诞节后", intervalHours, "将会是", christmas.Add(intervalDuration))

	myBirth := time.Date(1995, 4, 30, 3, 15, 0, 0, time.Local)
	lived := myBirth.Sub(now)
	fmt.Println("大概过了多少年", lived.Hours()/float64(24.0*365.0))
}
