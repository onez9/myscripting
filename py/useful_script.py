import os, sys
from PIL import Image
import shutil
import re

def resize_image(name, height):
  img = Image.open(f'{curdir}\\{name}')
  file_extension = name.split('.')[-1].lower()
  file_name = '_'.join(name.split('.')[:-1:])
  if img.size[1] > height:
    cwidth, cheight = img.size
    width = int((cwidth/cheight) * height)

    img = img.resize((width, height), Image.ANTIALIAS)
    nfilename = f'{file_name}r.{file_extension}'
    img.save(nfilename)


    shutil.move(file, f'{dirname}')

def findandremove(name):
  string = name
  match = re.search(r'r.', string) # только первое совпадение
  # match = re.findall(r'\d+', string) # возвращает все найденные значения
  if match is not None:
    os.remove(string)
  # print(match)
  # print(match.group(0))
  # input()

if __name__ == '__main__':
  path = 'C:\\Users\\User\\Pictures'
  os.chdir(path=path)
  curdir = os.getcwd()
  filterimage = ['png', 'jpg', 'jpeg']
  lstfile = [file for file in os.listdir() if len(file.split('.')) >= 2 and file.split('.')[-1].lower() in filterimage]

  dirname = 'original'
  # os.mkdir(dirname)

  for file in lstfile:
    resize_image(file, 768)
    # shutil.move(file, f'{dirname}')
    # findandremove(file)
