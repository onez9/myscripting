package main

import "fmt"

type Vehicles interface {
	move()
}
// структура "Автомобиль"
type Car struct{}

// структура самолёт
type Aircraft struct{}

func (c Car) move() {
	fmt.Println("Автомобиль едет")
}

func (a Aircraft) move() {
	fmt.Println("Самолёт летит")
}
// в го интерфес реализуется неявно
// чтобы интерфейс соответствовал интерфейсу, он должен реализовывать все методы этого интерфейса
func main() {
	//var tesla Vehicles = Car{}
	//var boing Vehicles = Aircraft{}
	//var tesla1 = Car{}
	//var boing1 = Aircraft{}

	var tesla1 Car = Car{}
	var boing1 Aircraft = Aircraft{}


	tesla1.move()
	boing1.move()
}
