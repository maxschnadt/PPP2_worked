#include "../../std_lib_facilities.h"

int main()
{
    int i {'a'};

    while (i<='z')
    {
        cout << char(i) << '\t' << i << '\n';
        ++i;
    }
    return 0;
}
