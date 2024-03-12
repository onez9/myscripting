from math import floor, ceil, trunc
from pickle import FALSE, dumps, dump, load, loads, PickleError, PicklingError, UnpicklingError

from cv2 import STEREO_MATCHER_DISP_SCALE




class Someclass:
    #def __new__(self): # нужно изучить этот метод, а потом переопределять, если раскомментировать __eq__ и __del__ не будут работать
    #    print('__new__ method is running')

    def __init__(self, a, b):
        print('initialize')
        self.a = a
        self.b = b

    # Замечание от переводчика: svetlov отмечает, что здесь автор ошибается,
    # на самом деле __del__ всегда вызывается по завершении работы интерпретатор
    # Но почему-то при запуске ничего не происходит
    def __del__(self):
        print("Объект попадает в зборщик мусора")
    def __eq__(self, __o: object) -> int:
        print('hello')
        return '='
    def __cmp__(self, other):
        print('print something 73453595345345359354')
        return 'cmp'
    def __invert__(self):
        return '__invert__ function'
    def __ne__(self, other):
        print('Random text here')
    # def __reduce__(self):
        # print('something happen&')
    def __neg__(self):
        print('tu tu ru')
        return '-'
    def __abs__(self):
        print('abs')
        return 'abs'
    def __int__(self):
        print('Иди нахуй')
        return 12
    # То что ниже почему-то не переопределяется
    def __round__(self, n):
        print('__round__ function')
        return 3
    def __floor__(self):
        return 'Округление для ближайшего меньшего целого'
    def __ceil__(self):
        print('Округление для ближайшего большего целого')
        return 43
    def __trunc__(self):
        return 'Транк тоже не работает'
    def __xor__(self, other):
        return "xor xor xor"
    def __reduce__(self):
        print('TUTUTURURURURURURURU123')
        return Someclass, (123, 123)

if __name__ == '__main__':
    print('start')


    c1 = Someclass(1, 2)
    c2 = Someclass(1, 3)

    # __eq__ тест для
    print(f'Равенство(Тождество): {c1==c2}')

    # __cmp__(self, other) тест компаре
    # c1.__reduce__() # переводится, как уменьшить
    print(f'Отрицание: {-c1}')
    print(f'Модуль: {abs(c1)}')
    print(f'Инвертирование(~): {~c1}')
    print(f'Округление: {round(c1, 2)}') # not working for me
    print(f'Округление: {floor(c1)}') # up также
    print(f'Округление: {ceil(c1)}') # up также
    print(f'Обрезание {trunc(c1)}') # А не работает потому что говно тупое блядь
    print(f'xor this xor: {c1^1}')
    print(f'int: {int(c1)}')


    # Тут я демонстрирую как переопределяется метод reduce, то бишь сериализация/десериализация
    if False:
        with open('data.dt', 'wb') as fo:
            resdump = dump(c1, fo)
            print(resdump) # NONE 論理
    else:
        with open('data.dt', 'rb') as fi:
            readdata = load(fi)
            print(readdata.a)
            print(readdata.b)







    print('End programm')
