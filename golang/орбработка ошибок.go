package main


import (
	"fmt"
	"strconv"
	"errors"

)

func process(count int) error {
	if count < 1 {
		// также мы можем создать свою собственную ошибку с помощью пакета errors и вызова функции New
		return errors.New("Invalid count")
		// это общепринятый метод использования переменных ошибок в стандарте go
	}
	return nil


}



func main() {
	i,err:=strconv.Atoi("42")
	if  err!=nil {
		fmt.Printf("Ошибка: %v\n", err)
		return
	}

	fmt.Println("Преобразованное число: ", i)

	i,err=strconv.Atoi("44")
	if  err!=nil {
		fmt.Printf("Ошибка: %v\n", err)
		return
	}
	fmt.Println("Преобразованное число: ", i)
	
	// также мы можем создать свою ошибку и вызова функции New
	err2:=process(0)
	if err!=nil{
		fmt.Println("Ошибка: %v\n", err2)
	}
	fmt.Println(err2)
	// Ошибка: Invalid count
	
}
