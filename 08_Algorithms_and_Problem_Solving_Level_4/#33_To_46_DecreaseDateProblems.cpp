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

sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.day == 1)
    {
        if (Date.month == 1)
        {
            Date.month = 12;
            Date.day = 31;
            Date.year--;
        }
        else
        {
            Date.month--;
            Date.day = NumberOfDaysInMonth(Date.month, Date.year);
        }
    }
    else
    {
        Date.day--;
    }
    return Date;
}

sDate DecreaseDateByXDays(sDate Date, int Days)
{
    for (int i = 0; i < Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
    for (int i = 0; i < 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByXWeeks(sDate Date, int Weeks)
{
    for (int i = 0; i < Weeks * 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
    if (Date.month == 1)
    {
        Date.month = 12;
        Date.year--;
    }
    else
    {
        Date.month--;
    }
    Date.day = min(Date.day, NumberOfDaysInMonth(Date.month, Date.year));
    return Date;
}

sDate DecreaseDateByXMonths(sDate Date, int Months)
{
    for (int i = 0; i < Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
    Date.year--;
    Date.day = min(Date.day, NumberOfDaysInMonth(Date.month, Date.year));
    return Date;
}

sDate DecreaseDateByXYears(sDate Date, int Years)
{
    for (int i = 0; i < Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearsFaster(sDate Date, int Years)
{
    Date.year -= Years;
    Date.day = min(Date.day, NumberOfDaysInMonth(Date.month, Date.year));
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.year -= 10;
    Date.day = min(Date.day, NumberOfDaysInMonth(Date.month, Date.year));
    return Date;
}

sDate DecreaseDateByXDecades(sDate Date, int Decades)
{
    for (int i = 0; i < Decades * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate Date, int Decades)
{
    Date.year -= Decades * 10;
    Date.day = min(Date.day, NumberOfDaysInMonth(Date.month, Date.year));
    return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
    Date.year -= 100;
    Date.day = min(Date.day, NumberOfDaysInMonth(Date.month, Date.year));
    return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.year -= 1000;
    Date.day = min(Date.day, NumberOfDaysInMonth(Date.month, Date.year));
    return Date;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #33 To #46 : Write a program to read a date and make a functions to decrease date as follows:\n";
    cout << "   - DecreaseDateByOneDays\n";
    cout << "   - DecreaseDateByXDays\n";
    cout << "   - DecreasebateByOneWeek\n";
    cout << "   - DecreaseDateByXWeeks\n";
    cout << "   - DecreaseDateByOneMonth\n";
    cout << "   - DecreaseDateByXMonths\n";
    cout << "   - DecreaseDateByOneYear\n";
    cout << "   - DecreaseDateByXYears\n";
    cout << "   - DecreaseDateByXYearsFaster\n";
    cout << "   - DecreaseDateByOneDecade\n";
    cout << "   - DecreaseDateByXDecades\n";
    cout << "   - DecreasebateByXDecadesFaster\n";
    cout << "   - DecreaseDateByOneCentury\n";
    cout << "   - DecreaseDateByOneMillennium\n";
    cout << "\tex     : Please enter a year  ? 2022\n";
    cout << "\t         Please enter a month ? 12\n";
    cout << "\t         Please enter a day   ? 31\n";
    cout << "\toutput : Date After :\n";
    cout << "\t         01-Subtracting One Day           : 30/12/2022\n";
    cout << "\t         02-Subtracting 10 Days           : 20/12/2022\n";
    cout << "\t         03-Subtracting One Week          : 13/12/2022\n";
    cout << "\t         04-Subtracting 10 Weeks          : 4/10/2022\n";
    cout << "\t         05-Subtracting One Month         : 4/9/2022\n";
    cout << "\t         06-Subtracting 5 Months          : 4/4/2022\n";
    cout << "\t         07-Subtracting One Year          : 4/4/2021\n";
    cout << "\t         08-Subtracting 10 Years          : 4/4/2011\n";
    cout << "\t         09-Subtracting 10 Years Faster   : 4/4/2001\n";
    cout << "\t         10-Subtracting One Decade        : 4/4/1991\n";
    cout << "\t         11-Subtracting 10 Decades        : 4/4/1891\n";
    cout << "\t         12-Subtracting 10 Decades Faster : 4/4/1791\n";
    cout << "\t         13-Subtracting One Century       : 4/4/1691\n";
    cout << "\t         14-Subtracting One Millennium    : 4/4/691\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date :");

    cout << "Date After :\n";
    sDate date2 = DecreaseDateByOneDay(date1);
    cout << "01-Subtracting One Day           : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByXDays(date2, 10);
    cout << "02-Subtracting 10 Days           : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByOneWeek(date2);
    cout << "03-Subtracting One Week          : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByXWeeks(date2, 10);
    cout << "04-Subtracting 10 Weeks          : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByOneMonth(date2);
    cout << "05-Subtracting One Month         : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByXMonths(date2, 5);
    cout << "06-Subtracting 5 Months          : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByOneYear(date2);
    cout << "07-Subtracting One Year          : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByXYears(date2, 10);
    cout << "08-Subtracting 10 Years          : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByXYearsFaster(date2, 10);
    cout << "09-Subtracting 10 Years Faster   : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByOneDecade(date2);
    cout << "10-Subtracting One Decade        : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByXDecades(date2, 10);
    cout << "11-Subtracting 10 Decades        : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByXDecadesFaster(date2, 10);
    cout << "12-Subtracting 10 Decades Faster : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByOneCentury(date2);
    cout << "13-Subtracting One Century       : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = DecreaseDateByOneMillennium(date2);
    cout << "14-Subtracting One Millennium    : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";


    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
