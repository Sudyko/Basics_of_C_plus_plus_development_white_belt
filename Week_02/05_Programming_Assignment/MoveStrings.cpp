#include <iostream>
#include <vector>
using namespace std;
void MoveStrings(vector<string>& a, vector<string>& b) {
	for (string str : a) b.push_back(str);
	a.clear();
}
int main()
{
	vector<string> source = { "a", "b", "c" };
	vector<string> destination = { "z" };
	MoveStrings(source, destination);
	for (auto str : source) {
		cout << str << " ";
	}
	cout << endl;
	for (auto str : destination) {
		cout << str << " ";
	}
	return 0;
}