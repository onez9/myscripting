package main

import "fmt"

type Person struct {
	Name, Surname string
}

// Метод - это функция со специальным аргументом получателя
// (p Person) - получатель

// Методы обычных получателей работают с копией исходного значения
func (p Person) FullName() string {

	return p.Name + " " + p.Surname
}

// также можно объявить метод для типов не являющихся структурами
// можно объявить метод только с получателем , тип которого определен в том же пакете что и метод

type MyFloat float64

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func t1() {
	p := Person{"Иван", "Петров"}
	fmt.Println(p.FullName())
}
func t2() {
	f := MyFloat(-10.5)
	fmt.Println(f.Abs())
}
func main() {
	t2()

}
