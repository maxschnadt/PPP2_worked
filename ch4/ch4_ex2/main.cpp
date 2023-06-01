#include "../../std_lib_facilities.h"

int main()
{
    vector<double> measurements{};

    for (double temp; cin>>temp;)
    {
        measurements.push_back(temp);
    }

    sort(measurements);

    double median {};

    if (measurements.size() % 2 == 0)
    {
        median = measurements[measurements.size()/2 - 1] + measurements[measurements.size()/2];
        median /= 2;
    }
    else if (measurements.size() % 2 == 1)
    {
        median = measurements[measurements.size()/2];
    }

    cout << "The median is " << median << "\n";

    return 0;
}
