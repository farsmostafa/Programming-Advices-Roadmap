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
    date.year = ReadPositiveNumberInRange("Enter a year : ", 1, 9999);
    date.month = ReadPositiveNumberInRange("Enter a month: ", 1, 12);
    date.day = ReadPositiveNumberInRange("Enter a day  : ", 1, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{
    return (date1.year < date2.year) ||
           (date1.year == date2.year && date1.month < date2.month) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

bool IsDate1EqualsDate2(sDate date1, sDate date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

bool IsDate1AfterDate2(sDate date1, sDate date2)
{
    return (!IsDate1BeforeDate2(date1, date2) && !IsDate1EqualsDate2(date1, date2));
}

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};
enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualsDate2(Date1, Date2))
        return enDateCompare::Equal;
    return enDateCompare::After;
}

struct stPeriod
{
    sDate StartDate;
    sDate EndDate;
};

stPeriod ReadPeriod()
{
    stPeriod period;
    cout << "Enter Start Date:\n";
    period.StartDate = ReadDate("");
    cout << "Enter End Date:\n";
    period.EndDate = ReadDate("");
    return period;
}

bool isDateInPeriod(sDate date, stPeriod period)
{
    return !(IsDate1BeforeDate2(date, period.StartDate) || IsDate1AfterDate2(date, period.EndDate));
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #60 :Write a program to read a Period and Date, then check if date is within this period or not?\n";
    cout << "\tex     : Enter Period:\n";
    cout << "\t\t: Enter Start Date:\n";
    cout << "\t\t\tEnter a year : 2022\n";
    cout << "\t\t\tEnter a month: 1\n";
    cout << "\t\t\tEnter a day  : 1\n";
    cout << "\t\t: Enter End Date:\n";
    cout << "\t\t\tEnter a year : 2022\n";
    cout << "\t\t\tEnter a month: 1\n";
    cout << "\t\t\tEnter a day  : 10\n";
    cout << "\t\t: Enter Date to check:\n";
    cout << "\t\t\tEnter a year : 2022\n";
    cout << "\t\t\tEnter a month: 1\n";
    cout << "\t\t\tEnter a day  : 5\n";
    cout << "\toutput  : Yes, the date is within the period.\n";
    cout << "\n\n-------------------------------------------------\n";
    stPeriod period = ReadPeriod();
    sDate date = ReadDate("Enter Date to check:");
    if (isDateInPeriod(date, period))
    {
        cout << "\nYes, the date is within the period.\n";
    }
    else
    {
        cout << "\nNo, the date is not within the period.\n";
    }
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
