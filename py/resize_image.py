import os, sys
from PIL import Image
import shutil
import re

def resize_image(src, height, dst):
  os.chdir(src)
  lstfile = [file for file in os.listdir() if len(file.split('.'))>=2 and file.split('.')[-1] in ['jpg', 'png', 'jpeg', 'gif']]

  for name in lstfile:
    img = Image.open(name)
    file_extension = name.split('.')[-1].lower()
    file_name = '_'.join(name.split('.')[:-1:])
    if img.size[1] > height:
      cwidth, cheight = img.size
      width = int((cwidth/cheight) * height)

      img = img.resize((width, height), Image.ANTIALIAS)
      filename_new = f'{file_name}768r.{file_extension}'
      img.save(filename_new)
      shutil.move(name, f'{dst}')

def findandremove(src, r1):
  os.chdir(src)
  acc = 0
  for string in os.listdir():
    match = re.search(r1, string) # только первое совпадение
    # match = re.findall(r'\d+', string) # возвращает все найденные значения

    if match is not None:
      print(string)
      acc+=1
      os.remove(string)
  print(acc)

# рекурсивная функция для переноса всех файлов с определенным расширение в одно место
def rec_dis(from_, to_):
  os.chdir(path=from_)
  for ext in ['png', 'jpg', 'jpeg', 'gif']:
    fstr = f'move *.{ext} {to_}'
    os.system(fstr)
  lstdir = [element for element in os.listdir() if len(element.split('.')) == 1]
  for dir in lstdir:
    rec_dis(dir, to_)
    print(dir)
  os.chdir('..')

def move_some_file(src):
  os.chdir(src)
  # os.mkdir('origin')
  for filename in os.listdir():
    match = re.search('r\.', filename)
    if match is not None:
      # print(match.group())

      print(filename)
      shutil.move(filename, '..')


if __name__ == '__main__':
  src = 'C:\\Users\\User\\Pictures'
  dst = 'C:\\Users\\User\\Pictures\\origin'

  n768r = '[0-9]{3}r\\.'
  r = '[^0-9]{3}r\\.'
  r1 = '[^768]r\\.'
  findandremove(src, r1)
  # print([1, 2, 3, 54][-1])

  # print(lstfile) # resize_image

  # resize_image(src, 768, dst)
  # move_some_file(dst)


