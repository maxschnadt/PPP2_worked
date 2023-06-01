#include "../../std_lib_facilities.h"

double convert_length(double length, string unit)
{
    const double in_to_cm {2.54};
    const double ft_to_in {12.0};
    const double cm_to_m {0.01};
    const double in_to_m {in_to_cm * cm_to_m};
    const double ft_to_m {ft_to_in * in_to_m};

    if (unit == "ft")
    {
        return length * ft_to_m;
    }
    else if (unit == "cm")
    {
        return length * cm_to_m;
    }
    else if (unit == "in")
    {
        return length * in_to_m;
    }
    else if (unit == "m")
    {
        return length;
    }
    else
    {
        cout << "No or non-permissible unit entered.\n";
        return 0.0;
    }
}

int main()
{
    double smallest_length {999999999.9};
    double largest_length {-999999999.9};
    double current_length {};
    double sum_length {};
    int num_length {};
    vector<double> list_lengths {};
    string unit {};


    while (cin>>current_length>>unit)
    {
        current_length = convert_length(current_length, unit);
        list_lengths.push_back(current_length);
        cout << "The length entered is: " << current_length << " m\n";
        if (current_length < smallest_length)
        {
            cout << "The smallest length so far.\n";
            smallest_length = current_length;
        }

        if (current_length > largest_length)
        {
            cout << "The largest length so far.\n";
            largest_length = current_length;
        }
        sum_length += current_length;
        ++num_length;
    }

    sort(list_lengths);
    for (double length : list_lengths)
    {
        cout << length << " m\n";
    }

    cout << "The sum of lengths entered is: " << sum_length << " m\n"
         << "The smallest length entered is: " << smallest_length << " m\n"
         << "The largest length entered is: " << largest_length << " m\n"
         << "The number of lengths entered is: " << num_length << ".\n";

    return 0;
}
