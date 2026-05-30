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

sDate GetDateFromDayOrderInYear(short dayOrder, short year)
{
    sDate date;
    date.year = year;
    date.month = 1;
    if (dayOrder < 1)
    {
        date.day = 0;
        cout << "Invalid day order! Day order should be greater than 0.\n";
        return date;
    }else if (dayOrder > (IsLeapYear(year) ? 366 : 365))
    {
        short yearsToAdd = 0;
        while (dayOrder > (IsLeapYear(year + yearsToAdd) ? 366 : 365))
        {
            dayOrder -= (IsLeapYear(year + yearsToAdd) ? 366 : 365);
            yearsToAdd++;
        }
        date.year += yearsToAdd;
        cout << "Day order exceeds the number of days in the year " << year << ". It corresponds to a date in the year " << date.year << ".\n";
    }
    while (dayOrder > NumberOfDaysInMonth(date.month, year))
    {
        dayOrder -= NumberOfDaysInMonth(date.month, year);
        date.month++;
    }
    date.day = dayOrder;
    return date;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #11 :Write a program to print total days from the beginning of year, then Take the total days and convert them back to date.\n";
    cout << "\tex     : Please enter a year   ? 2022\n";
    cout << "\t         Please enter a month  ? 9\n";
    cout << "\t         Please enter a day    ? 20\n";
    cout << "\toutput : Number of days from beginning of the year is 263\n\n";
    cout << "\t         Date for [263] is: 20/9/2022";
    cout << "\n\n-------------------------------------------------\n";
    short year = ReadPositiveNumberInRange("Enter a year  to check? : ", 1, 9999);
    short month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    short day = ReadPositiveNumberInRange("Enter a day   to check? : ", 1, NumberOfDaysInMonth(month, year));
    cout << "\nNumber of days from beginning of the year is " << NumberOfDaysFromTheBeginingOfTheYear(day, month, year) << "\n";
    sDate date = GetDateFromDayOrderInYear(NumberOfDaysFromTheBeginingOfTheYear(day, month, year), year);
    cout << "Date for [" << NumberOfDaysFromTheBeginingOfTheYear(day, month, year) << "] is: "
         << date.day << "/" << date.month << "/" << date.year << "\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
