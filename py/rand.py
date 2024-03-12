import random
from threading import Thread
import time
import os



if __name__=='__main__':
	



	# arr = {
	# 	1: 3,
	# 	2: 5,
	# 	...: 34,
	# 	'32': 666

	# }
	# print(arr[Ellipsis])

	what = {
	 1: (Ellipsis, print),
	 ...:lambda x: lambda y: x+y
	}

	what = {
	 1: (..., print),
	 ...:lambda x: lambda y: x+y
	}

	# what[1][1](what[,what[1][0]](1)(2))
	what[1][1](4)
	# try:
	# 	print(os.system('cls'))
	# 	while True:
	# 		number = random.randint(10,100)

	# 		print(f"Сколько будет {number} в квадрате?")
	# 		start = time.time()
	# 		answer = int(input("Ваш ответ: "))
	# 		if answer == number**2:
	# 			end = time.time()
	# 			print(f'Правильно, молодец! ({end-start})  (в секундах)')
	# 		else:
	# 			end = time.time()
	# 			print(f'Неправильно, думай дальше; Время ответа: {end-start} (в секундах)')
	# 		print()	

	# except KeyboardInterrupt:
	# 	print('Выход')