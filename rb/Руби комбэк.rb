
# puts("Привет")
# string = "    Привет как дела?    "
# puts(string)
# puts(string.upcase())
# puts(string.downcase())
# puts(string.strip())
# puts(string.length())
# puts(string.include? "ив")
# num = -234.632
# num *= -1
# puts(num.abs())
# puts(num.round())
# puts(Math.sqrt(num))
# puts(Math.sqrt(num))
# puts("Введите ваше имя: ")
# str2 = gets.chomp()
# puts("Ваше имя: " + str2 + ", ты крут!")

# num1 = gets.chomp().to_i
# num2 = gets.chomp().to_i
# num3 = gets.chomp().to_f
# num4 = gets.chomp().to_f


# puts(num1 + num2)
# puts(num3 + num4)



arr = Array[4, 6, 6, 234, 345, 34, 132433, 34, 312]
puts(arr)


# создали пустой массив
list = Array.new
list[0] = 4324
list[23]= 321

puts(list)


countris = {
  123 => "Anime123",
  "countris" => 435,
  :re => 13,
}
puts(countris)
puts countris


def sayHello
  puts "Привет мир"
end

def sayTwo(word='Hello', num=423432)
  puts "Ваше слово: " + word + " ваше число: " + num.to_s
end

def summa(x, y)
  return x+y,70
end

sayHello
sayTwo
res = summa(213,130)
puts res
