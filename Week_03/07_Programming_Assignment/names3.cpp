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
string VectorToString(const vector<string>& v) {
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
    Person(const string& first_name, const string& last_name,
        int new_birth_year) {
        birth_year = new_birth_year;
        names[birth_year] = first_name;
        surnames[birth_year] = last_name;
    }
    void ChangeFirstName(int year, const string& first_name) {
        if (year >= birth_year) {
            names[year] = first_name;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        if (year >= birth_year) {
            surnames[year] = last_name;
        }
    }
    string GetFullName(int year) const {
        if (year < birth_year) {
            return "No person";
        }
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
    string GetFullNameWithHistory(int year) const {
        if (year < birth_year) {
            return "No person";
        }
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
    string FindYearByName(const map<int, string>& names, const int& year) const {
        string name;
        for (const auto& item : names) {
            if (item.first <= year) {
                name = item.second;
            }
            else break;
        }
        return name;
    }
    int birth_year;
    map<int, string> names;
    map<int, string> surnames;
};
int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}