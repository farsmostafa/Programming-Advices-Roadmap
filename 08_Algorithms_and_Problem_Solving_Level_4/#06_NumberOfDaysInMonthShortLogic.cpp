#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumberInRange(string message, int From, int To)
{

    int number;
    cout << message;
    cin >> number;

    while (cin.fail() || number < From || number > To)
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

short NumberOfDaysInMonth(int month, int year)
{
    if (month < 1 || month > 12)
    {
        return 0;
    }
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : days[month - 1];
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #06 :Write a program to print Number of Days in a certain Month.\n";
    cout << "\tex  : Please enter a year to  check? 2000\n\n";
    cout << "\tex  : Please enter a month to check? 2\n\n";
    cout << "\toutput : Number of Days in month    [2] is 29\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    cout << "\nNumber of Days in month [" << month << "] is " << NumberOfDaysInMonth(month, year) << "\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
