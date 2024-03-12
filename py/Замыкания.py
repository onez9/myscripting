

def one():
  lst = ['first', 'second']

  def inner():
    print(lst)
    print(id(lst))
    return 3
  return inner




o = one()
# print(dir(o))
print(o.__closure__[0].cell_contents)


input()
