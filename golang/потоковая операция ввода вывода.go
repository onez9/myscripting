//интерфейс io.Reader предназначен для считывания данных
/*
type Reader interface {
	Read(p []byte) (n int, err error)
}
*/

package main

import (
	"fmt"
	"io"
)

type phoneReader string

func (ph phoneReader) Read(p []byte) (int, error) {
	fmt.Println(ph)
	fmt.Println(p)
	count := 0
	for i := 0; i < len(ph); i++ {
		if ph[i] >= '0' && ph[i] <= '9' {
			p[count] = ph[i]
			count++
		}
	}
	return count, io.EOF
}

func main() {
	phone1 := phoneReader("+1(234)567 9010")
	buffer := make([]byte, len(phone1))
	phone1.Read(buffer)
	fmt.Println(string(buffer)) // 123456789010
}
