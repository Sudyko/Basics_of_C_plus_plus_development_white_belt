#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void PrintVector(const vector<string>& v) {
	for (const auto& item : v) {
		cout << item << " ";
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	vector<string> words;
	for (n; n > 0; --n) {
		string arg;
		cin >> arg;
		words.push_back(arg);
	}
	sort(begin(words), end(words), [](const string& str1, const string& str2) {
		string s1 = "";
		string s2 = "";
		for (int i = 0; i < str1.size(); ++i) {
			s1 += tolower(str1[i]);
		}
		for (int i = 0; i < str2.size(); ++i) {
			s2 += tolower(str2[i]);
		}
		return s1 < s2;
		});
	PrintVector(words);
	return 0;
}