#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
    const int width = 10;
    ifstream input("input.txt");
    if (input) {
        int a, b;
        input >> a >> b;
        for (int i = 0; i < a; ++i) {
            for (int l = 0; l < b; l++) {
                int x;
                input >> x;
                input.ignore(1);
                cout << setw(10) << x;
                if (l != b - 1) {
                    cout << " ";
                }
            }
            if (i != a - 1) {
                cout << endl;
            }
        }
    }
    return 0;
}