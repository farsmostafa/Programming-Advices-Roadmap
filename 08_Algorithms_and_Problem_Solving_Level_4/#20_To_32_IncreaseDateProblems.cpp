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

sDate IncreaseDateByXDays(sDate date, int days)
{
    for (int i = 0; i < days; i++)
    {
        date = IncreaseDateByOneDay(date);
    }
    return date;
}

sDate IncreaseDateByOneWeek(sDate date)
{
    for (int i = 0; i < 7; i++)
    {
        date = IncreaseDateByOneDay(date);
    }
    return date;
}

sDate IncreaseDateByXWeeks(sDate date, int weeks)
{
    for (int i = 0; i < weeks; i++)
    {
        date = IncreaseDateByOneWeek(date);
    }
    return date;
}

sDate IncreaseDateByOneMonth(sDate date)
{
    if (IsLastMonthInYear(date))
    {
        date.year++;
        date.month = 1;
    }
    else
    {
        date.month++;
    }
    date.day = min(date.day, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

sDate IncreaseDateByXMonths(sDate date, int months)
{
    for (int i = 0; i < months; i++)
    {
        date = IncreaseDateByOneMonth(date);
    }
    return date;
}

sDate IncreaseDateByOneYear(sDate date)
{
    date.year++;
    date.day = min(date.day, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

sDate IncreaseDateByXYears(sDate date, int years)
{
    for (int i = 0; i < years; i++)
    {
        date = IncreaseDateByOneYear(date);
    }
    return date;
}

sDate IncreaseDateByXYearsFaster(sDate date, int years)
{
    date.year += years;
    date.day = min(date.day, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

sDate IncreaseDateByOneDecade(sDate date)
{
    return IncreaseDateByXYearsFaster(date, 10);
}

sDate IncreaseDateByXDecades(sDate date, int decades)
{
    for (int i = 0; i < decades; i++)
    {
        date = IncreaseDateByOneDecade(date);
    }
    return date;
}

sDate IncreaseDateByXDecadesFaster(sDate date, int decades)
{
    date.year += decades * 10;
    date.day = min(date.day, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

sDate IncreaseDateByOneCentury(sDate date)
{
    date.year += 100;
    date.day = min(date.day, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

sDate IncreaseDateByOneMillennium(sDate date)
{
    date.year += 1000;
    date.day = min(date.day, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #20 To #32 : Write a program to read a date and make a functions to increase date as follows:\n";
    cout << "   - IncreaseDateByXDays\n";
    cout << "   - IncreasebateByOneWeek\n";
    cout << "   - IncreaseDateByXWeeks\n";
    cout << "   - IncreaseDateByOneMonth\n";
    cout << "   - IncreaseDateByXMonths\n";
    cout << "   - IncreaseDateByOneYear\n";
    cout << "   - IncreaseDateByXYears\n";
    cout << "   - IncreaseDateByXYearsFaster\n";
    cout << "   - IncreaseDateByOneDecade\n";
    cout << "   - IncreaseDateByXDecades\n";
    cout << "   - IncreasebateByXDecadesFaster\n";
    cout << "   - IncreaseDateByOneCentury\n";
    cout << "   - IncreaseDateByOneMillennium\n";
    cout << "\tex     : Please enter a year  ? 2022\n";
    cout << "\t         Please enter a month ? 12\n";
    cout << "\t         Please enter a day   ? 31\n";
    cout << "\toutput : Date After :\n";
    cout << "\t         01-Adding One Day : 01/1/2023\n";
    cout << "\t         02-Adding 10 Days : 11/1/2023\n";
    cout << "\t         03-Adding One Week : 18/1/2023\n";
    cout << "\t         04-Adding 10 Weeks: 29/3/2023\n";
    cout << "\t         05-Adding One Month: 29/4/2023\n";
    cout << "\t         06-Adding 5 Months: 29/9/2023\n";
    cout << "\t         07-Adding One Year : 29/9/2024\n";
    cout << "\t         08-Adding 10 Years: 29/9/2034\n";
    cout << "\t         09-Adding 10 Years Faster: 29/9/2044\n";
    cout << "\t         10-Adding One Decade: 29/9/2054\n";
    cout << "\t         11-Adding 10 Decades: 29/9/2154\n";
    cout << "\t         12-Adding 10 Decades Faster: 29/9/2254\n";
    cout << "\t         13-Adding One Century: 29/9/2354\n";
    cout << "\t         14-Adding One Millennium: 29/9/3354\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date :");

    cout << "Date After :\n";
    sDate date2 = IncreaseDateByOneDay(date1);
    cout << "    01-Adding One Day : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByXDays(date2, 10);
    cout << "    02-Adding 10 Days : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByOneWeek(date2);
    cout << "    03-Adding One Week : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByXWeeks(date2, 10);
    cout << "    04-Adding 10 Weeks: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByOneMonth(date2);
    cout << "    05-Adding One Month: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByXMonths(date2, 5);
    cout << "    06-Adding 5 Months: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByOneYear(date2);
    cout << "    07-Adding One Year : " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByXYears(date2, 10);
    cout << "    08-Adding 10 Years: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByXYearsFaster(date2, 10);
    cout << "    09-Adding 10 Years Faster: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByOneDecade(date2);
    cout << "    10-Adding One Decade: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByXDecades(date2, 10);
    cout << "    11-Adding 10 Decades: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByXDecadesFaster(date2, 10);
    cout << "    12-Adding 10 Decades Faster: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByOneCentury(date2);
    cout << "    13-Adding One Century: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";
    date2 = IncreaseDateByOneMillennium(date2);
    cout << "    14-Adding One Millennium: " << date2.day << "/" << date2.month << "/" << date2.year << "\n";

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
