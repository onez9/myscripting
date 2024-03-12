package main

import "fmt"

// String - это тип, который описывает себя как строку. Пакет fmt (и многие другие) ищет это интерфейс для вывода значений
/*
type Stringer interface {
	String() string
}
*/


type Person struct {
	Name string
	Age int
}

func (p Person) String() string {
	return fmt.Sprintf("%v (%v лет)", p.Name, p.Age)
}

func main() {
	a:=Person{"Иван Сидоров", 42}
	z:=Person{"Андрей Семенов", 9001}

	fmt.Println(a,z)


	
}
