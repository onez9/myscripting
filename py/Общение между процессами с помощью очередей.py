import multiprocessing
import time
import random

def func():
    def func1():
        print("Hello")
def get_text(queue):
    value = random.randint(0, 30)
    print(f'value: {value}')
    queue.put(value)
    time.sleep(random.randint(1, 2))


if __name__ == '__main__':
    queue = multiprocessing.Queue()
    prcs_list = []

    for _ in range(6):
        pr = multiprocessing.Process(target=get_text, args=(queue,))
        pr.start()
        prcs_list.append(pr)

    for item in prcs_list:
        item.join()
    
    print(f'item: {queue.get()}')
    print(f'item: {queue.get()}')
    # pr.join()


    for item in iter(queue.get, None):
        print(f'item from loop: {item}')


    
    print("HELLO")
