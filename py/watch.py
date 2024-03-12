# import keyboard
# import mouse
import pyautogui
# import pyinput
from pynput import keyboard
from pynput.keyboard import Key, Controller, GlobalHotKeys
from threading import Thread, BoundedSemaphore, Barrier
import selenium
import requests
from bs4 import BeautifulSoup as bs
# keyboard = Controller()

# def func1():
#   print("hello")
# def func():
#   # print("hello")

  # pyautogui.press(['shift', 'control'])

# keyboard.release(Key.alt)

# keyboard.press('c')
# keyboard.release('c')
# keyboard.release(Key.ctrl)


def default_position():
  with GlobalHotKeys({'<ctrl>+<alt>': lambda: pyautogui.moveTo(333, 333)}) as k:
      k.join()

def sayHello():
  with GlobalHotKeys({'<ctrl>+<alt>': lambda: print('hello')}) as k:
      k.join()


# with GlobalHotKeys({'<ctrl>+<shift>': func1}) as h:
#     h.join()
# keyboard.add_hotkey('ctrl+alt', func)

# keyboard.add_hotkey()
# pyautogui.position()
# pyautogui.move(300, 300, 3)

{ 'Cookie': 'categories=files; language=ru-RU; locale=ru; autocomplete=google; image_proxy=1; method=POST; safesearch=0; theme=oscar; results_on_new_tab=0; doi_resolver=oadoi.org; oscar-style=logicodev-dark; advanced_search=0; disabled_engines=; enabled_engines="kickass__music\054startpage__general\054habrahabr__it\054duckduckgo images__images\054dogpile__general\054rubygems__it\054qwant__general\054tokyotoshokan__files\054erowid__general\054seznam__general\054tvmaze__general\054yggtorrent__videos\054wikiquote__general\054wikisource__general\054wikivoyage__general\054fdroid__files\054etools__general\054lobste.rs__it\054reddit__news\054imdb__general\054kaufland__general\054kickass__files\054reddit__general\054unsplash__images\054searchcode code__it\054nyaa__videos\054mojeek__general\054ask__general\054wiby__general\054bitbucket__it\054frinkiac__images\054woxikon.de synonyme__general\054reddit__social media\054apk mirror__files\054invidious__music\054azlyrics__general\054nyaa__music\054openrepos__files\054gpodder__general\054free software directory__it\054petal__general\054yggtorrent__music\054wikinews__news\054yggtorrent__files\054tokyotoshokan__videos\054duden__general\054ina__videos\054geektimes__it\054naver__general\054wikiversity__general\054archive is__general\054reddit__images\054whaleslide__general\054wordnik__general\054google play movies__videos\054tokyotoshokan__music\054library genesis__general\054urbandictionary__general\054wikimini__general\0541x__images\054mymemory translated__general\054wiktionary__general\054solidtorrents__files\054yahoo__general\054rumble__videos\054gitlab__it\054duckduckgo__general\054nyaa__files\054ccc-tv__videos\054onesearch__general\054google play apps__files\054codeberg__it\054sjp.pwn__general\054kickass__videos\054peertube__videos\054npm__it\054semantic scholar__science\054ddg definitions__general\054nyaa__images\054framalibre__it\0541337x__videos\054etymonline__general\054gigablast__general\054invidious__videos\054wikibooks__general"; disabled_plugins=; enabled_plugins="Open_Access_DOI_rewrite\054Vim-like_hotkeys\054Infinite_scroll"; tokens=; autofocus=1; archive_today=0'
}



if __name__=='__main__':

  # "q=123&time_range=&language=ru-RU&category_general=on"

  data = {
    'q':'123',
    'time_range': "",
    'language':'ru-RU',
    'category_general':'on',
  }

  headers = {



    'Host': 'searx.ru',
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.3; Win64; x64; rv:105.0) Gecko/20100101 Firefox/105.0',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8',
    'Accept-Language': 'ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3',
    'Accept-Encoding': 'gzip, deflate, br',
    'Content-Type': 'application/x-www-form-urlencoded',
    'Content-Length': '52',
    'Origin': 'null',
    'DNT': '1',
    'Connection': 'keep-alive',

    'Upgrade-Insecure-Requests': '1',
    'Sec-Fetch-Dest': 'document',
    'Sec-Fetch-Mode': 'navigate',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-Fetch-User': '1',
    'Sec-GPC': '1',
    'TE': 'trailers',




  }



  url= 'https://searx.ru/search'
  text = requests.post(url=url, data=data).text
  # print(res.content)

  res = bs(text, 'html.parser')
  res = res.find(id='main_results').find_all(class_='result')
  for item in res:
    print(item)

  """
  pyautogui.FAILSAFE=False
  t1 = Thread(target=default_position, daemon=False)
  t1.start()

  t2 = Thread(target=sayHello, daemon=False)
  t2.start()

  t2.join()
  t1.join()
  """

