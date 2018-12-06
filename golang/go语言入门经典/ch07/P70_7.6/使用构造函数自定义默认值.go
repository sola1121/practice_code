package main

import (
	"fmt"
)

type Alarm struct {
	Time  string
	Sound bool
}

func NewAlarm(time string) Alarm {
	createdAlarm := Alarm{
		Time:  time,
		Sound: true,
	}
	return createdAlarm
}

func main() {
	fmt.Printf("%+v\n", NewAlarm("8:00"))
}
