#include <iostream>
#include <vector>
using namespace std;
void Add(vector<string>& v, const string& point) {
	v.push_back(point);
}
void Dump(const vector<string>& v) {
	cout << v.size() << " ";
	for (string tmp : v) {
		cout << tmp << " ";
	}
	cout << endl;
}
void Next(vector<vector<string>>& main_month, const int& next_len) {
	vector<vector<string>> new_month(next_len);
	if (main_month.size() > next_len) {
		for (int l = 0; l < main_month.size(); ++l) {
			if (l > next_len - 1)
				new_month[next_len - 1].insert(new_month[next_len - 1].end(), begin(main_month[l]), end(main_month[l]));
			else
				new_month[l].insert(new_month[l].end(), begin(main_month[l]), end(main_month[l]));
		}
	}
	else {
		for (int l = 0; l < next_len; ++l) {
			if (l < main_month.size())
				new_month[l].insert(new_month[l].end(), begin(main_month[l]), end(main_month[l]));
		}
	}
	main_month = new_month;
}
const vector<int> MONTH_LENGTH = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
	int n, arg;
	int i = 0;
	vector<vector<string>> current_month(MONTH_LENGTH[i]);
	cin >> n;
	for (n; n != 0; --n) {
		string operation;
		cin >> operation;
		if (operation == "ADD") {
			cin >> arg >> operation;
			Add(current_month[arg - 1], operation);
		}
		else if (operation == "DUMP") {
			cin >> arg;
			Dump(current_month[arg - 1]);
		}
		else if (operation == "NEXT") {
			if (i != 11) i += 1;
			else i = 0;
			Next(current_month, MONTH_LENGTH[i]);
		}
	}
	return 0;
}