#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, c, d, x1, x2;
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (a == 0 && b == 0) {
        return 0;
    }
    else if (a == 0) {
        x1 = c / -b;
        cout << x1 << endl;
    }
    else if (d > 0) {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << x1 << " " << x2 << endl;;
    }
    else if (d == 0) {
        x1 = -(b / (2 * a));
        cout << x1 << endl;
    }
    else return 0;
}