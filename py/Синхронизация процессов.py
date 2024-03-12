import multiprocessing
import time


def test_func(lock):
    lock.acquire()
    print(f'{multiprocessing.current_process()} - {time.time()}')
    time.sleep(2)
    lock.release()


if __name__ == '__main__':
    lock = multiprocessing.Lock()
    prs = []
    for i in range(6):
        pr = multiprocessing.Process(target=test_func, name=f'pr-{i}', args=(lock,))
        prs.append(pr)
        pr.start()

    for pr in prs:
        pr.join()
    print('Все процессы завершены!')


