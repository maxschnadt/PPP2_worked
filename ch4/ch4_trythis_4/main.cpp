#include "../../std_lib_facilities.h"

int square(int x)
{
    int y {0};

    for (int j {0}; j < x; ++j)
    {
        y += x;
    }

    return y;
}

int main()
{
    int i = 0;

    while (i <= 100)
    {
        cout << i << "\t" << square(i) << "\n";
        ++i;
    }

    return 0;
}
