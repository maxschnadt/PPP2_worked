#include "../../std_lib_facilities.h"

void compute_root(double a, double b, double c)
{
    double p {b*1.0 / a};
    double q {c*1.0 / a};

    if ((p*p)/4.0 - q < 0.0)
    {
        throw runtime_error("Function has no real roots.");
    }
    else if ((p*p)/4.0 - q == 0)
    {
        double root = -p/2;
        cout << "Root: " << root << "\n";
        cout << "Check root: a * x^2 + b * x + c = " << a * (root * root) + b * root + c << "\n";
    }
    else if ((p*p)/4.0 - q > 0)
    {
        double root1 = -p/2 + sqrt((p*p)/4.0 - q);
        double root2 = -p/2 - sqrt((p*p)/4.0 - q);
        cout << "Root 1: " << root1 << "\n";
        cout << "Root 2: " << root2 << "\n";
        cout << "Check root 1: a * x_1^2 + b * x_1 + c = " << a * (root1 * root1) + b * root1 + c << "\n";
        cout << "Check root 2: a * x_2^2 + b * x_2 + c = " << a * (root2 * root2) + b * root2 + c << "\n";
    }
    else
    {
        throw runtime_error("Can't compute roots. Maybe values too big?");
    }
}

int main()
{
    double a, b, c {};

    cout << "Enter the quadratic coefficient: ";
    cin >> a;

    cout << "Enter the linear coefficient: ";
    cin >> b;

    cout << "Enter the constant coefficient: ";
    cin >> c;

    try
    {
        compute_root(a, b, c);
    }
    catch (exception& e)
    {
        cerr << "Error: " << e.what() << "\n";
        keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown error.\n";
        keep_window_open();
        return 2;
    }

    return 0;
}
