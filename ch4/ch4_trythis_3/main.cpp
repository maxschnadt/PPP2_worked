#include "../../std_lib_facilities.h"

int main ()
{
    for (int i = 'A'; i <= 'Z'; ++i)    // Write out integer values for uppercase letters
    {
        cout << char(i) << "\t" << i << "\n";
    }

    for (int i = 'a'; i <= 'z'; ++i)    // Write out integer values for lowercase letters
    {
        cout << char(i) << "\t" << i << "\n";
    }

    for (int i = '0'; i <= '9'; ++i)    // Write out integer values for digits
    {
        cout << char(i) << "\t" << i << "\n";
    }
    return 0;
}