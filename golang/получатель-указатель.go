package main

import "fmt"

type Vertex struct {
    X,Y float64
}


// так изменяет значения членов структуры
func (v Vertex) Scale1(f float64) {
    v.X=v.X*f;
    v.Y=v.Y*f;

}

// а так нет
func (v *Vertex) Scale(f float64) {
    v.X=v.X*f;
    v.Y=v.Y*f;

}

func main() {
    v:=Vertex{1,1}
    v.Scale(10)
    fmt.Println(v.X)
}
