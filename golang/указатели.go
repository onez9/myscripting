package main

import "fmt"

func main() {
	i:=12345

	p:=&i // указатель на i
	fmt.Println(*p) // прочитать i через указатель
	*p=21 // установить i через указатель
	fmt.Println(i) // просмотреть новое значение
}
