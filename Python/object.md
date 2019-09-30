# `__enter__` and `__exit__`
We can use `__enter__` and `__exit__` to support `with` statement.
```py
class TestFile:
    def __init__(self, filename):
        print("I'm in __init__")
        self.filename = filename
    def __enter__(self):
        print("I'm in __enter__")
        self.handler = open(self.filename, 'r')
        return self.handler
    def __exit__(self, type, value, trace):
        print("I'm in __exit__")
        self.handler.close()
with TestFile('test.txt') as f:
    print("Do something here")
```
The output should be below:
```
I'm in __init__
I'm in __enter__
Do something here
I'm in __exit__
```