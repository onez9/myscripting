
def decorat(func):
  def wrapper():
    print('Hello')
    result = func()
    print('Buy')
    return result
  return wrapper


@decorat
def f1():
  i = 0
  while i < 10:
    yield i
    i += 1
  # return [123, 123, 123]

try:
  g = f1()
  print(*g)
  # print(next(g))
  # print(next(g))
  # print(next(g))
  # f1()

except Exception as e:
  print(e)
finally:
  input('Нажмите ENTER для выхода')
