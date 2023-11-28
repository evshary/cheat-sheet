# string usage

We need `#include <string>` first.

* Declaration
```c++
string str1;  // empty string
string str2("test123");  // use const string to create
string str3(str2);  // use str2 to create
```

* empty, compare, size
```c++
// Empty or not
if (str1.empty())
  cout << "empty string" << endl;
// Compare
if (str1 == str2)
  cout << "str1 equals to str2" << endl;
// Access
for (int i = 0; i < str1.size(); i++)
  cout << str1[i] << endl;
```

* assign, append, insert, erase
```c++
// get 4 bytes from index 1 of str2 to str1
str1 = str1.assign(str2, 1, 4);
// append 4 bytes from index 1 of str2 to str1
str1 = str1.append(str2, 1, 4);
// insert "test123" from index 4
str1 = str1.insert(4, "test123")
```

* find & string::npos
```c++
string abc = "hello world";
size_t found = abc.found("hello");
if (found != string::npos) // string::npos stands for the end of string
  // do something... and found will be the position of abc
// Continue to find from "found" location
found = abc.find("world", found);
```

* find_first_of: such as strtok in C
```c++
// Replace !@#$ with *
size_t found = str1.find_first_of("!@#$");
while (found != string::npos) {
  str1[found] = '*';
  found=str1.find_first_of("!@#$", found+1);
}
```

* substr
```c++
string str = "abc->efg->hij->";
string delimiter = "->";
size_t pos, last_pos = 0;
string token;
while ((pos = str.find(delimiter, last_pos)) != string::npos) {
  token = str.substr(last_pos, pos-last_pos);
  cout << token << endl;
  last_pos = pos + delimiter.length();
}
```

* string/int conversion
```c++
string val = to_string(256);  // from 256 to string
int val = stoi("256");        // from string to 256
```

