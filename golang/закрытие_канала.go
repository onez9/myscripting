package main

import "fmt"

func main() {
    intCh:=make(chan int,3)
    intCh<-3
    intCh<-4

    close(intCh) // канал закрыт
    intCh<-5

    // но данные из канала мы можем получить, а вот записать нет
    for i:=0;i<cap(intCh);i++{
        // тут осуществляется проверка закрытости канала
        if val,opened:=<-intCh;opened{
            // первое значение это собственно данные из канала, а второе это код ошибки(false or true)
            fmt.Println(val)

        }else{
            fmt.Println("Канал закрыт!")
        }
    }
}
