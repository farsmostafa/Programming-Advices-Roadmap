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

struct stPeriod
{
    sDate StartDate;
    sDate EndDate;
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

bool IsLastDayInMonth(sDate Date)
{
    return Date.day == NumberOfDaysInMonth(Date.month, Date.year);
}
bool IsLastMonthInYear(sDate Date)
{
    return Date.month == 12;
}

sDate IncreaseDateByOneDay(sDate date)
{
    if (IsLastDayInMonth(date))
    {
        if (IsLastMonthInYear(date))
        {
            date.year++;
            date.month = 1;
            date.day = 1;
        }
        else
        {
            date.month++;
            date.day = 1;
        }
    }
    else
    {
        date.day++;
    }
    return date;
}

int GetDifferenceInDays(sDate date1, sDate date2, bool IncludeEndDay = false, bool swapFlagValue = false)
{
    if (IsDate1BeforeDate2(date2, date1))
    {
        return GetDifferenceInDays(date2, date1, IncludeEndDay, true);
    }
    int counter = 0;
    while (IsDate1BeforeDate2(date1, date2))
    {
        date1 = IncreaseDateByOneDay(date1);
        counter++;
    }
    counter += IncludeEndDay ? 1 : 0;
    return swapFlagValue ? -counter : counter;
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #59 :Write a program to read a Period and calculate period length in days.\n\n";
    cout << "\tex     : Enter Period :\n";
    cout << "\t       : Enter Start Date :\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 1\n";
    cout << "\t\t\tEnter a day   to check? : 1\n";
    cout << "\t       : Enter End Date   :\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 1\n";
    cout << "\t\t\tEnter a day   to check? : 5\n";
    cout << "\toutput  : Period Length: 4 days\n";
    cout << "\t        : Period Length (Including End Date): 5 days\n";
    cout << "\n\n-------------------------------------------------\n\n";
    stPeriod Period;
    cout << "\nEnter Period 1:\n";
    Period.StartDate = ReadDate("Enter Start Date:");
    Period.EndDate = ReadDate("Enter End Date:");
    cout << "\nPeriod Length: " << PeriodLengthInDays(Period) << " days\n";
    cout << "Period Length (Including End Date): " << PeriodLengthInDays(Period, true) << " days\n";

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
