package main

import "fmt"

// пустые интефейсы используются, когда обрабатываются значения неизвестного типа.
// Например fmt.Println принимает любое количество аргументов типа interface{}



func main() {
	var i interface{}
	describe(i) //(<nil>,<nil>)
	i=42
	describe(i) // (42, int)
	i="Hello"
	describe(i) //(hello, string)



}
func describe(i interface{}){
	fmt.Println("(%v, %T)\n", i, i)
}
