#include "../../std_lib_facilities.h"

int main()
{
    try
    {
        vector<char> correct_letters (4);  // List of correct letters, which will be guessed

        for (char& letter: correct_letters)
        {
            letter = 'A' + rand()%26;
        }


        int bulls {0};
        while (bulls < 4)
        {
            bulls = 0;  // Counter for correct letters at the correct position
            int cows {0};   // Counter for correct letters at the wrong position
            cout << "Please enter 4 letters separated by a space:\n";

            vector<char> user_letters (4);  // List of user entered letters

            for (char & letter: user_letters)   // Loop for reading in user letters into the list
            {
                cin >> letter;
                if (!cin) error ("Input operation not successful"); // Throw error if input fails
            }

            for (int i {0}; i < user_letters.size(); ++i)   // Step through the user entered letters
            {
                bool increased_bulls {false};
                for (int j {0}; j < correct_letters.size(); ++j) // First time stepping through the correct letters
                {
                    if (i == j && correct_letters[j] == user_letters[i])
                    {
                        ++bulls;    // Increase bulls if positions and letters match
                        increased_bulls = true; // Variable that tracks wether bulls have been increased
                        break;
                    }
                }
                if (!increased_bulls)   // Only executed if bulls have not been increased
                                        // Should prevent a variable from being counted twice, say C in FPCK vs. ACDC
                {
                    for (int k {0}; k < correct_letters.size(); ++k)    // Step through the correct letters
                    {
                        if (i != k && correct_letters[k] == user_letters[i])    // Increase cows if letters match but their position doesn't
                        {
                            ++cows;
                            break;
                        }
                    }
                }
            }
            cout << "Bulls: " << bulls << "\nCows: " << cows << "\n";
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
        cerr << "Unknown error" << endl;
        keep_window_open();
        return 2;
    }

}
