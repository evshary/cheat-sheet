#!/usr/bin/python3

import pickle

class role:
    def __init__(self, name):
        self.name = name
    
    def getName(self):
        return self.name
    
myrole = role("new_name")

with open('my.save', 'wb') as f:
    f.write(pickle.dumps(myrole))

with open('my.save', 'rb') as f:
    newrole = pickle.loads(f.read())

print("role name = ", newrole.getName())