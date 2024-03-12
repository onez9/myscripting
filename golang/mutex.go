package main

import (
	"fmt"
	"sync"
)

// Общий ресурс
var counter int = 0

func main() {
	ch := make(chan bool) // Канал
	var mutex sync.Mutex  // Определяем mutex

	for i := 1; i < 5; i++ { // Одна и таже функция одновременно в 5 экземлярах работает с одой и той же переменной
		go work(i, ch, &mutex)
		fmt.Println("Запуск горутины номер: ", i)
	}

	for i := 1; i < 5; i++ {
		<-ch
		fmt.Println("Получили данные из канала: ", ch, ", попытка номер: ", i)
	}
	fmt.Println("The End")
}

func work_modified(number int, ch chan bool, mutex *sync.Mutex) {

	mutex.Lock()
	//counter = 0
	tmp := counter
	for k := 1; k <= 5; k++ {

		tmp++
		counter = tmp
		fmt.Println(number, " - ", counter)

	}
	// Деблокируем доступ
	mutex.Unlock()
	ch <- true
}

func work(number int, ch chan bool, mutex *sync.Mutex) {
	// Блокируем доступ к переменной counter

	// mutex.Lock()
	counter = 0
	for k := 1; k <= 5; k++ {
		counter++
		fmt.Println(number, " - ", counter)
	}
	// Деблокируем доступ
	// mutex.Unlock()
	ch <- true
}
