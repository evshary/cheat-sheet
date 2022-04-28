# stack

```c++
#include <stack>
using namespace std;

int main(){
  stack<int> s;
  s.push(1); // [1]
  s.push(2); // [2,1]
  s.push(3); // [3,2,1]
  for(int i=0; i < s.size() ; i++) {
    cout << s.top() << endl; // output 3 2 1
    s.pop();
  }
  return 0;
}
```
