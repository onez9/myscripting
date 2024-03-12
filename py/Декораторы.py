import datetime
import time

# print(time.time())
# print(datetime.datetime.now())
def dec(func):
  def wrapper():
    start = time.time()
    print(start)
    result = func()
    print(time.time() - start)
    return result
  return wrapper

@dec
def f1():
  n = 1000
  arr = [item for item in range(n) if item%3==0]
  return arr

@dec
def f2():
  n = 1000
  arr = []
  for i in range(n):
    if i%3==0:
      arr.append(i)
  return arr

try:
  l1 = f1()
  l2 = f2()
  print('--')
  # print(l1)
  # print(l2)
except Exception as e:
  print(e)
# print(f1())
# print(f2())
input()
