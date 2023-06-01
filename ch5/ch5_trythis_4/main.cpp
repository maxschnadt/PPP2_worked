#include "../../std_lib_facilities.h"

int area(int length, int width)
{
    if (length <= 0 || width <= 0)
    {
        throw runtime_error("You fucked up m8");
    }
    return length * width;
}

int factorial(int number)
{
    if (number == 1)
    {
        return number;
    }
    else if (number >= 2)
    {
        return number * factorial(number-1);
    }
    else
    {
        throw runtime_error("Not a number");
    }
}

int main()
{
    int area1 = area(0, 2);
    int fact5 = factorial(0);
    cout << fact5 << "\n";
    return 0;
}
