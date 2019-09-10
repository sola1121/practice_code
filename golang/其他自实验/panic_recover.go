package main

func main() {
	defer func() {
		println("覆盖恐慌, 正常回收.")
		recover()
	}()
	panic("引发恐慌")
}
