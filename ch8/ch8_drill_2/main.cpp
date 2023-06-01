#include <iostream>

void swap_v(int a, int b)
{
    int temp;
    temp = a, a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a, a = b;
    b = temp;
}

void print(const int& x, const int& y)
{
    std::cout << "x: " << x << "\ny: " << y << std::endl;
}

int main()
{
    int x = 7;
    int y = 9;
    swap_r(x, y);
    print(x, y);
    swap_r(7, 9);
    print(7, 9);
    const int cx = 7;
    const int cy = 9;
    swap_r(cx, cy);
    print(cx, cy);
    swap_r(7.7, 9.9);
    print(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_r(dx, dy);
    print(dx, dy);
    swap_r(7.7, 9.9);
    return 0;
}
