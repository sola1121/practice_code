package main

import (
	"fmt"
)

type taxi interface {
	IsNull() bool
	PeopleNum() int
	IsRuning() bool
}

type working_taxi struct {
	people  int
	running bool
}

func (wt *working_taxi) IsNull() bool {
	if wt.people == 0 {
		return true
	} else if wt.people > 0 {
		return false
	} else {
		panic("人数为负数.")
	}
}

func (wt *working_taxi) PeopleNum() int {
	return wt.people
}

func (wt *working_taxi) IsRuning() bool {
	return wt.running
}

func getTaxiInfo(t taxi) {
	fmt.Println("出租车是否为空: ", t.IsNull())
	if !t.IsNull() {
		fmt.Println("出租车现有人数: ", t.PeopleNum())
	}
	fmt.Println("出租车运行状态: ", t.IsRuning())
}

func main() {
	wt := working_taxi{people: 12, running: true}
	getTaxiInfo(&wt)
}
