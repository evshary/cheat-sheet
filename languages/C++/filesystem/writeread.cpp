#include <fstream>
#include <iostream>
#include <string>

#define FILENAME "myfile.txt"

int main() {
    // write file
    std::cout << "Write to file: " <<  FILENAME << std::endl;
    std::ofstream fout(FILENAME);
    fout << "key" << "\t" << "value" << std::endl;
    fout.close();
    // write file
    std::cout << "Read file " << FILENAME << std::endl;
    std::string k, v;
    std::ifstream fin(FILENAME);
    while(!fin.eof()) {
        fin >> k >> v;
    }
    std::cout << k << ":" << v << std::endl;
    fin.close();

    return 0;
}

