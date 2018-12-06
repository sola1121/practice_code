package main

import (
	"fmt"
	"strings"
)

type pkgStr struct {
	str string
}

func (ps pkgStr) getUpperStr() string {
	return strings.ToUpper(ps.str)
}

func (ps pkgStr) replaceToBar(s string) string {
	return strings.Replace(ps.str, s, "bar", -1)
}

func (ps pkgStr) findWord(s string) int {
	return strings.Index(ps.str, s)
}

func main() {
	theStr := pkgStr{str: "Oh I do like to be beside the seaside"}
	fmt.Println(theStr.getUpperStr())
	fmt.Println(theStr.replaceToBar("seaside"))
	fmt.Println(theStr.findWord("the"))
}
