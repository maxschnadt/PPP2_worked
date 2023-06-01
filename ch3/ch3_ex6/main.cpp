#include "../../std_lib_facilities.h"

int max_num(int x, int y)
{
    int maximum {};
    maximum = (x + y + abs(y-x)) / 2;
    return maximum;
}

int min_num(int x, int y)
{
    int minimum {};
    minimum = (x + y - abs(y-x)) / 2;
    return minimum;
}

int main()
{
    cout << "Please enter 3 integers: ";
    int number_1;
    int number_2;
    int number_3;
    cin >> number_1 >> number_2 >> number_3;
    int maximum_1_2 = max_num(number_1, number_2);
    int maximum_1_2_3 = max_num(maximum_1_2, number_3);
    int minimum_1_2 = min_num(number_1, number_2);
    int minimum_1_2_3 = min_num(minimum_1_2, number_3);
    int medium_1_2 = min_num(max_num(number_1, number_2), max_num(number_2, number_3));
    int medium_1_2_3 = min_num(medium_1_2, max_num(number_1, number_3));
    cout << minimum_1_2_3 << ", " << medium_1_2_3 << ", " << maximum_1_2_3;
    return 0;
}
