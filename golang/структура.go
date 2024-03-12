package main

import "fmt"

type Circle struct {
	x float64
	y float64
	r float64
}


func main() {
	c:=Circle{}
	fmt.Println(c.x,c.y,c.r)
	c.x=10
	c.y=5


	//worked
	//cm:=new(Circle) // выделит память для всех полей, присвоит каждому из нулевое значение и вернёт указатель (*circle)

	// инициализация структуры
	cm1:=Circle{x:0,y:0,r:5}
	fmt.Println("x", cm1.x, "y",cm1.y,"r",cm1.y)
	// можно ещё вот так
	cm2:=Circle{0,0,5}
	fmt.Printf("%v %v %v\n", cm2.x,cm2.y,cm2.r)





}
