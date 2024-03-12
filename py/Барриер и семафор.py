from threading import Thread, BoundedSemaphore, Barrier, current_thread
from time import ctime, sleep
from random import randint


pool = BoundedSemaphore(value=3)


def test1():
    while True:
        with pool:
            print(current_thread().name)
            sleep(3)


def test2(barrier):
    sleep(randint(3, 7))
    print(f'thr-{current_thread().name} запущен в {ctime()}')
    barrier.wait()
    print(f'thr-{current_thread().name} преодалел баррьер в {ctime()}')


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
