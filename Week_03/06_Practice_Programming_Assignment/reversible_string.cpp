#include <iostream>
#include <algorithm>
using namespace std;
class ReversibleString {
public:
    ReversibleString(const string& s) {
        current_str = s;
    }
    ReversibleString() { current_str = ""; };
    void Reverse() {
        reverse(current_str.begin(), current_str.end());
    }
    string ToString() const {
        return current_str;
    }
private:
    string current_str;
};
int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}