
import multiprocessing
import time
import random


def add_value(locker, array, index):
    with locker:
        num = random.randint(8, 20)
        vtime = time.ctime()
        array[index] = num
        print(f'array[{index}] = {num}, sleep = {vtime}')
        time.sleep(num)


if __name__ == '__main__':
    lock = multiprocessing.Lock()
    arr = multiprocessing.Array("i", range(10))

    process_list = []

    for i in range(10):
        pr = multiprocessing.Process(target=add_value, args=(lock, arr, i))
        process_list.append(pr)
        pr.start()

    for item in process_list:
        item.join()

    print(list(arr))



