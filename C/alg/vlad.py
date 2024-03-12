import sys
import math as m
start = input('Enter a value: ')
lst = []
tt = 0

if list(start)[0] == ':':
	print(-1)
	sys.exit()
start = int(start)
old = int(start)
while start <= 10**8:
	boo = 0 # оканчивающиеся на 0 числа
	string = str(start)

	# 0 или 2
	for i in range(0, len(string)):
		if string[i] == '0' or string[i] == '2':
			n = 10**(len(string)-i-1)
			start += n - (start % n)
			boo = 1
			tt += 1
	string = str(start)


	# Checking the uniqueness of symbols
	for i in range(len(string)):
		if string[i] in lst:
			n = 10**(len(string)-i-1)
			start += n - (start % n)
			boo = 1
			tt += 1
		else:
			lst.append(string[i])


	#print(boo,tt)
	if tt == 0:
		#start += 1
		boo = 1
	if start % 10 == 0:
		boo = 1
	lst = []
	if boo == 0:
		print(start)
		break
	if old == start:
		start += 1
		tt = 1
		continue
	if start > 10**8:
		print(-1)


