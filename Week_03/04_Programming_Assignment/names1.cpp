#include <iostream>
#include <map>
using namespace std;
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
        cout << person.GetFullName(year) << endl;
    }
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}