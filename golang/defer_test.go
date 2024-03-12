package main

import "fmt"

func main() {
	defer fmt.Println("World") // отложенные вызовы функции помещаются в стек

	fmt.Println("hello")
	
}
