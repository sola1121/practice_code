package main

import (
	"fmt"
)

func main() {
	var players = make(map[string]int)

	players["value1"] = 111
	players["value2"] = 222
	players["value3"] = 333
	var players_backup = make(map[string]int)
	players_backup = players

	fmt.Println("原先的players映射: ", players)
	delete(players, "value2")
	fmt.Println("删除了value2的players映射: ", players)
	fmt.Println("查看长度, 是否支持: ", len(players))
	fmt.Println("值传递还是引用: ", players_backup) // 直接引用了players
}
