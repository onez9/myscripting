package main
import "fmt"

type Vertex struct{
    X,Y float64
}

func scale1(v Vertex, f float64) {
    v.X=v.X*f
    v.Y=v.Y*f
}

func scale2(v *Vertex, f float64) {
    v.X=v.X*f
    v.Y=v.Y*f
}


func main() {
    v1:=Vertex{1,1}
    scale1(v1,10)
    fmt.Println(v1)

    v2:=&Vertex{1,1}
    scale2(v2,10)
    fmt.Println(v2)

}
