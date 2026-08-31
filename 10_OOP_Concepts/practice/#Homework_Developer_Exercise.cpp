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

    void PrintInfo()
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

class clsEmployee : public clsPerson
{

private:
    string _Title;
    double _Salary;
    string _Department;

public:
    clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, double Salary, string Department)
        : clsPerson(ID, FirstName, LastName, Email, Phone)
    {
        _Title = Title;
        _Salary = Salary;
        _Department = Department;
    }

    void SetTitle(string Title)
    {
        _Title = Title;
    }
    void SetSalary(double Salary)
    {
        _Salary = Salary;
    }
    void SetDepartment(string Department)
    {
        _Department = Department;
    }

    string Title()
    {
        return _Title;
    }
    double Salary()
    {
        return _Salary;
    }
    string Department()
    {
        return _Department;
    }

    void PrintInfo()
    {
        cout << "Info:\n\n";
        cout << "---------------------------------";
        cout << "\nID         : " << ID();
        cout << "\nFirst Name : " << FirstName();
        cout << "\nLast Name  : " << LastName();
        cout << "\nFull Name  : " << FullName();
        cout << "\nTitle      : " << _Title;
        cout << "\nEmail      : " << Email();
        cout << "\nPhone      : " << Phone();
        cout << "\nSalary     : " << _Salary;
        cout << "\nDepartment : " << _Department;
        cout << "\n---------------------------------\n\n";
    }
};

class clsDeveloper : public clsEmployee
{
private:
    string _MainProgrammingLanguage;

public:
    clsDeveloper(int ID, string FirstName, string LastName, string Title, string Email, string Phone, double Salary, string Department, string MainProgrammingLanguage)
        : clsEmployee(ID, FirstName, LastName, Title, Email, Phone, Salary, Department)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }
    void SetMainProgrammingLanguage(string MainProgrammingLanguage)
    {
        _MainProgrammingLanguage = MainProgrammingLanguage;
    }
    string MainProgrammingLanguage()
    {
        return _MainProgrammingLanguage;
    }

    void PrintInfo()
    {
        cout << "Info:\n\n";
        cout << "---------------------------------";
        cout << "\nID         : " << ID();
        cout << "\nFirst Name : " << FirstName();
        cout << "\nLast Name  : " << LastName();
        cout << "\nFull Name  : " << FullName();
        cout << "\nTitle      : " << Title();
        cout << "\nEmail      : " << Email();
        cout << "\nPhone      : " << Phone();
        cout << "\nSalary     : " << Salary();
        cout << "\nDepartment : " << Department();
        cout << "\nMain Programming Language : " << _MainProgrammingLanguage;
        cout << "\n---------------------------------\n\n";
    }
};

int main()
{
    system("cls");
    clsDeveloper Dev(1, "Fars", "Mostafa", "Developer", "fares.moostafa@gmail.com", "01093649229", 20000, "IT" , "C++");
    Dev.PrintInfo();
    Dev.SendEmail("Course 10", "this course is about OOP");
    Dev.SendSMS("Dear Fars Mostafa, Thanks for studing this course.");

    system("pause>0");
    return 0;
}
