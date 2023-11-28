# Input/output manipulators
We should `#include <iomanip>` first. Refer to [here](https://en.cppreference.com/w/cpp/io/manip).

* Hex Number
```c++
using namespace std;
cout << hex << 15 << endl; // f
cout << hex << showbase << 15 << endl; // 0xf 
cout << hex << showbase << uppercase << 15 << endl; // 0xF
cout << hex << showbase << uppercase << setw(4) << 15 << endl; // " 0xF" with one space behind the output
```

* Set flag with variable
```c++
using namespace std;
ios::fmtflags flag;
flag = ios::showpos | ios::showbase | ios::hex | ios::uppercase;
cout.flags(flag);
cout << 15 << endl; // 0xf
```

