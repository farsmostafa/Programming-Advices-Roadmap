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
    date.year = ReadPositiveNumberInRange("Enter a year  to check? : ", 1, 9999);
    date.month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    date.day = ReadPositiveNumberInRange("Enter a day   to check? : ", 1, NumberOfDaysInMonth(date.month, date.year));
    return date;
}
bool IsLastDayInMonth(sDate Date)
{
    return Date.day == NumberOfDaysInMonth(Date.month, Date.year);
}
bool IsLastMonthInYear(sDate Date)
{
    return Date.month == 12;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #15 : Write a program to read date and check \n   - If it is last bay in Month\n   - If it is last Month In Year \n";
    cout << "\tex     : Please enter a year  ? 2022\n";
    cout << "\t         Please enter a month ? 12\n";
    cout << "\t         Please enter a day   ? 10\n";
    cout << "\toutput : No, it is not last day in month\n";
    cout << "\t         Yes, it is last month in year\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    if (IsLastDayInMonth(date1))
        cout << "Yes, it is last day in month\n";
    else
        cout << "No, it is not last day in month\n";

    if (IsLastMonthInYear(date1))
        cout << "Yes, it is last month in year\n";
    else
        cout << "No, it is not last month in year\n";

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
