package main

import "fmt"

func main() {
	m := make(map[string]int)
	m["Answer"] = 42
	fmt.Println(m["Answer"])

	m["Answer"] = 48
	fmt.Println(m["Answer"])

	delete(m, "Answer")
	fmt.Println(m["Answer"])

	v, ok := m["Answer"]
	// Если ключ находится в m, ok получит true. Если нет, ok получит false.
	fmt.Println(v, ok)

}
