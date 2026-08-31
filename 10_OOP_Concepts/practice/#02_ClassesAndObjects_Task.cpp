#include <iostream>

using namespace std;

class clsPerson
{
    int x;

public:
    string FirstName;
    string LastName;

    string Full_Name()
    {
        return FirstName + " " + LastName;
    }
};

int main()
{
    clsPerson person1;
    person1.FirstName = "Fars";
    person1.LastName = "Alaa";
    system("cls");
    cout << person1.Full_Name();
    system("pause>0");
    return 0;
}
