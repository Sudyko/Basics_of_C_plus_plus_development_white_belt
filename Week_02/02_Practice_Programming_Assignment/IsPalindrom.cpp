#include <iostream>
using namespace std;
bool IsPalindrom(string str) {
	int size = str.size();
	for (int i = 0; i < size / 2; ++i) {
		if (str[i] == str[size - 1 - i]);
		else return 0;
	}
	return 1;
}
int main()
{
	string s;
	cin >> s;
	cout << IsPalindrom(s);
	return 0;
}