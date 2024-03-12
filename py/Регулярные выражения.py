import re

string = 'gjkfdg133jk34r.kj3545lkjgdjdlf'


match = re.search(r'r3213.', string) # только первое совпадение
# match = re.findall(r'\d+', string) # возвращает все найденные значения

print(match)
print(match.group(0))
# input()
