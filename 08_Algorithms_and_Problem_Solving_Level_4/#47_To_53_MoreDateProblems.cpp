#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct sDate
{
    short day;
    short month;
    short year;
};

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

sDate ReadDate(string message)
{
    sDate date;
    cout << message << "\n";
    date.year = ReadPositiveNumberInRange("Enter a year  to check? : ", 1, 9999);
    date.month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    date.day = ReadPositiveNumberInRange("Enter a day   to check? : ", 1, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

sDate GetSystemDate()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    sDate date;
    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;
    return date;
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

short DayOfWeekOrder(int day, int month, int year)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.day, Date.month, Date.year);
}

string DayShortName(short dayOrder)
{
    string dayNames[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return dayNames[dayOrder];
}

bool IsEndOfWeek(sDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(sDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(sDate Date)
{
    return !IsWeekEnd(Date);
}

short DaysUntilTheEndOfWeek(sDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(sDate Date)
{
    return NumberOfDaysInMonth(Date.month, Date.year) - Date.day + 1; // +1 to include the current day
}

short DaysUntilTheEndOfYear(sDate Date)
{
    short totalDaysInYear = IsLeapYear(Date.year) ? 366 : 365;
    short daysPassed = NumberOfDaysFromTheBeginingOfTheYear(Date.day, Date.month, Date.year);
    return totalDaysInYear - daysPassed + 1; // +1 to include the current day
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #47 To #53 : Write a program to read a date and make functions as follows:\n";
    cout << "   - Overload the DayOfWeekOrder to take date structure\n";
    cout << "   - IsEndOfWeek\n";
    cout << "   - IsWeekEnd\n";
    cout << "   - IsBusinessDay\n";
    cout << "   - DaysUntilTheEndOfWeek\n";
    cout << "   - DaysUntilTheEndOfMonth\n";
    cout << "   - DaysUntilTheEndOfYear\n";
    cout << "\tex     : Today is Friday, 23/9/2022\n";
    cout << "\toutput : Is it End of Week ?\n";
    cout << "\t         => No Not end of week\n";
    cout << "\t         Is it Week End ?\n";
    cout << "\t         => Yes it is a Week end\n";
    cout << "\t         Is it Business Day ?\n";
    cout << "\t         => No it is Not a Business day\n";
    cout << "\t         - Days until the end of week  : 1 Day(s)\n";
    cout << "\t         - Days until the end of month : 8 Day(s)\n";
    cout << "\t         - Days until the end of year  : 100 Day(s)\n";

    cout << "\n-------------------------------------------------\n\n";

    sDate date1 = GetSystemDate();
    cout << "Today is " << DayShortName(DayOfWeekOrder(date1)) << ", " << date1.day << "/" << date1.month << "/" << date1.year << "\n\n";
    cout << "Is it End of Week ?\n";
    cout << "=> " << (IsEndOfWeek(date1) ? "Yes, it is End of week" : "No, it is Not end of week") << "\n";
    cout << "Is it Week End ?\n";
    cout << "=> " << (IsWeekEnd(date1) ? "Yes, it is a Week end" : "No, it is Not a Week end") << "\n";
    cout << "Is it Business Day ?\n";
    cout << "=> " << (IsBusinessDay(date1) ? "Yes, it is a Business day" : "No, it is Not a Business day") << "\n";
    cout << "- Days until the end of week  : " << DaysUntilTheEndOfWeek(date1) << " Day(s)\n";
    cout << "- Days until the end of month : " << DaysUntilTheEndOfMonth(date1) << " Day(s)\n";
    cout << "- Days until the end of year  : " << DaysUntilTheEndOfYear(date1) << " Day(s)\n";

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
