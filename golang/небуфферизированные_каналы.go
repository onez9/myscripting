package main

import "fmt"


func main() {
    intCh:=make(chan int)

    go func() {
        fmt.Println("Go runtine starts")
        intCh <- 5
        fmt.Println("Sended")
    }()


    /*
    func aaaa() {
        fmt.Println("Go runtine starts")
        intCh <- 5
        fmt.Println("Sended")
    }
    */

    // получение данных из канала
    fmt.Println(<-intCh)
    fmt.Println("The End")
    // Go runtine starts
    // Sended
    // 5
    // The End





}
