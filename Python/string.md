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
