#include "../../std_lib_facilities.h"

int main()
{
    vector<int> primes {2};

    bool is_prime {true};

    cout << "Enter the largest number up to which you want to find all primes: ";
    int max_prime {};
    cin >> max_prime;

    for (int i {1}; i < max_prime; ++i)
    {
        for (int j: primes)
        {
            if (i % j == 0 || i == 1)
            {
                is_prime = false;
            }
        }

        if (is_prime)
        {
            primes.push_back(i);
        }

        is_prime = true;
    }

    for (int number: primes)
    {
        cout << number << " is prime.\n";
    }

    cout << "There are " << primes.size() << " primes between 1 and " << max_prime << ".\n";

    return 0;
}
