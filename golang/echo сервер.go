package main

import (
	"net/http"

	"github.com/labstack/echo"
)

func main() {

	e := echo.New() // создан экземпляр Echo с помощью функции echo.New()
	e.GET("/", func(c echo.Context) error {
		return c.String(http.StatusOK, "Hello, World") // пределяется единственный маршрут (“/”)
		//для метода GET, для которого указывается обработчик, который просто отправляет строку “Hello,
		//World!” со статусом 200 (http.StatusOK).
	})
	e.Logger.Fatal(e.Start(":5555"))

}
