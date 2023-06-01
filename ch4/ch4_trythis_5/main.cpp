#include "../../std_lib_facilities.h"

int main()
{
    vector<string> word_list{};

    for (string temp {}; cin>>temp;)
    {
        word_list.push_back(temp);
    }

    vector<string> dislike {"Broccoli", "Tomato", "Salad", "Meat"};

    bool is_contained {false};

    for (string word : word_list)
    {
        for (string unliked : dislike)
        {
            if (word == unliked)
            {
                is_contained = true;
            }
        }

        if (is_contained)
        {
            cout << "BLEEP!\n";
        }
        else
        {
            cout << word << "\n";
        }

        is_contained = false;
    }

    return 0;
}
