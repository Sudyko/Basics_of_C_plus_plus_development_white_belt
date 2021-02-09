#include <iostream>
using namespace std;
void Bin(int a) {
	if (a == 0) return;
	Bin(a / 2);
	cout << a % 2;
}
int main()
{
	int a;
	cin >> a;
	Bin(a);
	return 0;
}