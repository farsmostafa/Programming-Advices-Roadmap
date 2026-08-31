#include <iostream>

using namespace std;

class clsPerson
{
private:
    int _ID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    void SetEmail(string Email)
    {
        _Email = Email;
    }
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }

    int ID()
    {
        return _ID;
    }
    string FirstName()
    {
        return _FirstName;
    }
    string LastName()
    {
        return _LastName;
    }
    string Email()
    {
        return _Email;
    }
    string Phone()
    {
        return _Phone;
    }
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    // __declspec(property(get = FirstName, put = SetFirstName)) string FirstName;
    // __declspec(property(get = LastName, put = SetLastName)) string LastName;
    // __declspec(property(get = Email, put = SetEmail)) string Email;
    // __declspec(property(get = Phone, put = SetPhone)) string Phone;

    void PrintPersonInfo()
{
    cout << "Info:\n\n";
    cout << "---------------------------------";
    cout << "\nID         : " << _ID;
    cout << "\nFirst Name : " << _FirstName;
    cout << "\nLast Name  : " << _LastName;
    cout << "\nFull Name  : " << _FirstName << " " << _LastName;
    cout << "\nEmail      : " << _Email;
    cout << "\nPhone      : " << _Phone;
    cout << "\n---------------------------------\n\n";
}

void SendEmail(string subject, string body)
{
    cout << "----------------\n";
    cout << "The following message sent successfully to email: " << _Email << endl;
    cout << "Subject: " << subject << endl;
    cout << "Body: " << body << endl;
    cout << "----------------\n\n";
}

void SendSMS(string message)
{
    cout << "----------------\n";
    cout << "The following message sent successfully to phone: " << _Phone << endl;
    cout << "Message: " << message << endl;
    cout << "----------------\n\n";
}
};

int main()
{
    system("cls");
    clsPerson Person(1, "Fars", "Mostafa", "fares.moostafa@gmail.com", "01093649229");
    Person.PrintPersonInfo();
    Person.SendEmail("Course 10", "this course is about OOP");
    Person.SendSMS("Dear Fars Mostafa, Thanks for studing this course.");

    system("pause>0");
    return 0;
}
