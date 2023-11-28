# template
Replace the specific token in the string content.

```py
import string
s = string.Template("I have ${item1} and ${item2}.")
# Use dictionary
mydict = {'item1':'coin', 'item2':'dice'}
print(s.safe_substitute(mydict))
# Only part of variables
print(s.safe_substitute(item1='frog'))
```

# iterate alphebat

```ascii_lowercase
import string
for ch in string.ascii_lowercase:
  print(ch)
```
