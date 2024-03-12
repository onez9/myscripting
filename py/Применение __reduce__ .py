from pickle import PickleError, PicklingError, UnpicklingError
from pickle import load, loads, dump, dumps


# def write(data, filename='data.pickle'):
#     with open(filename, 'wb') as f:
#         dump(data, f)


# def read(filename='data.pickle'):
#     with open(filename, 'rb') as f:
#         new_data = load(f)
#     return new_data

class Attack:
    def __reduce__(self):
        return (exec, ("print('12332131')",))

if __name__ == '__main__':

    data_people = {
        'fucksize': 20,
        'lenght': 178,
        'boobssize': 3
    }


    try:
        # write(data=data_people)
        # data = read()
        something = dumps(Attack()) # тут объект файла
        print(something)
        print(loads(something))
        # c1 = load(something)

        # print(c1)
        # with open('btext.txt', 'rb') as f:
        #     res = f.read()
        # print(loads(res))

    except UnpicklingError:
        print('Проблемы с десериализцацией')

    except PicklingError:
        print('Проблемы с сериализацией')

    finally:
        print('Ohh, my good')

