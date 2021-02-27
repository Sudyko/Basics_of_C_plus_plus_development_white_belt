#include <iostream>
using namespace std;
struct Specialization {
    string value;
    explicit Specialization(const string& new_val) {
        value = new_val;
    }
};
struct Course {
    string value;
    explicit Course(const string& new_val) {
        value = new_val;
    }
};
struct Week {
    string value;
    explicit Week(const string& new_val) {
        value = new_val;
    }
};
struct LectureTitle {
    string specialization, course, week;
    LectureTitle(const Specialization& new_spec, const Course& new_course, const Week& new_week) {
        specialization = new_spec.value;
        course = new_course.value;
        week = new_week.value;
    }
};

int main() {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );
    return 0;
}
