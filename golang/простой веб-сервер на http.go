package main

import (
	"fmt"
	"io"       // потоковое чтение и запись данных
	"net/http" // Для отправки сетевых запросов используется функция
)

// перед запуском выполнить: go mod init myapp
// затем: go get github.com/labstack/echo/v4

func getRoot(w http.ResponseWriter, r *http.Request) {
	io.WriteString(w, "Это мой сайт!\n")
}

func getHello(w http.ResponseWriter, r *http.Request) {
	io.WriteString(w, "Привет!\n")
}

func main() {
	http.HandleFunc("/", getRoot)
	http.HandleFunc("/hello", getHello) // обработка маршрутов

	err := http.ListenAndServe(":3333", nil) // создание и запуск веб-сервера

	if err != nil {
		fmt.Println(err)
	}

}
