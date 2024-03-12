package main

import "fmt"

func fibonacci(n int, c chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		c <- x
		x, y = y, x+y
		fmt.Println(x, y)

	}
	close(c)

}

// dunst !! не относится к теме это имя процесса который рабоает
// фиг знает зачем, но при нажатии сtrl+тильда происходит
// вывод уведомления от finger print defender
func main() {
	c := make(chan int, 10)
	go fibonacci(cap(c), c)
	for i := range c {
		// будет работать пока канал не закроют, закрывать канал должен только отправитьель
		fmt.Printf("чтение: %v", i)
	}

}
