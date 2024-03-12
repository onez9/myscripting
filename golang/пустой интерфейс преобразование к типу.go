package main

import "fmt"


func main() {
	var i interface{} = "Hello"

	s:=i.(string)
	fmt.Println(s) //hello

	s,ok:=i.(string) //hello true
	fmt.Println(s,ok)

	f,ok:=i.(float64) 
	fmt.Println(f,ok) //0 false
	
	//f=i.(float64) //panic
	//fmt.Println(f)
	


	
}
