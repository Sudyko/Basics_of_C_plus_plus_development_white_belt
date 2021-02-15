#include <iostream>
#include <map>
using namespace std;
void PrintBase(const map<string, string>& m) {
	if (m.size() != 0) {
		for (const auto& item : m) {
			cout << item.first << "/" << item.second << " ";
		}
		cout << endl;
	}
	else cout << "There are no countries in the world" << endl;
}
void ChangeCapital(map<string, string>& m, const string& country, const string& new_capital) {
	if (m.count(country) > 0) {
		if (m[country] == new_capital) cout << "Country " << country << " hasn't changed its capital" << endl;
		else cout << "Country " << country << " has changed its capital from " << m[country] << " to " << new_capital << endl;
	}
	else cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	m[country] = new_capital;
}
void RenameCountry(map<string, string>& m, const string& old_country_name, const string& new_country_name) {
	if (old_country_name == new_country_name || m.count(new_country_name) > 1)
		cout << "Incorrect rename, skip" << endl;
	else if (m[old_country_name] != "") {
		string temp = m[old_country_name];
		m.erase(old_country_name);
		m[new_country_name] = temp;
		cout << "Country " << old_country_name << " with capital " << temp << " has been renamed to " <<
			new_country_name << endl;
	}
}
void AboutCountry(map<string, string>& m, const string& country_name) {
	if (m.count(country_name) > 0) cout << "Country " << country_name << " has capital " << m[country_name] << endl;
	else cout << "Country " << country_name << " doesn't exist" << endl;
}
int main()
{
	int n;
	cin >> n;
	map<string, string> base;
	for (n; n > 0; --n) {
		string arg1, arg2;
		cin >> arg1;
		if (arg1 == "CHANGE_CAPITAL") {
			cin >> arg1 >> arg2;
			ChangeCapital(base, arg1, arg2);
		}
		else if (arg1 == "RENAME") {
			cin >> arg1 >> arg2;
			RenameCountry(base, arg1, arg2);
		}
		else if (arg1 == "ABOUT") {
			cin >> arg1;
			AboutCountry(base, arg1);
		}
		else if (arg1 == "DUMP") {
			PrintBase(base);
		}
	}
	return 0;
}