package main // Определение пакета

import (
	"fmt"
	"math"
	"runtime"
	"time"
)


/*
comment
comment block


*/


// аналогично for, оператор if может начинаться с оператора, который должен выполняться перед условием.
// переменные объявленные оператором находятся в области видимости только до конца оператора if или else
func pow(x,n,lim float64) float64 {
	if v:=math.Pow(x,n); v<lim {
		return v
	} else {
		fmt.Println(v)
	}

	return lim
}



// функции
func add(x int, y int) int {
	return x + y
}

// если параметры имеют один и тот же тип
func add1(x, y int) int {
	return x+y
}

// функция нескольких результатов. Функция swap возвращает 2 строки
func swap(x, y string) (string, string) {
	return y, x
}

func divideMul(sum int) (x, y int) {
	x=sum/10
	y=sum*10
	return // naked return
}

/*
var i1,j1 int=1,2 // переменные с инициализаторами

var c,python,java bool // объявляет список имён переменных одного типа с помощью оператора var
*/


func main() {
	/*
	fmt.Println("Привет, ПГАТУ")
	fmt.Println(math.Pi)
	fmt.Println(add(42,13))
	fmt.Println(add1(42,13))
	a,b:=swap("hello","world")
	fmt.Println(a,b)
	x1,y1:=divideMul(20)
	fmt.Println(x1,y1)
	var i int
	fmt.Println(i,c,python,java)
	var cpp,python3,js=true,false,"no!" // переменная с инициализатором, тут опустили тип, переменная имеет тип инициализатора
	fmt.Println(i1,j1,cpp,python3,js)
	*/

	fmt.Println(math.Pi)
	var i3,j int=1,2
	k:=3 // короткий оператор присваивания, вместо объявления var с неявным типом(работает внутри функции)
	// вне функции каждый оператор начинается с ключевого слова (var,func и т.д.), поэтому конструкция := недоступна
	c,python,java:=true,false,"no!"
	fmt.Println(i3,j,k,c,python,java)


	// Нулевые значения (переменные без явного начального значения присваивается нулевое значение)
	/*
	0 - числовых типов
	false - логических типов
	"" - для строк
	nil - для указателей
	*/
	var i1 int
	var f float64
	var b bool
	var s string
	fmt.Printf("%v %v %v %q\n", i1, f, b, s)



	// преобразование типов
	var i44 int = 44
	var f44 float64=float64(i44)
	var u44 uint=uint(f44)
	fmt.Println(i44,f44,u44)
	// в отличии от С, в Go присваивание между элементами разного типа требует явного преобразования



	/*
	// Вывод типов
	var i66 int
	j66:=i66 // j66 будет int
	i77:=77 // int
	f77:=77.77 // float64
	g77:=77.77+0.7i // complex128
	fmt.Printf("%v %v %v %v\n", j66, i77, f77, g77)
	
	// константы могут быть символьными, строковыми, логическими или числовыми
	// константы не могут быть объявлены через :=
	const world = "sekay"
	fmt.Println("Hello", world)



	// Циклы. В Го есть только одна циклическая конструкция - цикл for
	sum:=0
	for i:=0;i<10;i++ { // 3 компонента оператора for не заключаются в скобки ()
		sum+=i
	}
	fmt.Println(sum)

	// бесконечный цикл
	for {
	}
	*/

	
	// while
	sum:=1
	for sum<1000 {
		sum += sum
		
	}
	fmt.Println(sum)



	fmt.Println(pow(2,3,100))

	// switch в go такой же, как и в си с++ java js и php, за исключением того что go выполняет только выбранный вариант
	// switch выбирает case сверху вниз до первого выполнения указанного условия
	fmt.Println(runtime.GOOS)
	fmt.Print("Go runs on ")

	
	switch os:=runtime.GOOS; os {
		case "darwin":
		fmt.Println("OS X.")
		case "linux":
		fmt.Println("Linux.")
		default:
		//freebsd,openbsd,
		//plan9,windows...
		fmt.Printf("%s.\n", os)
		
	}

	t:=time.Now()
	switch {
		case t.Hour() < 12:
		fmt.Println("Good morning!")
		case t.Hour() < 17:
		fmt.Println("Good afternoon.")
		default:
		fmt.Println("Good evening")
	}




	/*
	Основнýе типý Go:
	bool - булево знаùение
	string - строка
	int int8 int16 int32 int64 - øелýе ùисла
	uint uint8 uint16 uint32 uint64 uintptr - беззнаковýе øелýе ùисла
	byte (псевдоним длā uint8) - байт
	rune (псевдоним длā int32) - длā работý с символами Unicode
	float32 float64 - ùисла с плаваĀûей запāтой
	complex64 complex128 - комплексное ùисло
	*/
	
}
