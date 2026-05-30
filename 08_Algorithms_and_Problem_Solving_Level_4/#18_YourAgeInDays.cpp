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

bool IsDate1BeforeDate2(sDate date1, sDate date2)
{
    return (date1.year < date2.year) ||
           (date1.year == date2.year && date1.month < date2.month) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

bool IsDate1EqualDate2(sDate date1, sDate date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
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



int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #18 : Write a program calculate you age in days.\n";
    cout << "\tex     : Please enter a year 1  ? 2003\n";
    cout << "\t         Please enter a month 1 ? 4\n";
    cout << "\t         Please enter a day 1   ? 1\n";
    cout << "\toutput : Your age in days is 8035 days.\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter your birth date:");
    sDate date2 = GetSystemDate();
    int difference = GetDifferenceInDays(date1, date2, true);
    cout << "\nYour age in days is " << difference << " days.\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
