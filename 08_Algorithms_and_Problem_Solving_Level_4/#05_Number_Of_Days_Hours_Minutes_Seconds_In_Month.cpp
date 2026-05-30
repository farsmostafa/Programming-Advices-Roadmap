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
    if (month == 2)
    {
        return IsLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}
short NumberOfHoursInMonth(int month, int year)
{
    return NumberOfDaysInMonth(month, year) * 24;
}
int NumberOfMinutesInMonth(int month, int year)
{
    return NumberOfHoursInMonth(month, year) * 60;
}
int NumberOfSecondsInMonth(int month, int year)
{
    return NumberOfMinutesInMonth(month, year) * 60;
}

void PrintMonthInfo(int month, int year)
{
    cout << "\tNumber of Days in Month    [" << month << "] is " << NumberOfDaysInMonth(month, year) << endl;
    cout << "\tNumber of Hours in Month   [" << month << "] is " << NumberOfHoursInMonth(month, year) << endl;
    cout << "\tNumber of Minutes in Month [" << month << "] is " << NumberOfMinutesInMonth(month, year) << endl;
    cout << "\tNumber of Seconds in Month [" << month << "] is " << NumberOfSecondsInMonth(month, year) << endl;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to print Number of {Days, Hours, Minutes, Seconds} in a certain month.\n";
    cout << "\tex  : Please enter a year  to check? 2000\n\n";
    cout << "\tex  : Please enter a month to check? 2\n\n";
    cout << "\toutput : Number of Days in month    [2] is 29\n";
    cout << "\t         Number of Hours in month   [2] is 576\n";
    cout << "\t         Number of Minutes in month [2] is 34560\n";
    cout << "\t         Number of Seconds in month [2] is 2073600\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    PrintMonthInfo(month, year);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
