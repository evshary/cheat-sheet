# regular expression

Run `import re` before using.

cheat-sheet:

![image](https://user-images.githubusercontent.com/456210/137049942-30a87beb-b7d9-44e5-96a9-30e8da388baf.png)

## search pattern

* search: **Used in most condition**. Find the first matched pattern in the string.
* match: Find the first pattern in the string but find from the start of the string.
* findall: Find all the patterns in the string and return **list**.
* finditer: Find all the patterns in the string and return **iterator**.

### re.search

* Find matched pattern

```py
import re
# We want to get time only
today_string = "2021-10.13 08:00:00"
print(re.search(r"\d+:\d+:\d+", today_string).group(0))
# Output: 08:00:00
```

* Get substring based on matched pattern

```py
import re
# We want to get all the content (including space and nonspace char) between <tag> and </tag>
test_string = "------------- <tag>Hello World</tag> -------------"
print(re.search(r"<\w+>([\s\S]+)</\w+>", test_string).group(0))
# Output: <tag>Hello World</tag>
print(re.search(r"<\w+>([\s\S]+)</\w+>", test_string).group(1))
# Output: Hello World
```

### re.findall

* List all matched pattern

```py
import re
# We want to get the character (including a-z,A-Z,0-9,_) between XML tag
tag_content = "<tag1>test1</tag1><tag2>test2</tag2><tag3>test3</tag3>"
print(re.findall(r"<\w+>([\w]+)</\w+>", tag_content))
# Output: ['test1', 'test2', 'test3']
```

## replace pattern

* Replace substring based on matched pattern

```py
import re
# We want to replace test to abc
content = "test1,test2,test3"
print(re.sub("test", "abc", content))
# Output: abc1,abc2,abc3
```

* Reverse tag of matched pattern

```py
import re
# We want to reverse <tag> and </tag>
tag_content = "<tag1>test1</tag1><tag2>test2</tag2><tag3>test3</tag3>"
print(re.sub(r"(<\w+>)([\w]+)(</\w+>)", r"\3\2\1", tag_content))
# Output: </tag1>test1<tag1></tag2>test2<tag2></tag3>test3<tag3>
```

# Reference

* [regex101](https://regex101.com/): We can debug the expression here.
* [爬蟲資料清洗 - re 正則表達式](https://ithelp.ithome.com.tw/articles/10232174): Basic usage
