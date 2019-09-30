# namedtuple
If we want to access tuple, we need to use index, which is not friendly.
namedtuple can provide as the function like `struct` in C, which provides name for each members.

```py
from collections import namedtuple
Employee = namedtuple("Employee", ["name", "age", "phone"])
employee = Employee("John", 30, '0123456')
print(employee.name)
print(employee.age)
print(employee.phone)
```