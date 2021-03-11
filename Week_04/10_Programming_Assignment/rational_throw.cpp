#include <iostream>
using namespace std;
int evcl(const int& x, const int& y) {
    if (y == 0)
        return x;
    return evcl(y, x % y);
}
int FindNok(const int& a, const int& b) {
    return a * b / evcl(a, b);
}
class Rational {
public:
    Rational() {}
    Rational(int a, int b) {
        if (b == 0) {
            throw invalid_argument("invalid argument");
        }
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
Rational operator + (const Rational& lhs, const Rational& rhs) {
    int nok = FindNok(lhs.Denominator(), rhs.Denominator());
    if (lhs.Denominator() > nok) {
        int new_numerator = lhs.Denominator() / nok * lhs.Numerator() +
            rhs.Denominator() / nok * rhs.Numerator();
        return Rational(new_numerator, nok);
    }
    else {
        int new_numerator = nok / lhs.Denominator() * lhs.Numerator() +
            nok / rhs.Denominator() * rhs.Numerator();
        return Rational(new_numerator, nok);
    }
}
Rational operator - (const Rational& lhs, const Rational& rhs) {
    int nok = FindNok(lhs.Denominator(), rhs.Denominator());
    if (lhs.Denominator() > nok) {
        int new_numerator = lhs.Denominator() / nok * lhs.Numerator() -
            rhs.Denominator() / nok * rhs.Numerator();
        return Rational(new_numerator, nok);
    }
    else {
        int new_numerator = nok / lhs.Denominator() * lhs.Numerator() -
            nok / rhs.Denominator() * rhs.Numerator();
        return Rational(new_numerator, nok);
    }
}
Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator());
}
Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("domain error");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}
bool operator == (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}
bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}
ostream& operator << (ostream& stream, const Rational& r) {
    return stream << r.Numerator() << '/' << r.Denominator();
}
istream& operator >> (istream& stream, Rational& r) {
    int a, b;
    char c;
    stream >> a >> c >> b;
    if (stream && c == '/') {
        r = Rational(a, b);
    }
    return stream;
}