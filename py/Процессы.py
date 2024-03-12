import multiprocessing
import time
import threading


def test():
    acc = 0
    while True:
        print(f'{multiprocessing.current_process().name} - {time.time()}')
        time.sleep(1)
        acc += 1
        if acc == 3:
            break


if __name__ == '__main__':
    prc = []
    for i in range(6):
        pr = multiprocessing.Process(target=test, name=f'pr-{i}')
        prc.append(pr)
        pr.start()

    for it in prc:
        it.join()  # пока процесс не завершится ниже не опустимся
    print("Все процессы завершены! Идём дальше")

    # multiprocessing.Process(target=test, name='prc-2').start()
    # multiprocessing.Process(target=test, name='prc-3').start()
    # print("Процесс запущен")

