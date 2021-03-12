#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>

using namespace std;

class Date {
public:
    Date(const int& new_year, const int& new_month, const int& new_day) {
        year = new_year;
        if (new_month > 12 || new_month < 1) {
            throw logic_error("Month value is invalid: " + to_string(new_month));
        }
        month = new_month;
        if (new_day > 31 || new_day < 1) {
            throw logic_error("Day value is invalid: " + to_string(new_day));
        }
        day = new_day;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year, month, day;
};

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() < rhs.GetYear()) {
        return true;
    }
    else if (lhs.GetYear() > rhs.GetYear()) {
        return false;
    }
    else if (lhs.GetYear() == rhs.GetYear()) {
        if ((lhs.GetMonth() * 31 + lhs.GetDay()) < (rhs.GetMonth() * 31 + rhs.GetDay())) {
            return true;
        }
        else
            return false;
    }
}

ostream& operator << (ostream& stream, const Date& date) {
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << '-';
    stream << setw(2) << date.GetMonth() << '-';
    stream << setw(2) << date.GetDay();
    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        event_list[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (event_list.count(date) > 0 && event_list[date].count(event) > 0) {
            event_list[date].erase(event);
            return true;
        }
        return false;
    }
    int DeleteDate(const Date& date) {
        if (event_list.count(date) == 0) {
            return 0;
        }
        else {
            int count = event_list[date].size();
            event_list.erase(date);
            return count;
        }
    }

    set<string> Find(const Date& date) const {
        if (event_list.count(date) > 0) {
            return event_list.at(date);
        }
        else {
            return {};
        }
    }

    void Print() const {
        for (const auto& item : event_list) {
            for (const string& s : item.second) {
                cout << item.first << " " << s << endl;
            }
        }
    }
private:
    map<Date, set<string>> event_list;
};

Date ParseDate(const std::string& date) {
    stringstream date_stream(date);
    bool flag = true;

    int year;
    flag = flag && (date_stream >> year);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    flag = flag && (date_stream >> month);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    flag = flag && (date_stream >> day);
    flag = flag && date_stream.eof();

    if (!flag) {
        throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

int main() {
    try {
        Database db;
        string command;
        while (getline(cin, command)) {
            stringstream ss(command);
            string operation;
            ss >> operation;
            if (operation == "Add") {
                string date_for_add, event;
                ss >> date_for_add >> event;
                Date date = ParseDate(date_for_add);
                db.AddEvent(date, event);
            }
            else if (operation == "Del") {
                string date_for_del;
                ss >> date_for_del;
                string event;
                if (!ss.eof()) {
                    ss >> event;
                }
                Date date = ParseDate(date_for_del);
                if (event.empty()) {
                    int count = db.DeleteDate(date);
                    cout << "Deleted " << count << " events" << endl;
                }
                else {
                    if (db.DeleteEvent(date, event)) {
                        cout << "Deleted successfully" << endl;
                    }
                    else {
                        cout << "Event not found" << endl;
                    }
                }
            }
            else if (operation == "Find") {
                string date_for_find;
                ss >> date_for_find;
                Date date = ParseDate(date_for_find);
                for (const string& item : db.Find(date)) {
                    cout << item << endl;
                }
            }
            else if (operation == "Print") {
                db.Print();
            }
            else if(operation.empty()) {
            }
            else {
                throw runtime_error("Unknown command: " + operation);
            }
        }
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}