#include <iostream>
using namespace std;

int evcl(const int& x, const int& y) {
    if (y == 0)
        return x;
    return evcl(y, x % y);
}

class Rational {
public:
    Rational() {}
    Rational(int a, int b) {
        int nod = abs(evcl(a, b));
        if (a < 0 && b < 0) {
            numerator = -a / nod;
            denominator = -b / nod;
        }
        else if (a >= 0 && b < 0) {
            numerator = -a / nod;
            denominator = -b / nod;
        }
        else {
            numerator = a / nod;
            denominator = b / nod;
        }
    }
    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }
    
private:
    int numerator = 0;
    int denominator = 1;
};