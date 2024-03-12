package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
	"time"
)

func main() {
	client := http.Client{ // структура http.Client
		Timeout: 6 * time.Second, // устанавливает timeout для запроса
		// Jar: , устанавливает куки отправляемые в запросе
		// Tramsport: , определяет механизм выполнения запроса
	}
	resp, err := client.Get("https://google.com")
	if err != nil {
		fmt.Println(err)
		return
	}

	//fmt.Println(resp) // выведет не всё
	io.Copy(os.Stdout, resp.Body) // потоковая запись в Stdout
	defer resp.Body.Close()       // В любом случае выполнится последним

}
