from threading import Event, Condition, Barrier, BoundedSemaphore, Thread, current_thread, active_count
from time import sleep


def test():
    while True:
        event.wait()
        print('test')
        sleep(3)


def functestevent():
    thr_num = current_thread().name
    print(f'Идёт подготовка изобожения из потока [{thr_num}]')

    event.wait()
    print('Изображение отправлено')


def functestcond1():
    while True:
        # with cond:
        cond.acquire()
        # cond.wait(timeout=None)
        cond.wait_for(booo3)
        print(f'Мы c вами получили событие!')
        cond.release()

def booo3():
    sleep(10)
    return True

def functestcond2():
    for i in range(101):
        if i%10==0:
            with cond:
                # cond.acquire()
                cond.notify()
                # cond.release()
        else:
            print(f'somefunc-{i}')
        sleep(0.2)


if __name__ == '__main__':
    event = Event() # no acquire and release
    cond = Condition()
    # booo3 = False
    Thread(target=functestcond1).start()

    # Thread(target=functestcond2).start()


    # for i in range(10):
    #     Thread(target=functestevent, name=f'thr-{i}').start()
    #     print(f'Поток [{i}] запущен')

    # if active_count() >= 10: # return count active threads
    #     event.set() # flag -> true
    # a = 3
    # Thread(target=test).start()
    # sleep(3)
    # event.set()
    # print("hsfls")
    # if a := test():
        # print(a)
    # event.clear() # event FALSE
    # event.set() # event True
    # Thread(target=test).start()
