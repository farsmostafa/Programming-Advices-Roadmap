#include <iostream>

using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;

public:
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    string GetFirstName()
    {
        return _FirstName;
    }

    string GetLastName()
    {
        return _LastName;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    string Full_Name()
    {
        return _FirstName + " " + _LastName;
    }
};

int main()
{
    clsPerson person1;
    person1.FirstName = "Fars";
    person1.LastName = "Alaa";
    system("cls");
    cout << "First Name: " << person1.FirstName << endl;
    cout << "Last Name: " << person1.LastName << endl;
    cout << "Full Name: " << person1.Full_Name();
    system("pause>0");
    return 0;
}
