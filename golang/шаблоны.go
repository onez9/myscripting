package main

import "fmt"

func index[T comparable](s []T, x T) int {
	for i, v := range s {
		if v == x {
			return i
		}
	}
	return -1
}

func main() {
	si := []int{10, 20, 30, 15, -10}
	fmt.Println(index(si, 15))

	ss := []string{"foo", "bar", "baz"}
	fmt.Println(index(ss, "foo"))
}
