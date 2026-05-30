#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumberInRange(string message, int From = INT_MIN, int To = INT_MAX)
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

struct sDate
{
    short day;
    short month;
    short year;
};

sDate ReadDate(string message)
{
    sDate date;
    cout << message << "\n";
    date.year = ReadPositiveNumberInRange("Enter a year : ", 1, 9999);
    date.month = ReadPositiveNumberInRange("Enter a month: ", 1, 12);
    date.day = ReadPositiveNumberInRange("Enter a day  : ", 1, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

bool IsValidDate(sDate date)
{
    if (date.day < 1 || date.day > 31)
    {
        return false;
    }

    if (date.month < 1 || date.month > 12)
    {
        return false;
    }

    if (date.day < 1 || date.day > NumberOfDaysInMonth(date.month, date.year))
    {
        return false;
    }

    return true;
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #62 :Write a program to read Date and write a function to validate this date\n\n";
    cout << "\tex     : Enter Date:\n";
    cout << "\t\t\tEnter a year : 2022\n";
    cout << "\t\t\tEnter a month: 1\n";
    cout << "\t\t\tEnter a day  : 1\n";
    cout << "\toutput : Yes, this Date is valid.\n";
    cout << "\tex     : Enter Date:\n";
    cout << "\t\t\tEnter a year : 2022\n";
    cout << "\t\t\tEnter a month: 2\n";
    cout << "\t\t\tEnter a day  : 31\n";
    cout << "\toutput : No, this Date is not valid.\n";
    cout << "\n\n-------------------------------------------------\n\n";
    sDate date;
    date.day = ReadPositiveNumberInRange("Enter a day  : ");
    date.month = ReadPositiveNumberInRange("Enter a month: ");
    date.year = ReadPositiveNumberInRange("Enter a year : ");
    if (IsValidDate(date))
    {
        cout << "\nYes, this Date is valid.\n";
    }
    else
    {
        cout << "\nNo, this Date is not valid.\n";
    }
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
