#include "../../std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to: ";
    string first_name {};
    cin >> first_name;
    cout << "Enter a friends name: ";
    string friend_name {};
    cin >> friend_name;
    cout << "Enter the gender of " << friend_name << " (m for male, f for female): ";
    char friend_sex {};
    cin >> friend_sex;
    cout << "Enter the age of " << friend_name << " in years: ";
    int friend_age {};
    cin >> friend_age;
    if(friend_age<=0 || friend_age >= 110)
    {
        simple_error("you're kidding!");
    }
    cout << "\nDear " << first_name << ",\n\n"
         << "how's it going? I heard you got a new job, are you happy there?\n"
         << "I heard you just had birthday and you are " << friend_age << " years old.\n"
         << "Sophie and the kids are happy and healthy as ever. I now teach\n"
         << "evening classes at the local college, which is an interesting ex-\n"
         << "perience to say the least. Have you seen " << friend_name << " lately? Maybe we\n"
         << "can catch up over some coffee in the not so distant future?\n";
    if(friend_sex=='f')
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    if(friend_sex=='m')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    if(friend_age > 70)
        cout << "I hope you are enjoying retirement.\n";
    if(friend_age < 12)
        cout << "Next year you will be " << friend_age+1 << ".\n";
    if(friend_age == 17)
        cout << "Next year you will be able to vote.\n";
    cout << "I wish you only the best and hope to hear back from you soon.\n\n"
         << "Best regards\nMax";
    return 0;
}
