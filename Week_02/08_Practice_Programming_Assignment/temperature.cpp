#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int sum = 0;
	int i;
	cin >> i;
	vector<int> deg(i);
	vector<int> result;
	for (int& d : deg) {
		cin >> d;
		sum += d;
	}
	sum /= i;
	for (i = 0; i < deg.size(); ++i) {
		if (deg[i] > sum) {
			result.push_back(i);
		}
	}
	cout << result.size() << endl;
	for (int& r : result) {
		cout << r << " ";
	}
	return 0;
}