#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
vector<string> FindNameByHistory(const map<int, string>& names_by_year, const int& year) {
    vector<string> names;
    for (const auto& item : names_by_year) {
        if (item.first <= year && (names.empty() || names.back() != item.second)) {
            names.push_back(item.second);
        }
    }
    return names;
}
string VectorToString(const vector<string>& v){
    string result = "";
    if (v.size() > 2) {
        for (int i = v.size() - 2; i > 0; --i) {
            result += v[i];
            result += ", ";
        }
        result += v[0];
    }
    else result += v[0];
    return result;
}
class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        surnames[year] = last_name;
    }
    string GetFullName(int year) {
        string current_name = FindYearByName(names, year);
        string current_surname = FindYearByName(surnames, year);
        if (current_name.empty() && current_surname.empty()) {
            return "Incognito";
        }
        else if (current_name.empty())
            return current_surname + " with unknown first name";
        else if (current_surname.empty())
            return current_name + " with unknown last name";
        else
            return current_name + " " + current_surname;
    }
    string GetFullNameWithHistory(int year) {
        vector<string> NamesByHistory = FindNameByHistory(names, year);
        vector<string> SurnamesByHistory = FindNameByHistory(surnames, year);
        string current_name = FindYearByName(names, year);
        string current_surname = FindYearByName(surnames, year);
        if (current_name.empty() && current_surname.empty()) {
            return "Incognito";
        }
        else if (current_name.empty()) {
            if (SurnamesByHistory.size() > 1) {
                return current_surname + " (" + VectorToString(SurnamesByHistory) + ") " + "with unknown first name";
            }
            return current_surname + " with unknown first name";
        }
        else if (current_surname.empty()) {
            if (NamesByHistory.size() > 1) {
                return current_name + " (" + VectorToString(NamesByHistory) + ") " + "with unknown last name";
            }
            return current_name + " with unknown last name";
        }
        else {
            if (SurnamesByHistory.size() > 1 && NamesByHistory.size() > 1) {
                return current_name + " (" + VectorToString(NamesByHistory) + ") " + current_surname + " (" + VectorToString(SurnamesByHistory) + ")";
            }
            else if (NamesByHistory.size() > 1) {
                return current_name + " (" + VectorToString(NamesByHistory) + ") " + current_surname;
            }
            else if (SurnamesByHistory.size() > 1) {
                return current_name + " " + current_surname + " (" + VectorToString(SurnamesByHistory) + ")";
            }
            return current_name + " " + current_surname;
        }
    }
private:
    string FindYearByName(const map<int, string>& names, const int& year) {
        string name;
        for (const auto& item : names) {
            if (item.first <= year) {
                name = item.second;
            }
            else break;
        }
        return name;
    }
    map<int, string> names;
    map<int, string> surnames;
};
int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}