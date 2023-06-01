#include "../../std_lib_facilities.h"

int main()
{
    vector<int> primes {2};

    cout << "Enter the number of primes you want to find: ";
    int num_primes {};
    cin >> num_primes;

    if (num_primes <= 0)
    {
        cout << "No primes found.\n";
    }
    else if (num_primes > 0)
    {
        int temp {2};
        bool is_prime {true};

        while (primes.size() < num_primes)
        {
            for (int prime_number: primes)
            {
                if (temp % prime_number == 0)
                {
                    is_prime = false;
                }
            }

            if (is_prime)
            {
                primes.push_back(temp);
            }

            is_prime = true;
            ++temp;
        }

        for (int number: primes)
        {
            cout << number << " is prime.\n";
        }
    }

    return 0;
}
