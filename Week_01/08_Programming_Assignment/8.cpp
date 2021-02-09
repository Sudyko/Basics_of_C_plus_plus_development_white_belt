#include <iostream>
using namespace std;
int evcl(int x, int y) {
	if (y == 0)
		return x;
	return evcl(y, x % y);
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << evcl(a, b);
	return 0;
}