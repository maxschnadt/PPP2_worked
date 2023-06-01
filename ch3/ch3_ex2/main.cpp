#include "../../std_lib_facilities.h"

int main() {
    cout << "Please enter the number of miles: ";
    double distance_miles {};
    cin >> distance_miles;
    double distance_kilometers {distance_miles * 1.609};
    cout << distance_miles << " miles are " << distance_kilometers << " kilometers.\n";
    return 0;
}
