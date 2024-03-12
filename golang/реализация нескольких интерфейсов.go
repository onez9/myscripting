package main

import "fmt"
type Reader interface {
	read()
}

type Writer interface {
	write(string)
}

func writeToStream(writer Writer, text string) {
	writer.write(text)
}

func readFromStream(reader Reader) {
	reader.read()
}

type File struct{
	text string
}

func (f *File) read() {
	fmt.Println(f.text)
}

func (f *File) write(msg string) {
	f.text = msg
	fmt.Println("Запись в файл", msg)
}

func main() {
	myFile:=&File{}
	writeToStream(myFile, "Hello World")
	readFromStream(myFile)
}





