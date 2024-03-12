package main

import (
	"fmt"
	"io"
	"os"
)

func crf(name string) {
	file, err := os.Create(name)
	if err != nil {
		fmt.Println("Unable to createfile:", err)
		os.Exit(1) // Выходим из программы
	}

	defer file.Close()
}

func rf(name string) {
	file, err := os.Open(name)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	defer file.Close()
	data := make([]byte, 64)
	for {
		n, err := file.Read(data)
		if err == io.EOF {
			break
		}
		fmt.Println(string(data[:n]))
	}
}

func wf(name string) {
	text := "hello world"
	// data := []byte("hello world")
	file, err := os.OpenFile(name, os.O_APPEND|os.O_WRONLY, os.ModeAppend)
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	file.WriteString(text)
	// file.Write(data)
	fmt.Println("done")
	defer file.Close()
}

func main() {
	name := "file.txt"
	// crf(name)
	// wf(name)
	rf(name)
	//fmt.Println(file.Name()) //вывести имя файла
}
