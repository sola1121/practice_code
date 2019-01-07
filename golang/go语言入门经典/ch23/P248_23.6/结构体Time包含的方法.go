package main

import (
	"fmt"
	"log"
	"reflect"
	"time"
)

func printTime(t time.Time) {
	fmt.Print("\n\n")
	fmt.Println("显示小时", t.Hour(), reflect.TypeOf(t.Hour()))
	fmt.Println("显示分钟", t.Minute(), reflect.TypeOf(t.Minute()))
	fmt.Println("显示秒", t.Second(), reflect.TypeOf(t.Second()))
	fmt.Println("显示日期", t.Day(), reflect.TypeOf(t.Day()))
	fmt.Println("显示月份", t.Month(), reflect.TypeOf(t.Month()))
	fmt.Println("显示UNIX时间", t.Unix(), reflect.TypeOf(t.Unix()))
	fmt.Println("显示星期", t.Weekday(), reflect.TypeOf(t.Weekday()))
	fmt.Print("\n")
}

func main() {
	s := "2014-09-01T15:04:05+08:00"
	t, err := time.Parse(time.RFC3339, s)
	if err != nil {
		log.Fatal(err)
	}
	printTime(t)

	t = t.AddDate(0, 1, 0)
	printTime(t)

	t.Sub(time.Date(0, 2, 0, 0, 0, 0, 0, time.Local))
	printTime(t)
}
