#include <iostream>
#include <vector>
using namespace std;
void Reverse(vector<int>& v){
	int size = v.size();
	for (int i = 0; i < size / 2; ++i) {
		int tmp = v[i];
		v[i] = v[size - i - 1];
		v[size - i - 1] = tmp;
	}
}
int main()
{
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);
	for (auto num : numbers) {
		cout << num << " ";
	}
	return 0;
}