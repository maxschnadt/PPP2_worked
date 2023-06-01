#include "../../std_lib_facilities.h"

int main()
{
    constexpr double yen_to_dollar {0.0076};
    constexpr double kroner_to_dollar {0.095};
    constexpr double pounds_to_dollar {1.24};
    double amount {0};
    char currency {' '};

    cout << "Please enter an amount of money followed by a currency (y, k or p):\n";
    cin >> amount >> currency;

    switch(currency)
    {
        case 'y':
            cout << amount << " yen are " << amount * yen_to_dollar << " dollar.\n";
            break;
        case 'k':
            cout << amount << " kroner are " << amount * kroner_to_dollar << " dollar.\n";
            break;
        case 'p':
            cout << amount << " pounds are " << amount * pounds_to_dollar << " dollar.\n";
            break;
        default:
            cout << "You didn't enter a valid currency.\n";
            break;
    }

    return 0;
}
