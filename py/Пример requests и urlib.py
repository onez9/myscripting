import urllib3 
import json



http = urllib3.PoolManager() 
#r = http.request(
#        'GET', 
#        'https://gitlab.com/i23wuMB367/algorithms/-/blob/master/eulers_project/11.py'
#        ) 
r = http.request(
        'GET',
        'http://httpbin.org/ip'
        )

pp = json.loads(r.data.decode('UTF-8'))

print(pp)
# print(r.headers)
# print(r.status)
# print(r.data) 
