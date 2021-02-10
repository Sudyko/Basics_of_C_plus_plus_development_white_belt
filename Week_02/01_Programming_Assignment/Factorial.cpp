#include <iostream>
using namespace std;
int Factorial(int arg) {
	int temp = 1;
	for (arg; arg > 0; --arg) {
		temp *= arg;
	}
	return temp;
	
}
int main()
{
	int a;
	cin >> a;
	cout << Factorial(a);
	return 0;
}