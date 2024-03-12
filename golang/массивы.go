package main

import "fmt"


func main() {
	var a [2]string // длина массива является частью его типа, поэтому размер массива нельзя изменять


	a[0]="Hello"
	a[1]="World"
	fmt.Println(a[0],a[1])
	fmt.Println(a)
	primes:=[6]int{2,3,5,7,11,13}
	fmt.Println("Массив primes: ", primes)


	// срезы
	var s []int=primes[1:4]
	fmt.Println("Срезы массива primes: ", s)



	// Срезы как ссылки на массивы
	letters:=[4]string{
		"A",
		"B",
		"C",
		"D",
	}
	fmt.Println(letters)

	a1:=letters[0:2]
	b1:=letters[1:3]
	fmt.Println(a1,b1)

	b1[0]="XXX" // при изменении элемента среза изменится и соответствующие элементы массива
	fmt.Println(a1,b1)
	fmt.Println(letters)


	// литералы среза. Литерал среза похож на литерал массива но без длины.
	q:=[]int{2,3,5,7,11,13}
	fmt.Println(q)
	// создает тот же массив, что и выше, а затем создает срез, который ссылается на него:
	r:=[]bool{true,false,true,true,false,true} 
	fmt.Println(r)
	//отрицательные индексы среза не поддерживаются
	s1:=[]int{2,3,5,7,11,13}
	f1:=s1[1:4]
	fmt.Println(f1)

	f2:=s1[:2]
	fmt.Println(f2)

	f3:=s1[4:]
	fmt.Println(f3)


	//срез: длина и ёмкость
	/*
	длина среза - это количество элементов которые он содержит
	len()
	Емкость среза - это количество элементов в базовом массиве, считая от первого элемента в срезе.
	cap()
	*/
	
	s123:=[]int{2,3,5,7,11,13}
	fmt.Println(cap(s123))
	fmt.Println(len(s123))
	s123 = s123[:0]
	fmt.Println(s123)
	s123 = s123[:4]
	fmt.Println(s123)
	fmt.Println(cap(s123))
	fmt.Println(len(s123))

	s123 = s123[2:]
	fmt.Println(s123)
	fmt.Println(cap(s123))
	fmt.Println(len(s123))


	




}
