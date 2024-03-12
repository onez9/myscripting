from threading import Event, Condition, Barrier, BoundedSemaphore, Thread, current_thread, active_count, current_thread
from time import sleep
from random import randint



def test():
    while True:
        event.wait()
        print('test')
        sleep(3)



def image_handler():
    thr_num = current_thread().name
    print(f'Идёт подготовка изобожения из потока [{thr_num}]')

    event.wait()
    print('Изображение отправлено')


def somefunc():
    while True:
        with cond:
            cond.wait()
            print(f'Мы c вами получили событие!')


def somefunc2():
    for i in range(101):
        if i%10==0:
            with cond:
                cond.notify()
        else:
            print(f'somefunc-{i}')
        sleep(0.2)




if __name__ == '__main__':
    event = Event()
    cond = Condition()


    # a, = [1]
    # print(a)

    for i in range(10):
        Thread(target=image_handler, name=f'thr-{i}').start()
        print(f'Поток [{i}] запущен')

    if active_count() >= 10:
        event.set()

    # if a := test():
        # print(a)
    # event.clear() # event FALSE
    # event.set() # event True
    # Thread(target=test).start()
