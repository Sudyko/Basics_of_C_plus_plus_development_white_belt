#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void PrintVector(const vector<string>& v) {
	for (const string& item : v) {
		cout << item << " ";
	}
	cout << endl;
}
void FindBusesForStop(map<string, vector<string>>& m, const string& stop_name, const vector<string> order) {
	vector<string> all_correct_stops;
	for (const auto& item : order) {
		if (find(m[item].begin(), m[item].end(), stop_name) != m[item].end())
			all_correct_stops.push_back(item);
	}
	if (all_correct_stops.size() != 0) {
		PrintVector(all_correct_stops);
	}
	else cout << "No stop" << endl;
}
void FindStopsForBus(map<string, vector<string>>& m, const string& bus_for_search, const vector<string>& order) {
	if (m.count(bus_for_search) != 0) {
		for (const auto& stop : m[bus_for_search]) {
			vector<string> all_buses_for_stop;
			cout << "Stop " << stop << ": ";
			for (const auto& bus : order) {
				if ((find(m[bus].begin(), m[bus].end(), stop) != m[bus].end()) && bus != bus_for_search) {
					all_buses_for_stop.push_back(bus);
				}
			}
			if (all_buses_for_stop.size() != 0)
				PrintVector(all_buses_for_stop);
			else cout << "no interchange" << endl;
		}
	}
	else cout << "No bus" << endl;
}
void PrintBase(const map<string, vector<string>> m) {
	if (m.size() != 0) {
		for (const auto& item : m) {
			cout << "Bus " << item.first << ": ";
			PrintVector(item.second);
		}
	}
	else cout << "No buses" << endl;
}
int main()
{
	int n;
	cin >> n;
	map<string, vector<string>> base;
	vector<string> correct_order;
	for (n; n > 0; --n) {
		string arg1, arg2;
		cin >> arg1;
		if (arg1 == "NEW_BUS") {
			cin >> arg1;
			vector<string> stop_names;
			int stop_count;
			cin >> stop_count;
			for (int i = 0; i < stop_count; ++i) {
				cin >> arg2;
				stop_names.push_back(arg2);
			}
			base[arg1] = stop_names;
			correct_order.push_back(arg1);
		}
		else if (arg1 == "BUSES_FOR_STOP") {
			cin >> arg1;
			FindBusesForStop(base, arg1, correct_order);
		}
		else if (arg1 == "STOPS_FOR_BUS") {
			cin >> arg1;
			FindStopsForBus(base, arg1, correct_order);
		}
		else if (arg1 == "ALL_BUSES") {
			PrintBase(base);
		}
	}
	return 0;
}