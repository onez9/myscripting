package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	fmt.Println("Hello every body!")
	var wg sync.WaitGroup
	wg.Add(10)
	work := func(id int) {
		defer wg.Done()
		fmt.Printf("Горутина %d начало \n", id)
		time.Sleep(2 * time.Second) // waitGroup очень похоже на барьеры в python и других языках программирования
		fmt.Printf("Горутина %d окончание \n", id)
	}

	// Вызываем горутины
	for i := 0; i < 10; i++ {
		go work(i)
	}
	wg.Wait() // Ожидаем завершения обоих горутин // В потоках питона такое же есть
	// time.Sleep(4 * time.Second)
	fmt.Println("Горутины завершили выполнение")

}
