def test(n):
  def wrapper(num):
    return num + n
  return wrapper



test_function1 = test(3)
print(test_function1(4))
