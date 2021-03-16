package main

import "github.com/yerkortiz/programs"

func main() {
	//programs.Hello("world!")
	//fmt.Println(programs.EchoV1(os.Args))
	//fmt.Println(programs.EchoV2(os.Args[1:]))
	//fmt.Println(programs.EchoV3(os.Args[1:]))
	files := []string{"asdas.txt"}
	programs.Dup2(files)
}
