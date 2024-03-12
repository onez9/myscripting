# Из библиотеки PIL импортировать класс Image
# https://python-scripts.com/pillow
from PIL import Image


# size of pic
# при вызове этой функции в img записывается Image объект изображения, а height_new новая высота изображения :) 
def get_image_resize(img, height_new):
    # для доступа к данным изображения используется атрибут(поле, как их еще называют) класса size
    # он(img.size) содержит в себе два элемента ширину и высоту. Выглядит кортеж так (x, y), где x и y могут быть чем угодно, в данном случае это числа   
    width, height = img.size # соответственно width и height будут хранить старую высоту и длинну изображения
    # // - деление без остатка
    # width_new//width == height_new//height - это стандартная пропорция. У нас есть старая ширина, высота и новая высота
    # а нам нужно получить новую вусоту
    # таким образом Беляков получил новую высоту изображения(Он ёе вывел)
    width_new = width // (height//height_new)

    # img.resize() принимает два параметра кортеж(это ширина и высота в скобках) и resamble - необязательный фильтр передискретизации
    # https://www.geeksforgeeks.org/python-pil-image-resize-method/. метод resize() не изменяет объект img, а возвращает новый в img_new
    img_new = img.resize((width_new, height_new), Image.ANTIALIAS)
    # img_new возвращает функция Белякова и приваивается переменной img_new1 в 99 строке
    return img_new


# pic symbols
def get_image_symbols(img_new):

    width, height = img_new.size

    # нужно для ассоциирования пикселя с символом
    segment = 256 * 256 * 256 // len(symbols)
    # строка в которую будет записан результат
    result = ''
    
    # пробегаемся по каждому пикселю по высоте
    for y in range(height):
        # пробегаемся по каждому пикселю по ширине
        for x in range(width):
            # red green blue три переменные по получают значениия от 0 до 255
            r, g, b = img_new.getpixel((x, y))
            # color = r * g * b
            if switching_ch == 2:
                # инверсия из полностью белого вычитаем необходимое колличество синего или зелёного или красного
                color = abs(255 - r) * abs(255 - g) * abs(255 - b)
            elif switching_ch == 1:
                # цвет не меняется
                color = r * g * b
            # pos - это index из строки symbols(в которой хранятся символы для кодирования)
            #
            # таким способом мы получаем значение pos в пределах от 0 до len(symbols)=18. тк изображение мы уменшили отношение color // segment позволяет однозначно ассацировать каждый пиксель с одним из символов строки symbols
            pos = color // segment
            # удаиваем каждый символ-пиксель, чтобы изображение не казалось слишком узким
            result += symbols[pos] * 2
        # добавляем перенос строки 
        result += '\n'
        # тут он специально строку добавляет в список и она там не как несколько элементов а как именно один элемент
    pic.append(result) # так он проверяет кто действително разобрался в коле. Проверка на вшивость:) из-за это-го не работало инверирование и переворот(я про функцию inverting_pic_sides). решением было заменить все pic на result в функие ниже
    return result



    


# inverting sides
# можешь мне написать если тут что-то непонятно, а по факту это простой вывод файл
def inverting_pic_sides(result):
    with open(f'output_ascii.txt', mode='a', encoding='utf8') as out:

        if inverting_ch == 1:
            for i in range(len(result)):
                out.write(result[i])

        if inverting_ch == 2:
            for i in range(len(result)-1, 0, -1):
                out.write(result[i])

        if inverting_ch == 3:
            for i in range(len(result)):
                for k in range(len(result)-1, 0, -1):
                    out.write(result[i][k])

        if inverting_ch == 4:
            for i in range(len(result)-1, 0, 1):
                for k in range(len(result)-1, 0, -1):
                    out.write(result[i][k])








# От сюда начинается выполнение прграммы
print('Отражение?')
# без циклов и break тоже бы работало. не знаю зачем он это сделал
while True:
    inverting_ch = int(input('1 - Нет\n'
                             '2 - Перевернуть\n'
                             '3 - Отзеркаливание\n'
                             '4 - Всё\n'))
    break

print('Инвертация цвета?')
while True:
    switching_ch = int(input('1 - Да\n'
                             '2 - Нет\n'))
    break


# Image.
# загружаем изображение через метод open класса Image
# в img записывается Image объект для работы с этим изображением

img = Image.open('ascii.jpg')


# get_image_resize - функция с двумя параметрами. Эту функцию написал Беляков. Она принимает объект того изображения, которое мы только что открыли и новую высоту

# мы сначала уменьшаем изображение до нужного колличества пикселей чтобы проще было кодировать и ассоцировать каждый пиксель с символом. (У нас просто монитора не хватит чтобы вывести ,например избражение размером 1500х900 пикселей текстом)
img_new1 = get_image_resize(img, 50)

# Создаем пустой список
pic = []


# символы которыми будет кодироваться изображение
symbols = '.:;+*123#░ &?#░▒▓█'


# отправляем новый объект изображения в функцию get_image_symbols
result = get_image_symbols(img_new1)

inverting_pic_sides(result)

