#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n;
	cin >> n;
	set<string> list;
	for (n; n > 0; --n) {

		string arg1;
		cin >> arg1;
		list.insert(arg1);
	}
	cout << list.size() << endl;
	return 0;
}