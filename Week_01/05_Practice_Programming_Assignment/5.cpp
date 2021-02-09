#include <iostream>
using namespace std;
int main()
{
	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;
	if (n > b) {
	x = n - (n / 100) * y;
	cout << x << endl;
	}
	else if (n > a) {
		y = n - (n / 100) * x;
		cout << y << endl;
	}
	else cout << n << endl;
	return 0;
}