#include <iostream>
#include <vector>
using namespace std;
vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> temp;
	for (auto w : words) {
		int size = w.size();
		if (size >= minLength) {
			if (size == 1) temp.push_back(w);
			for (int i = 0; i < size / 2; ++i) {
				if (w[i] != w[size - 1 - i])
					break;
				else if (i + 1 >= size / 2)
					temp.push_back(w);
			}
		}
	}
	return temp;
}
int main()
{
	return 0;
}