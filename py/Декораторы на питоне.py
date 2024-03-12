# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.




# key w args - именованные аргументы
# декоратор
def dec(func):
    def wrapper(*args, **kwargs):
        print('始める')
        result = func(*args, **kwargs) # сюда запишется outer
        print('終わる')
        return result
    return wrapper


def dec_with_parametr(arg='123'):
    print(arg)
    def outer(func):
        def wrapper(*args, **kwargs):
            print('начинаем - 始める')
            result = func(*args, **kwargs)
            print('заканчиваем - 終わる')
            return result
        return wrapper
    return outer


@dec_with_parametr()
def ppp():
    print('hello')








# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # for i in range(10):
        # Thread(target=test1, name=f'thr-{i}').start()
    # bar = Barrier(5)
    # for i in range(10):
        # Thread(target=test2, args=(bar,)).start()
    # tmp = test2.__name__
    # print(tmp)
    # дек возвращает функцию враппер
    # dec(ppp)
    a = [1, 2, 3]
    b = a
    a.append(234)
    print(b) # блять

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
