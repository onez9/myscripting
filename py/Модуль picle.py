from pickle import PickleError, PicklingError, UnpicklingError
from pickle import load, loads, dump, dumps


def write(data, filename='data.pickle'):
    with open(filename, 'wb') as f:
        dump(data, f)




def read(filename='data.pickle'):
    with open(filename, 'rb') as f:
        new_data = load(f)
    return new_data

class newClass:
    def __init__(self, a, b, c):
        self.a=a
        self.b=b
        self.c=c
    def show(self):
        print(self.a, self.b, self.c)

if __name__ == '__main__':

    data_people = {
        'fucksize': 20,
        'lenght': 178,
        'boobssize': 3
    }




    try:
        # write(data=data_people)
        # data = read()
        bd = dumps(newClass)
        print(bd)
        res = loads(bd)
        print(res)
        print(newClass)
        object1Class = res(1, 2, 3)
        object1Class.show()
        # with open('btext.txt', 'rb') as f:
        #     res = f.read()
        # print(loads(res))

    except UnpicklingError:
        print('Проблемы с десериализцацией')

    except PicklingError:
        print('Проблемы с сериализацией')

    finally:
        print('Ohh, my good')

