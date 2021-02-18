#include <iostream>
#include <set>
#include <map>
using namespace std;
void AddSynPair(map<string, set<string>>& m, const string& word1, const string& word2) {
	m[word1].insert(word2);
	m[word2].insert(word1);
}
void CountSyns(map<string, set<string>>& m, const string& check_word) {
	cout << m[check_word].size() << endl;
}
void CheckForSyn(map<string, set<string>>& m, const string& word1, const string& word2) {
	if (m[word1].count(word2) > 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main()
{
	int n;
	cin >> n;
	string arg1, arg2;
	map<string, set<string>> data;
	for (n; n > 0; --n) {
		cin >> arg1;
		if (arg1 == "ADD") {
			cin >> arg1 >> arg2;
			AddSynPair(data, arg1, arg2);
		}
		else if (arg1 == "COUNT") {
			cin >> arg1;
			CountSyns(data, arg1);
		}
		else if (arg1 == "CHECK") {
			cin >> arg1 >> arg2;
			CheckForSyn(data, arg1, arg2);
		}
	}
	return 0;
}