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

string MonthShortName(short MonthNumber)
{
    string Months[12] = {"Jan", "Feb", "Mar",
                         "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep",
                         "Oct", "Nov", "Dec"};
    return (Months[MonthNumber - 1]);
}

void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;
    int current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = NumberOfDaysInMonth(Month, Year);
    printf("\n _______________________%s________________________\n\n", MonthShortName(Month).c_str());
    printf(   "  sun    mon    tue    wed    thu    fri    sat\n");
    int i;
    for (i = 0; i < current; i++)
        printf("       ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%4d   ", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n __________________________________________________\n");
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #08 :Write a program to print Month Calender.\n";
    cout << "\tex  : Please enter a year  to check? 2022\n\n";
    cout << "\tex  : Please enter a month to check? 9\n\n";
    cout << "\t------------------separator------------------\n\n";
    cout << "\tsun    mon    tue    wed    thu    fri    sat\n";
    cout << "\t                             1      2      3 \n";
    cout << "\t 4      5      6      7      8      9     10 \n";
    cout << "\t11     12     13     14     15     16     17 \n";
    cout << "\t18     19     20     21     22     23     24 \n";
    cout << "\t25     26     27     28     29     30\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    PrintMonthCalendar(month, year);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
