package main

import "fmt"

func do(i interface{}) {
	switch v:=i.(type) {
		case int:
		fmt.Printf("Это число %v\n", v)
		case string:
		fmt.Printf("Это строка %q\n", v)
		default:
		fmt.Printf("Неизвестный тип данных %T!\n", v)
		
	}



}


func main() {
	// переключатели типа - это конструкция, которая используется для последовательной проверки нескольких типов
	// данных для значения интерфейса
	do(21)
	do("hello")
	do(true)
	
}
