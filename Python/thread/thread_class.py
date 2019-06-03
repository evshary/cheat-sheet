import threading

class ThreadClass(threading.Thread):
    def __init__(self, param):
        threading.Thread.__init__(self)
        self.param = param

    def run(self):
        # thread arg is self.param
        # do somthing....
        print("Do something")

t = []
for i in range(4):
    t.append(ThreadClass(i))
    t[i].start()

# Do something for main
# ...

for i in range(4):
    t[i].join()

print("End")