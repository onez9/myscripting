package main

import (
	"fmt"
)

var numbers = []int{5, 7, 9, 11, 13, 15, 17, 19}

func ex1() {
	for i, v := range numbers {
		// i - индекс
		// v - копия элемента по этому индуксу
		fmt.Printf("%d, %d\n", i, v)
	}

}

func ex2() {
	// пример range для карты вместо индекса возвращается ключ
	m := map[string]int{
		"a": 10,
		"b": 20,
		"c": 30}
	fmt.Println("Ключи, значения")
	for k, v := range m {
		fmt.Printf("%s, %d\n", k, v)
	}

}

func ex3() {
	fmt.Println("Значения:")
	for k, v := range numbers {
		fmt.Println(k, v)
	}

	fmt.Println("Ключи")
	for k, _ := range numbers {
		fmt.Println(k)
	}

	fmt.Println("Ключи")
	for k := range numbers {
		fmt.Println(k)
	}

}

func main() {
	//ex1()
	//ex2()
	ex3()
}
