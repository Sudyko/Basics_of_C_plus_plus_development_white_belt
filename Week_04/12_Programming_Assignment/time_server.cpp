#include <iostream>
using namespace std;

string AskTimeServer() {
    throw system_error(error_code());
    return "01:02:03";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        }
        catch (const system_error& se) {
            cout << se.what() << endl;
        }
        return last_fetched_time;
    }
private:
    string last_fetched_time = "00:00:00";
};
int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}