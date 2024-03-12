package main

import (
	"fmt"
	"time"
)



func f(from string) {
	for i:=0;i<3;i++ {
		fmt.Println(from, ":",i)
		
	}



}

func main() {
	go f("gorutine")
	f("direct")
	time.Sleep(time.Second)
	fmt.Println("done")
}




