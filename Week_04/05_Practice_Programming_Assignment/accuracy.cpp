#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
    ifstream input("input.txt");
    if (input) {
        double d_num;
        cout << fixed << setprecision(3);
        while (input >> d_num) {
            cout << d_num << endl;
        }
    }
    return 0;
}