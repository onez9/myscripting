import pandas as pd
import matplotlib.pyplot as plt

def func1():
  df=pd.read_csv('apple.csv', index_col='Date', parse_dates=True)
  df=df.sort_index()
  print(df.info())
  print(df.loc['2012-Feb', 'Close'].mean())
  # print(df.loc['2012-Feb':'2015-Feb', 'Close'].mean())
  newsample=df.loc['2012-Feb': '2015-Feb', ['Close']]
  newsample.plot()
  plt.show()
  print(df.resample('W')['Close'].mean())

def func2():
  titanic_df = pd.read_csv('titanic.csv')
  print(titanic_df.head())
  print(titanic_df.groupby(['Sex', 'Survived'])['PassengerID'].count())


if __name__=='__main__':
  func2()
