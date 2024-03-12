package main

import "fmt"

type phoneWriter struct{}

func (p phoneWriter) Write(bs []byte) (int, error) {
	// fmt.Println(p)
	// fmt.Println(bs)
	if len(bs) == 0 {
		return 0, nil
	}

	for i := 0; i < len(bs); i++ {
		if bs[i] >= '0' && bs[i] <= '9' {
			fmt.Println(string(bs[i]))
		}
	}
	return len(bs), nil
}

func main() {
	bytes1 := []byte("+1(234)567 8910")
	writer := phoneWriter{}
	writer.Write(bytes1)
}
