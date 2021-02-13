#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Worry(vector<bool>& v, const int& i) {
	if (v[i] == true) v[i] = false;
	else v[i] = true;
}
void Come(vector<bool>& v, const int& num) {
	v.resize(v.size() + num, false);
}
void WorryCount(const vector<bool>& v) {
	cout << count(begin(v), end(v), true) << endl;
}
int main()
{
	int n, arg;
	cin >> n;
	vector<bool> line;
	for (n; n != 0; --n) {
		string s;
		cin >> s;
		if (s == "WORRY" || s == "QUIET") {
			cin >> arg;
			Worry(line, arg);
		}
		else if (s == "COME") {
			cin >> arg;
			Come(line, arg);
		}
		else if (s == "WORRY_COUNT") {
			WorryCount(line);
		}
	}
	return 0;
}