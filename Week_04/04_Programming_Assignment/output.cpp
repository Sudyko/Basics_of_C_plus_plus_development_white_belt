#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    const string path = "output.txt";
    ifstream input("input.txt");
    if (input) {
        string line;
        ofstream output(path);
        while (getline(input, line)) {
            output << line << endl;
        }
    }
    return 0;
}