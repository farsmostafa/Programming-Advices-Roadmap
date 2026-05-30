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

short DayOfWeekOrder(int day, int month, int year)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

string DayShortName(short dayOrder)
{
    string dayNames[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return dayNames[dayOrder];
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #07 :Write a program to read a date, and print the day name of week.\n";
    cout << "\tex  : Please enter a year  to check? 2022\n\n";
    cout << "\tex  : Please enter a month to check? 9\n\n";
    cout << "\tex  : Please enter a day   to check? 20\n\n";
    cout << "\toutput : Date      : 20/9/2022\n";
    cout << "\t         Day order : 2\n";
    cout << "\t         Day Name  : Tuesday";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    int day = ReadPositiveNumberInRange("Enter a day to check? : ", 1, NumberOfDaysInMonth(month, year));
    short dayOrder = DayOfWeekOrder(day, month, year);
    cout << "Date      : " << day << "/" << month << "/" << year << endl;
    cout << "Day order : " << dayOrder << endl;
    cout << "Day Name  : " << DayShortName(dayOrder) << endl;
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
