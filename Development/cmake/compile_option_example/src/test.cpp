#include <iostream>

using namespace std;

int main() {
    cout << PROJECTS << endl; // should be defined in CMake.
#ifdef NEW_VERSION
    cout << "new version" << endl;
#else
    cout << "old version" << endl;
#endif
    return 0;
}
