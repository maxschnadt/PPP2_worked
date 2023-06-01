#include "../../std_lib_facilities.h"

int main()
{
    int number_of_integers {};
    cout << "Enter the values you want to sum: ";
    cin >> number_of_integers;

    if (!cin)
    {
        simple_error("You didn't enter an integer.");
        return 1;
    }

    cout << "Please enter some integers and terminate with '|': \n";
    vector<int> numbers {};
    for (int temp; cin>>temp;)
    {
        numbers.push_back(temp);
    }

    if (numbers.size() < number_of_integers)
    {
        simple_error("There are not enough integers to sum over.");
        return 1;
    }

    int sum {0};
    for (int i {0}; i < number_of_integers; ++i)
    {
        if (numbers[i] > 0 && sum > (INT32_MAX - numbers[i]))
        {
            simple_error("Sum will be larger than the largest possible integer.");
            return 1;
        }
        if (numbers[i] < 0 && sum < (INT32_MIN - numbers[i]))
        {
            simple_error("Sum will be smaller than the most negative possible integer.");
            return 1;
        }
        sum += numbers[i];
    }


    cout << "The sum of the first " << number_of_integers << " numbers ( ";
    for (int i {0}; i < number_of_integers; ++i) cout << numbers[i] << " ";
    cout << ") is " << sum << ".\n";
    return 0;
}
