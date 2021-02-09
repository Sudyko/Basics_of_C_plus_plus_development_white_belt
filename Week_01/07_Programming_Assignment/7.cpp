#include <iostream>
using namespace std;
int main()
{
	string str;
	int index = 0;
	int tmp = 0;
	cin >> str;
	for (auto ch : str) {
		if (ch == 'f') {
			++tmp;
			if (tmp == 2) {
				cout << index;
			}
		}
		++index;
	}
	if (tmp == 1) {
		cout << -1;
	}
	else if (tmp == 0) {
		cout << -2;
	}
	return 0;
}