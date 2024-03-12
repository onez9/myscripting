class class_test:
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def __repr__(self):
		return f'x = {self.x} y = {self.y}'
	def __add__(self, b):
		return class_test(self.x + b.x, self.y + b.y)
	def __sub__(self, b):
		return class_test(self.x - b.x, self.y - b.y)
	def __mul__(self, b):
		return class_test(self.x * b.x, self.y * b.y)
	def __truediv__(self, b):
		return class_test(self.x / b.x, self.y / b.y)
	def __floordiv__(self, b):
		return class_test(self.x // b.x, self.y // b.y)
	def __mod__(self, b):
		return class_test(self.x % b.x, self.y % b.y)
	def __pow__(self, b):
		return class_test(self.x ** b.x, self.y ** b.y)
	def __lshift__(self, b):
		return class_test(self.x << b.x, self.y << b.y)
	def __neg__(self):
		return
	def __eq__(self, b):
		return 




a = class_test(1, 2)
b = class_test(2, 3)
c = class_test(3, 3)
d = a << b

print(d)