import threading
from threading import Thread, BoundedSemaphore, Semaphore
import time
from random import randint




#BoundedSemaphore может быть реальзован столько раз сколько заблокирован
#Semaphore может быть реализован больше раз чем заблокирован

"""
def test():
    # while True:
    with pool:
        print(f'Поток {threading.current_thread().name} запущен')
        time.sleep(1)
        print(f'Поток {threading.current_thread().name} остановлен')
"""


print("Hello ...")
def test() -> None:
    acc = 0
    while True:
        print(f"second thread {acc}")
        time.sleep(1)
        acc += 1


if __name__ == '__main__':

    # Создание неблокирующего потока
    thr = threading.Timer(4, test)
    thr.setDaemon(True)
    thr.start()

    """
    while True:
        print("Test main")
        time.sleep(2)
    """
    for i in range(3):
        time.sleep(1)
        print(f'main thread {i}')

    # Ждём 3 секунды и отменяем поток
    # thr.cancel()

    print("finish")



    """
        max_connections = 3
        pool = BoundedSemaphore(value=max_connections)
    
        for i in range(10):
            Thread(target=test, name=f'thr-{i}').start()
    """



# def test(barrier):
#     time.sleep(randint(1, 4))
#     print('Поток запущен\n')
#     barrier.wait()
#     print('Придедел преодалён!\n')
#

# if __name__ == '__main__':
#     count = 5
#     bar = threading.Barrier(count)
#     for i in range(10):
#         Thread(target=test, args=(bar,), daemon=False, name=f'thr-{i}').start()















#
#
# data = threading.local()
# data.name = "Sever crashed"
# test_string = "Server shutdown"
# def set():
#     data.name = "local"
#     get()
#
# def get():
#     print(data.name)
#     print(test_string)
#
#
# class Test:
#     def __init__(self):
#         self.counter = 0
#         self.lock = threading.RLock()
#
#     def add(self):
#         self.lock.acquire(blocking=True)
#         print('puk')
#         self.lock.acquire(blocking=True)
#         time.sleep(0.3)
#         # time.sleep(2)
#         print(f'\n{threading.current_thread().name}: {self.counter}')
#         self.counter += 1
#         self.lock.release()
#         self.lock.release()

        # print(self.lock.acquire(blocking=False))
        # try:
        #     # self.lock.release()
        #     a = 1/0
        # except ZeroDivisionError:
        #     print('ZeroDivisionError')
        # except RuntimeError:
        #     print('RUNTIMEERROR')
        #



    # def game(self):
    #     tmp = 0
    #     print('\nRun\n')
    #     for it in range(10):
    #         print(f'\nhere = {tmp}')
    #         tmp += 1
    #
    #
    # def show(self):
    #     print(f'\nCounter is {self.counter}')

# def func2():
#     global acc
#     for _ in range(5):
#         time.sleep(1)
#         acc += 1


# if __name__ == '__main__':
#     get()
    # set()
    # test1 = Test()
    # arr = []
    # counts = 10
    # for i in range(counts):
    #     arr.append(Thread(target=test1.add, daemon=False))
    #
    # for i in range(counts):
    #     arr[i].start()

    # for i in range(counts):
    #     arr[i].join()

    # test1.show()
