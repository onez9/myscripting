import logging
import requests
# from requests1 import cc
# import requests1.cc as cc
# logging.basicConfig(level='DEBUG', filename='mylog.log')
logging.basicConfig(level='DEBUG')
logger = logging.getLogger()
# print(logger)

# print(cc)
# logger.setLevel('DEBUG')
# print(dir(logger))
# print(logger)
# print(logger.level)
# print(logger)
# logger.debug(f'somethings name = {123}')
# не показывается потому что у обработчика логгера и у самого логера
# свои собственные уровни логгирования

# у одного логгера может быть несколько обработчиков
logging.getLogger('urllib3').setLevel('CRITICAL')

# for key in logging.Logger.manager.loggerDict:
#   print(key)



# print(logger.handlers)
def aaaa(name):
  # logger.debug(f'Enter in the main() function: name = {name}')
  # print(logger)
  logger.debug(f'Enter in the main() function: name = {name}')

  print()
  r = requests.get('https://www.google.ru')
# debug - 10
# info - 20
# warning - 30

if __name__ == '__main__':
  # f.say()
  aaaa('alex')
