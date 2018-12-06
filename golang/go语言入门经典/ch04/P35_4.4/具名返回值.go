package main

import "fmt"


func saySomething(word1, word2 string) (new_word1, new_word2 string){
	new_word1 = word1 + "_这是new_word1"
	new_word2 = word2 + "_这是new_word2"
	return 
}


func main() {
	value1, value2 := saySomething("hello", "world")
	fmt.Println(value1, "\n", value2)
}