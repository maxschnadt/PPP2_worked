#include "../../std_lib_facilities.h"

int main() {
    int user_number {50};
    char user_choice {};
    vector<int> decrement_numbers {25, 13, 6, 3, 2, 1};

    for (int i {0}; i < 6; ++i)
    {
        cout << "Is your number smaller than " << user_number << "? (y for yes, n for no)\n";
        cin >> user_choice;

        if (user_choice == 'y')
        {

            user_number -= decrement_numbers[i];
        }
        else if (user_choice == 'n')
        {
            user_number += decrement_numbers[i];
        }
    }

    cout << "Is your number smaller than " << user_number << "?\n";
    cin >> user_choice;

    if (user_choice == 'y')
    {
        user_number -= 1;
    }
    else if (user_choice == 'n')
    {
        user_number = user_number;
    }

    cout << "Your number is " << user_number << ".\n";

    return 0;
}
