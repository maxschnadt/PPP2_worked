#include "../../std_lib_facilities.h"

int area(int length, int width)
{
    if (length <= 0 || width <= 0)
    {
        return -1;
    }
    return length * width;
}

int framed_area(int length, int width)
{
    const int frame_thickness {2};
    if (length <= frame_thickness || width <= frame_thickness)
    {
        return -1;
    }
    return area(length-frame_thickness, width-frame_thickness);
}

int f(int x, int y, int z)
{
    int area1 = area(x, y);
    if (area1 <= 0)
    {
        error("non-positive area");
    }
    cout << "area1: " << area1 << "\n";

    int area2 = framed_area(x, z);
    if (area2 <= 0)
    {
        error("non-positive framed area");
    }
    cout << "area2: " << area2 << "\n";

    int area3 = framed_area(y, z);
    if (area3 <= 0)
    {
        error("non-positive framed area");
    }
    cout << "area3: " << area3 << "\n";

    double ratio = double(area1)/area3;
    if (ratio <= 0 || isinf(ratio))
    {
        error("non-valid ratio");
    }
    cout << "ratio: " << ratio << "\n";

    return 0;
}

int main()
{
    f(715827882, 3, 3);
    return 0;
}
