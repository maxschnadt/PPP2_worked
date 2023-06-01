#include "../../std_lib_facilities.h"

class Name_value
{
    public:
        string name;
        double score;
};

int main()
{
    try
    {
        vector<Name_value> pairs{};

        while (true) {
            Name_value new_entry{};
            double value{};
            string label{};
            cin >> value >> label;
            if (value == 0 && label == "NoName")
            {
                break;
            }
            for (const Name_value& example: pairs)
            {
                if (label == example.name)
                {
                    error("Name already exists");
                }
            }
            new_entry.name = label;
            new_entry.score = value;
            pairs.push_back(new_entry);
        }

        for (const Name_value& example: pairs)
        {
            cout << "Name: " << example.name
                 << "\tScore: " << example.score << endl;
        }

        return 0;
    }
    catch (exception& e)
    {
        cerr << "error: " << e.what() << endl;
        keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown error.";
        keep_window_open();
        return 2;
    }
}
