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
    date.day = ReadPositiveNumberInRange("Enter a day   to check? : ", 1, NumberOfDaysInMonth(date.month, date.year));
    date.month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    date.year = ReadPositiveNumberInRange("Enter a year  to check? : ", 1, 9999);
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

short CalculateVacationDays(sDate vacationStart, sDate vacationEnd, bool swapFlagValue = false)
{
    if (IsDate1BeforeDate2(vacationEnd, vacationStart))
    {
        return CalculateVacationDays(vacationEnd, vacationStart, true);
    }
    int counter = 0;
    while (IsDate1BeforeDate2(vacationStart, vacationEnd))
    {

        counter += IsBusinessDay(vacationStart) ? 1 : 0; // Count the day if it's a business day
        vacationStart = IncreaseDateByOneDay(vacationStart);
    }
    return counter;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #54 : Write a program to read Vacation Period DateFrom and DateTo and make a function to calculate the actual vacation days.\n";
    cout << "            - Note: Weekends are excluded.";
    cout << "\tex     : Vacation Starts:\n";
    cout << "\t           - Please enter a Year? 2022\n";
    cout << "\t           - Please enter a Month? 9\n";
    cout << "\t           - Please enter a Day? 1\n";
    cout << "\t         Vacation Ends:\n";
    cout << "\t           - Please enter a Year? 2022\n";
    cout << "\t           - Please enter a Month? 9\n";
    cout << "\t           - Please enter a Day? 5\n";
    cout << "\toutput : Vacation From : Thursday, 1/9/2022\n";
    cout << "\t         Vacation To   : Monday, 5/9/2022\n\n";
    cout << "\t         Actual Vacation Days : 2 Day(s)\n";

    cout << "\n-------------------------------------------------\n\n";
    sDate vacationStart = ReadDate("Vacation Starts:");
    sDate vacationEnd = ReadDate("Vacation Ends:");
    cout << "\nVacation From : " << DayShortName(DayOfWeekOrder(vacationStart)) << ", " << vacationStart.day << "/" << vacationStart.month << "/" << vacationStart.year << "\n";
    cout << "Vacation To   : " << DayShortName(DayOfWeekOrder(vacationEnd)) << ", " << vacationEnd.day << "/" << vacationEnd.month << "/" << vacationEnd.year << "\n\n";
    short actualVacationDays = CalculateVacationDays(vacationStart, vacationEnd);
    cout << "Actual Vacation Days : " << actualVacationDays << " Day(s)\n";

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
