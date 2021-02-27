#include <iostream>
#include <vector>
using namespace std;
class Incognizable {
public:
    Incognizable() {}
    Incognizable(const int& a, ...) {}
private:
    vector<int> nums;
};
int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = { 0 };
    Incognizable d = { 0, 1 };
    return 0;
}