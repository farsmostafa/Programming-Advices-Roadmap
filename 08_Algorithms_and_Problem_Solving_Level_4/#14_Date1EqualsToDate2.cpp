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

short NumberOfDaysFromTheBeginingOfTheYear(int day, int month, int year)
{
    short totalDays = 0;
    for (int m = 1; m < month; m++)
    {
        totalDays += NumberOfDaysInMonth(m, year);
    }
    totalDays += day;
    return totalDays;
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

bool IsDate1EqualsDate2(sDate date1, sDate date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #14 :Write a program to read date1, date2 and check if Date 1 Equals Date 2\n";
    cout << "\tex     : Please enter a year 1  ? 2022\n";
    cout << "\t         Please enter a month 1 ? 10\n";
    cout << "\t         Please enter a day 1   ? 10\n";
    cout << "\t       : Please enter a year 2  ? 2022\n";
    cout << "\t         Please enter a month 2 ? 4\n";
    cout << "\t         Please enter a day 2   ? 10\n";
    cout << "\toutput : No, Date 1 is not equal Date 2";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    sDate date2 = ReadDate("Enter Date 2:");
    if (IsDate1EqualsDate2(date1, date2))
    {
        cout << "Yes, Date 1 is equal Date 2";
    }
    else
    {
        cout << "No, Date 1 is not equal Date 2";
    }

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
