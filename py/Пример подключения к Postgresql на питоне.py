import psycopg2

conn = psycopg2.connect(dbname='my_st', port="5432", 
        user='postgres', password='QwertY123', host='localhost')

cursor = conn.cursor()

def show_sql_req(cursor):
    for row in cursor:
        print(row)

cursor.execute('SELECT * FROM wifi_info;')
show_sql_req(cursor)
cursor.execute('SELECT B.bssid FROM wifi_info as B;')
show_sql_req(cursor)
cursor.execute('SELECT B.bssid, B.essid FROM wifi_info as B where id>5 and id<10; ')
show_sql_req(cursor)


# with open('mac.txt', 'r') as f:
#     read_data = f.read()
# 
# https://www.overclockers.ua/cpu/info/intel/
# 
# read_data = [[el.split()[0], el.split()[6], el.split()[5], el.split()[4], 
#     el.split()[3]] for el in read_data.split('\n')[2::] if (el != '')];
# 
# sql_insert_query = ''' insert into wifi_info (bssid, essid, date, \
#         vendor, lck, wps) values (%s,%s,current_timestamp,%s,%s,%s); '''
# 
# 
# 
# def callback(dg3):
#     print(dg3)
# 
# 
# 
# sql_create_table = ''' create table aaaa(id serial primary key, name
# varchar(80), age int); '''
# cursor.execute(sql_create_table)

    
conn.commit()
cursor.close()
conn.close()
























