package main

import "fmt"

// карта (ассоциативный массив или словарь) - неупорядоченная коллекция пар вида ключ-значение
type Vertex struct {
	Lat, Long float64
}

// нулевое значение карты равно nil. Карта nil не имеет ключей и ключи не могут быть к ней добавлены
// функция make возвращает карту заданного типа, инициализированную и готовую к использованию
var m map[string]Vertex

func g() {
	m = make(map[string]Vertex)

	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}
	m["Labs"] = Vertex{
		401.68433, -174.39967,
	}

	fmt.Println(m["Bell Labs"])
	fmt.Println(m["Labs"])
}

func literal_map() {
	// для заполнения карты элементами используются литералы карты с указанием ключей.
	var m2 = map[string]Vertex{
		"Bell Labs": Vertex{
			40.68433, -74.39967,
		},
		"Google": Vertex{
			37.42202, -122.08408,
		},
	}
	// если тип верхнего уровня - это просто имя типа, то его можно опустить в элементах
	fmt.Println(m2)
	var m = map[string]Vertex{
		"Bell Labs": {40.68433, -74.39967},
		"Google":    {37.42202, -122.08408},
	}
	fmt.Println(m)

}

func main() {
	//literal_map()
	g()
}
