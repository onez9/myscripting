from datetime import datetime
from random import sample
from threading import Thread
from time import sleep
import keyboard
import sys
import os
import ctypes
from colorama import Fore, Back, Style
import colorama
colorama.init()

pf = getattr(ctypes.windll.LoadLibrary("user32.dll"), "GetKeyboardLayout")
if hex(pf(0)) != '0x4190419':
	keyboard.send('shift+alt')
	exit()

def int_r(num):
    return int(num + (0.5 if num > 0 else -0.5))

start = False
start_time = None
words = None
letter_index = 0
word_index = 0
error_count = 0

def print_type_speed():
	while word_index < 19:
		printed_count = len(''.join(words[:word_index])) + len(words[word_index][:letter_index])
		elapsed_time = (datetime.now() - start_time).total_seconds()
		if elapsed_time > 0:
			type_speed = printed_count / elapsed_time
			os.system(f'title {int_r(type_speed * 60)} симв./мин.')
			sleep(0.25)

def print_info(error: bool=False):
	entered = Back.GREEN + Fore.WHITE + words[word_index][:letter_index] + Style.RESET_ALL
	if error:
		not_entered = Back.RED + Fore.WHITE + words[word_index][letter_index:letter_index+1] + Style.RESET_ALL + words[word_index][letter_index+1:] 
	else:
		not_entered = words[word_index][letter_index:]	
	space = ' '*5
	progress = f'[{word_index+1}/20]'
	sys.stdout.write(f'\r' + entered + not_entered + space + progress + space)
	sys.stdout.flush()

def restart():
	global start, start_time, words, letter_index, word_index, error_count
	os.system('cls')
	os.system('title TypeSpeedTest')
	with open('words.txt', 'r', encoding='utf-8') as file:
		words = sample(file.read().split('\n'), 20)
		file.close()
	start = False
	start_time = None
	letter_index = 0
	word_index = 0
	error_count = 0
	print_info()

def key_hook(event):
	global start, letter_index, word_index, start_time, error_count

	key = event.name
	if len(key) > 1 or not key.isalpha():
		return

	if key == words[word_index][letter_index]:
		if not start:
			start = True
			start_time = datetime.now()
			Thread(target=print_type_speed).start()
		letter_index += 1
		if letter_index == len(words[word_index]):
			word_index = word_index + 1 if word_index < 19 else 19
			letter_index = 0
		print_info()
	else:
		error_count += 1
		print_info(error=True)

	if word_index == 19:
		os.system('title TypeSpeedTest')
		os.system('cls')
		letters_count = len("".join(words))
		type_speed = letters_count / (datetime.now() - start_time).total_seconds()
		error_total = f'{(100 / letters_count * error_count):.1f}'
		print(f'Скорость печати: {int_r(type_speed)} симв./сек. ({int_r(type_speed * 60)} симв./мин.)\nКоличество ошибок: {error_total}%')
		os.system('pause')
		restart()
		
restart()
keyboard.on_press(key_hook)
keyboard.wait()