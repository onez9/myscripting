import time

named_tuple = time.localtime() # get struct_time
# time_string = time.strftime("%Y-%d-%m, %H:%M:%S", named_tuple)
time_string = time.strftime("%Y-%d-%m", named_tuple)

print(time_string)
