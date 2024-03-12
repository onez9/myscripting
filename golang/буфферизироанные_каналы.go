package main

import "fmt"

func main() {
    intCh:=make(chan int, 4)

    intCh<-10
    intCh<-3
    intCh<-44
    intCh<-45

    fmt.Println(<-intCh)
    fmt.Println(<-intCh)
    fmt.Println(<-intCh)
    fmt.Println(123)
    fmt.Println(<-intCh)

}
