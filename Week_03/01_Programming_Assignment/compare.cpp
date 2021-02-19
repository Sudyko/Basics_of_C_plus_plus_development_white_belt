#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void PrintVector(const vector<int>& v) {
	for (const auto& item : v) {
		cout << item << " ";
	}
	cout << endl;
}
int main()
{
	int n, a;
	cin >> n;
	vector<int> nums;
	for (n; n > 0; --n) {
		cin >> a;
		nums.push_back(a);
	}
	sort(begin(nums), end(nums), [](const int& x, const int& y) {
		return abs(x) < abs(y);
		});
	PrintVector(nums);
	return 0;
}