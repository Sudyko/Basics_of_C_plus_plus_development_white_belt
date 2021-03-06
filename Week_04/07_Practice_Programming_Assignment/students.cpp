#include <iostream>
#include <vector>
using namespace std;
struct Student {
    string first_name;
    string last_name;
    int day;
    int month;
    int year;
};
int main() {
    int q;
    cin >> q;
    vector<Student> students;
    string first_name, last_name;
    int day, month, year;
    for (int i = 0; i < q; ++i) {
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back(Student{ first_name, last_name, day, month, year });
    }
    int n;
    cin >> n;
    for (n; n > 0; --n) {
        string arg;
        int student_id;
        cin >> arg >> student_id;
        student_id -= 1;
        if (arg == "name" && student_id >= 0 && student_id < q) {
            cout << students[student_id].first_name << " " << students[student_id].last_name << endl;
        }
        else if (arg == "date" && student_id >= 0 && student_id < q) {
            cout << students[student_id].day << "." << students[student_id].month << "." << students[student_id].year << endl;
        }
        else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}