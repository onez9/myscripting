from threading import Thread, BoundedSemaphore, Barrier, current_thread
from time import sleep
from random import randint
x = 0


def increment_global(br):
    global x
    for _ in range(100):
        tmp = x
        tmp += 1
        sleep(randint(10, 20) * 0.05)
        print(f'{current_thread().name} Пришел в гости (стоит ожидает других(должно быть 3 человека))')
        sleep(randint(10, 20) * 0.05)
        print('Все 3 сидлят и пьют ром')
        sleep(randint(10, 20) * 0.1)
        # print(f'x = {x}, {current_thread().name}')
        br.wait()
        print(f'{current_thread().name} Ушел домой')
        x = tmp


def main():
    global x
    barrier = Barrier(3)
    t1 = Thread(target=increment_global, name=f'thr-1', args=(barrier,))
    t2 = Thread(target=increment_global, name=f'thr-2', args=(barrier,))
    t3 = Thread(target=increment_global, name=f'thr-3', args=(barrier,))
    t4 = Thread(target=increment_global, name=f'thr-4', args=(barrier,))

    t1.start()
    t2.start()
    t3.start()
    t4.start()

    t1.join()
    t2.join()
    t3.join()
    t4.join()

if __name__ == "__main__":
    main()
    print("x = after Iteration {0}".format(x))
