import threading

def thread_func(param):
    # thread arg is param
    # do somthing....
    print("Do something")

t = []
for i in range(4):
    t.append(threading.Thread(target = thread_func, args = (i,)))
    t[i].start()

# Do something for main
# ...

for i in range(4):
    t[i].join()

print("End")