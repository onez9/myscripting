

class Test:
    def __init__(self, age, name):
        self.age = age
        self.name = name

    def show(self):
        print(f'{self.name=}')
        print(f'{self.age=}')


if __name__ == '__main__':
    t1 = Test(13, 's93s')
    t1.show()
