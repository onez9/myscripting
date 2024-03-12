package main

import "fmt"

func main() {

	c := make(chan int)
	quit := make(chan int)
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println(<-c)
		}
		quit <- 0
	}()

	fibonacci(c, quit)
}

// Оператор select позволяет горутине ожидать несколько операций комменикаций.
// select блокируетс до тех пор пока не запустится один из его case, затем он выполняет это case.
// Если готовы сразу несколько, то тогда для выполнения будет выбран любой случайным образом

func fibonacci(c, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case c <- x:
			x, y = y, x+y
			fmt.Println(x, y)
		case <-quit:
			fmt.Println("quit")
			return
			/*
				default: // блок default вызывается, если ни какой другой блок не готов
					// его можно использовать, чтобы получать и посылать данные без блокировок
					fmt.Println("Получение из c вызвало бы блокировку")

			*/
		}
	}
}
