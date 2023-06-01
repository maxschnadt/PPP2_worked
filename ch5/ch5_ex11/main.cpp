#include "../../std_lib_facilities.h"

int main()
{
    vector<int> fibonacci_numbers {1, 1};
    int num_fibonacci {};

    cout << "Enter the number of fibonacci elements you want to compute: ";
    cin >> num_fibonacci;

    if (!cin)
    {
        simple_error("You didn't enter a valid number.");
        return 1;
    }

    for (int i {0}; i < num_fibonacci; ++i)
    {
        cout << fibonacci_numbers[i] << " ";
        if ((i+1) % 4 == 0)
            cout << "\n";
        if (fibonacci_numbers[i] > INT32_MAX - fibonacci_numbers[i+1])
        {
            cout << "\nLargest possible fibonacci number reached: " << fibonacci_numbers[i+1] << "\n";
            break;
        }
        fibonacci_numbers.push_back(fibonacci_numbers[i] + fibonacci_numbers[i+1]);
    }

    return 0;
}
