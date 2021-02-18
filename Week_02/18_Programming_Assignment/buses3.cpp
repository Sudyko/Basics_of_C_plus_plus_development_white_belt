#include <iostream>
#include <set>
#include <map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	map<int, set<string>> base;
	for (n; n > 0; --n) {
		set<string> list_of_stops;
		int arg1;
		string arg2;
		cin >> arg1;
		for (arg1; arg1 > 0; --arg1) {
			cin >> arg2;
			list_of_stops.insert(arg2);
		}
		arg1 = 0;
		int i = 0;
		for (i; i < base.size(); ++i) {
			if (base[i] == list_of_stops) {
				arg1 += 1;
				break;
			}
		}
		if (arg1 != 0)
			cout << "Already exists for " << i + 1 << endl;
		else {
			arg1 = base.size();
			cout << "New bus " << arg1 + 1 << endl;
			base[arg1] = list_of_stops;
		}
	}
	return 0;
}