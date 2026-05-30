#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumber(string message)
{

    int number;
    cout << message;
    cin >> number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Please enter a valid number: ";
        cin >> number;
    }
    return number;
}
bool IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInYear(int year)
{
    return IsLeapYear(year) ? 366 : 365;
}
short NumberOfHoursInYear(int year)
{
    return NumberOfDaysInYear(year) * 24;
}
int NumberOfMinutesInYear(int year)
{
    return NumberOfHoursInYear(year) * 60;
}
int NumberOfSecondsInYear(int year)
{
    return NumberOfMinutesInYear(year) * 60;
}

void PrintYearInfo(int year)
{
    cout << "\tNumber of Days in Year    [" << year << "] is " << NumberOfDaysInYear(year) << endl;
    cout << "\tNumber of Hours in Year   [" << year << "] is " << NumberOfHoursInYear(year) << endl;
    cout << "\tNumber of Minutes in Year [" << year << "] is " << NumberOfMinutesInYear(year) << endl;
    cout << "\tNumber of Seconds in Year [" << year << "] is " << NumberOfSecondsInYear(year) << endl;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #04 : Write a program to print Number of {Days, Hours, Minutes, Seconds} in a certain year.\n";
    cout << "\tex  : Please enter a year to check? 2000\n\n";
    cout << "\toutput : Number of Days in Year    [2000] is 366\n";
    cout << "\t         Number of Hours in Year   [2000] is 8784\n";
    cout << "\t         Number of Minutes in Year [2000] is 527040\n";
    cout << "\t         Number of Seconds in Year [2000] is 31622400\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumber("Enter a year: ");
    PrintYearInfo(year);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
