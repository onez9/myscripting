import math as m

a = b = 1
while True:
	c = a + b
	if len(str(c)) > 100:
		break
	print(c)
	a = b
	b = c

