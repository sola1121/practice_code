package main

import "fmt"

type Game struct {
	Name        string
	ReleaseDate string
	Platform    string
}

type outer struct {
	aaa   int
	inner inner
}

type inner struct {
	bbb int
}

func main() {
	var game1 Game
	game1.Name = "游戏1"
	game1.Platform = "PC"
	game1.ReleaseDate = "2018-10-10"

	var game2 = new(Game)
	game2.Name = "游戏2"
	game2.Platform = "Phone"
	game2.ReleaseDate = "2018-8-23"

	game3 := Game{
		Name:        "游戏3",
		Platform:    "ps4",
		ReleaseDate: "2018-11-21",
	}

	fmt.Println(game1)
	fmt.Println(game2)
	fmt.Println(game3)

	println("----- struct的零值是什么, 内嵌的struct--------")

	x := outer{
		aaa: 111,
	}
	fmt.Println("没有声明inner", x)

	y := outer{
		aaa: 222,
		inner: inner{
			bbb: 333,
		},
	}
	fmt.Println("声明了内嵌的:", y)
}
