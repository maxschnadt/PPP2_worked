#include "../../std_lib_facilities.h"

int main()
{
    vector<int> primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    vector<int> suspected_primes {};

    bool is_prime {false};

    for (int i {1}; i < 100; ++i)
    {
        for (int j: primes)
        {
            if (i == j)
            {
                is_prime = true;
            }
        }

        if (is_prime)
        {
            suspected_primes.push_back(i);
        }

        is_prime = false;
    }

    for (int prime: suspected_primes)
    {
        cout << prime << " is prime.\n";
    }

    return 0;
}
