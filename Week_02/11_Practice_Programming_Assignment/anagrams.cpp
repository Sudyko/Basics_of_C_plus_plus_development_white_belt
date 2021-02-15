#include <iostream>
#include <map>
using namespace std;
void BuildCharCounters(const map<string, string>& m) {
	map<char, int> main, check;
	for (const auto& item : m) {
		if (item.first.size() == item.second.size()) {
			for (int i = 0; i < item.first.size(); ++i) {
				++main[item.first[i]];
				++check[item.second[i]];
			}
			if (main == check) {
				cout << "YES" << endl;
			}
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	for (n; n > 0; --n) {
		string a, b;
		cin >> a >> b;
		map<string, string> anagram = { {a, b} };
		BuildCharCounters(anagram);
	}
	return 0;
}