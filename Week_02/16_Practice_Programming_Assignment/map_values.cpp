#include <iostream>
#include <set>
#include <map>
using namespace std;
set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> map_values;
    for (const auto& item : m) {
        map_values.insert(item.second);
    }
    return map_values;
}
int main()
{
    set<string> values = BuildMapValuesSet({
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}
        });

    for (const string& value : values) {
        cout << value << endl;
    }
	return 0;
}