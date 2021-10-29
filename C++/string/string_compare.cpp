#include <string>
#include <iostream>

using namespace std;

int startswith(string str, string substr)
{
    return (str.find(substr)==0)?1:0;
}

int endswith(string str, string substr)
{
    return (str.rfind(substr)==(str.length()-substr.length()))?1:0;
}

int main()
{
    string mystr = "This is example";
    string first_substr = "This";
    string last_substr = "example";

    if (startswith(mystr, first_substr)) {
        cout << mystr << " starts with " << first_substr << endl;
    }

    if (endswith(mystr, last_substr)) {
        cout << mystr << " ends with " << last_substr << endl;
    }

    return 0;
}
