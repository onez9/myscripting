from bs4 import BeautifulSoup
import requests
import sqlite3
import os

def getTask(url):
  try:
    res = requests.get(url).text
    soup = BeautifulSoup(res, 'html.parser') #Представляет объект ввиде вложенной структуры

    return soup.title.text, soup.find(class_="problem_content").text.strip()
  except Exception as e:
    return soup.title.text, "not  found"


if __name__=='__main__':
  os.chdir("C:\\Users\\User\\Code\\smilesite\\private")
  # print(os.getcwd())
  con = sqlite3.connect('db12.db') # to to create a connection to the database
  cur = con.cursor(); # In order to execute SQL statements and fetch results from SQL queries


  for i in range(52, 333):
    url = f"https://euler.jakumo.org/problems/view/{i}.html"
    name, task = getTask(url)

    query = "insert into tasks (task, answer, name) values (:task, :answer, :name);"
    cur.execute(query, {'task': task, 'answer': i, 'name': name})
    con.commit()


  con.close()



