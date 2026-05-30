<div dir="rtl">

# كورس 08: الخوارزميات وحل المشاكل - المستوى الرابع
# Algorithms & Problem Solving Level 4

| Problem Range | Status | Commit Hash |
|---|---|---|
| #01 - #10 | Completed | pending |

## 🧩 Problem #01: Number To Text
### 📝 وصف المشكلة (Problem Description)
قراءة رقم موجب وطباعة التمثيل النصي له باللغة الإنجليزية.
### 💡 الفكرة البرمجية (Logic Breakdown)
تقسيم الرقم إلى نطاقات (أحاد/عشرات/مئات/آلاف...) باستخدام Recursion.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
using namespace std;

long long ReadPositiveNumber(string message)
{
    long long number;
    cout << message;
    cin >> number;

    while (cin.fail() || number < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Please enter a positive number: ";
        cin >> number;
    }
    return number;
}

string NumberToText(long long Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 999)
        return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
    if (Number >= 1000 && Number <= 999999)
        return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
    if (Number >= 1000000 && Number <= 999999999)
        return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
    if (Number >= 1000000000 && Number <= 999999999999)
        return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
    return "";
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #01 : Write a program to read a number and print the text of that number.\n ";
    cout << "\tex     : Enter a Number? 5843\n";
    cout << "\toutput : Five Thousands Eight Hundreds Forty Three \n\n ";
    cout << "\n\n-------------------------------------------------\n\n";
    long long number = ReadPositiveNumber("Enter a Number? ");
    cout << "Output : " << NumberToText(number) << endl;
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
الحل مضبوط جدًا، والملاحظة الوحيدة أن `0` يرجع نصًا فارغًا.

## 🧩 Problem #02 & #03: Leap Year
### 📝 وصف المشكلة (Problem Description)
التحقق إن كانت السنة كبيسة أم لا.
### 💡 الفكرة البرمجية (Logic Breakdown)
تطبيق قاعدة السنة الكبيسة القياسية مباشرة.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumber(string message)
{
    int number;
    cout << message;
    cin >> number;
    while (cin.fail())
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
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #02 & 03 : Write a program to check if year is a leap year or not.\n";
    cout << "\tex     : Enter a year: 2023\n\n";
    cout << "\toutput : 2023 is not a leap year.\n";
    cout << "\tex2    : Enter a year: 2024\n\n";
    cout << "\toutput : 2023 is a leap year.\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumber("Enter a year: ");
    if (IsLeapYear(year))
        cout << year << " is a leap year.\n";
    else
        cout << year << " is not a leap year.\n";
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
المنطق صحيح، مع ملاحظة typo في مثال الإخراج داخل النص.

## 🧩 Problem #04: Year Time Units
### 📝 وصف المشكلة (Problem Description)
حساب عدد الأيام والساعات والدقائق والثواني في سنة محددة.
### 💡 الفكرة البرمجية (Logic Breakdown)
الاشتقاق التسلسلي من الأيام لباقي الوحدات.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumber(string message)
{
    int number; cout << message; cin >> number;
    while (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid Input! Please enter a valid number: "; cin >> number; }
    return number;
}
bool IsLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }
short NumberOfDaysInYear(int year) { return IsLeapYear(year) ? 366 : 365; }
short NumberOfHoursInYear(int year) { return NumberOfDaysInYear(year) * 24; }
int NumberOfMinutesInYear(int year) { return NumberOfHoursInYear(year) * 60; }
int NumberOfSecondsInYear(int year) { return NumberOfMinutesInYear(year) * 60; }
void PrintYearInfo(int year)
{
    cout << "\tNumber of Days in Year    [" << year << "] is " << NumberOfDaysInYear(year) << endl;
    cout << "\tNumber of Hours in Year   [" << year << "] is " << NumberOfHoursInYear(year) << endl;
    cout << "\tNumber of Minutes in Year [" << year << "] is " << NumberOfMinutesInYear(year) << endl;
    cout << "\tNumber of Seconds in Year [" << year << "] is " << NumberOfSecondsInYear(year) << endl;
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #04 : Write a program to print Number of {Days, Hours, Minutes, Seconds} in a certain year.\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumber("Enter a year: ");
    PrintYearInfo(year);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
تقسيم ممتاز لدوال صغيرة واضحة.

## 🧩 Problem #05: Month Time Units
### 📝 وصف المشكلة (Problem Description)
حساب وحدات الزمن لشهر معيّن داخل سنة.
### 💡 الفكرة البرمجية (Logic Breakdown)
حساب أيام الشهر أولًا ثم تحويلها لوحدات أكبر.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumberInRange(string message, int From, int To)
{
    int number; cout << message; cin >> number;
    while (cin.fail() || number < From || number > To) { cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid Input! Please enter a valid number: "; cin >> number; }
    return number;
}
bool IsLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }
short NumberOfDaysInMonth(int month, int year)
{
    if (month < 1 || month > 12) return 0;
    if (month == 2) return IsLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}
short NumberOfHoursInMonth(int month, int year) { return NumberOfDaysInMonth(month, year) * 24; }
int NumberOfMinutesInMonth(int month, int year) { return NumberOfHoursInMonth(month, year) * 60; }
int NumberOfSecondsInMonth(int month, int year) { return NumberOfMinutesInMonth(month, year) * 60; }
void PrintMonthInfo(int month, int year)
{
    cout << "\tNumber of Days in Month    [" << month << "] is " << NumberOfDaysInMonth(month, year) << endl;
    cout << "\tNumber of Hours in Month   [" << month << "] is " << NumberOfHoursInMonth(month, year) << endl;
    cout << "\tNumber of Minutes in Month [" << month << "] is " << NumberOfMinutesInMonth(month, year) << endl;
    cout << "\tNumber of Seconds in Month [" << month << "] is " << NumberOfSecondsInMonth(month, year) << endl;
}
int main()
{
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    PrintMonthInfo(month, year);
    return 0;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
التحقق من المدخلات مضبوط جدًا.

## 🧩 Problem #06: Number Of Days In Month (Short Logic)
### 📝 وصف المشكلة (Problem Description)
طباعة عدد أيام شهر محدد.
### 💡 الفكرة البرمجية (Logic Breakdown)
استخدام مصفوفة ثابتة للأيام + معالجة فبراير.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
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
    if (month < 1 || month > 12) return 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : days[month - 1];
}
int main()
{
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    cout << "\nNumber of Days in month [" << month << "] is " << NumberOfDaysInMonth(month, year) << "\n";
    return 0;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
نسخة أبسط وأسهل في الصيانة.

## 🧩 Problem #07: Day Name
### 📝 وصف المشكلة (Problem Description)
إدخال تاريخ ثم طباعة ترتيب اليوم واسمه.
### 💡 الفكرة البرمجية (Logic Breakdown)
معادلة رياضية لترتيب اليوم ثم Mapping للاسم.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumberInRange(string message, int From, int To)
{
    int number; cout << message; cin >> number;
    while (cin.fail() || number < From || number > To) { cin.clear(); cin.ignore(10000, '\n'); cout << "Invalid Input! Please enter a valid number: "; cin >> number; }
    return number;
}
bool IsLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }
short NumberOfDaysInMonth(int month, int year)
{
    if (month < 1 || month > 12) return 0;
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
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    int day = ReadPositiveNumberInRange("Enter a day to check? : ", 1, NumberOfDaysInMonth(month, year));
    short dayOrder = DayOfWeekOrder(day, month, year);
    cout << "Date      : " << day << "/" << month << "/" << year << endl;
    cout << "Day order : " << dayOrder << endl;
    cout << "Day Name  : " << DayShortName(dayOrder) << endl;
    return 0;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
حل سريع ودقيق مع تاريخ صالح.

## 🧩 Problem #08: Month Calendar
### 📝 وصف المشكلة (Problem Description)
طباعة تقويم شهر كامل.
### 💡 الفكرة البرمجية (Logic Breakdown)
تحديد بداية الأسبوع ثم طباعة الأيام في Grid.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
// Full source from #08_MonthCalendar.cpp
int ReadPositiveNumberInRange(string message, int From, int To){int number;cout<<message;cin>>number;while(cin.fail()||number<From||number>To){cin.clear();cin.ignore(10000,'\n');cout<<"Invalid Input! Please enter a valid number: ";cin>>number;}return number;}
bool IsLeapYear(int year){return (year%4==0&&year%100!=0)||(year%400==0);}
short NumberOfDaysInMonth(int month,int year){if(month<1||month>12){return 0;}int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};return month==2?(IsLeapYear(year)?29:28):days[month-1];}
short DayOfWeekOrder(int day,int month,int year){short a=(14-month)/12;short y=year-a;short m=month+12*a-2;return (day+y+y/4-y/100+y/400+(31*m)/12)%7;}
string MonthShortName(short MonthNumber){string Months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};return (Months[MonthNumber-1]);}
void PrintMonthCalendar(short Month,short Year){int NumberOfDays;int current=DayOfWeekOrder(1,Month,Year);NumberOfDays=NumberOfDaysInMonth(Month,Year);printf("\n _______________________%s________________________\n\n",MonthShortName(Month).c_str());printf("  sun    mon    tue    wed    thu    fri    sat\n");int i;for(i=0;i<current;i++)printf("       ");for(int j=1;j<=NumberOfDays;j++){printf("%4d   ",j);if(++i==7){i=0;printf("\n");}}printf("\n __________________________________________________\n");}
int main(){int year=ReadPositiveNumberInRange("Enter a year to check? : ",1,9999);int month=ReadPositiveNumberInRange("Enter a month to check? : ",1,12);PrintMonthCalendar(month,year);return 0;}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
النتيجة صحيحة، ويُفضّل لاحقًا تنسيق السورس متعدد الأسطر بدل السطر الواحد.

## 🧩 Problem #09: Year Calendar
### 📝 وصف المشكلة (Problem Description)
طباعة تقويم السنة بالكامل.
### 💡 الفكرة البرمجية (Logic Breakdown)
إعادة استخدام دالة طباعة الشهر لكل 12 شهر.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
// Full source from #09_YearCalendar.cpp
int ReadPositiveNumberInRange(string message,int From,int To){int number;cout<<message;cin>>number;while(cin.fail()||number<From||number>To){cin.clear();cin.ignore(10000,'\n');cout<<"Invalid Input! Please enter a valid number: ";cin>>number;}return number;}
bool IsLeapYear(int year){return (year%4==0&&year%100!=0)||(year%400==0);}
short NumberOfDaysInMonth(int month,int year){if(month<1||month>12){return 0;}int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};return month==2?(IsLeapYear(year)?29:28):days[month-1];}
short DayOfWeekOrder(int day,int month,int year){short a=(14-month)/12;short y=year-a;short m=month+12*a-2;return (day+y+y/4-y/100+y/400+(31*m)/12)%7;}
string MonthShortName(short MonthNumber){string Months[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};return (Months[MonthNumber-1]);}
void PrintMonthCalendar(short Month,short Year){int NumberOfDays;int current=DayOfWeekOrder(1,Month,Year);NumberOfDays=NumberOfDaysInMonth(Month,Year);printf("\n _______________________%s________________________\n\n",MonthShortName(Month).c_str());printf("  sun    mon    tue    wed    thu    fri    sat\n");int i;for(i=0;i<current;i++)printf("       ");for(int j=1;j<=NumberOfDays;j++){printf("%4d   ",j);if(++i==7){i=0;printf("\n");}}printf("\n __________________________________________________\n");}
void PrintYearCalendar(short Year){cout<<"_____________________________________________________________\n\n";cout<<"                   Calendar - "<<Year<<"\n\n";cout<<"_____________________________________________________________\n\n";for(int month=1;month<=12;month++){PrintMonthCalendar(month,Year);}}
int main(){int year=ReadPositiveNumberInRange("Enter a year to check? : ",1,9999);PrintYearCalendar(year);return 0;}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
إعادة الاستخدام قوية جدًا.

## 🧩 Problem #10: Days From Beginning Of Year
### 📝 وصف المشكلة (Problem Description)
إيجاد ترتيب اليوم داخل السنة.
### 💡 الفكرة البرمجية (Logic Breakdown)
جمع أيام الشهور السابقة مع يوم الشهر الحالي.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
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
bool IsLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }
short NumberOfDaysInMonth(int month, int year)
{
    if (month < 1 || month > 12) return 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : days[month - 1];
}
short NumberOfDaysFromTheBeginingOfTheYear(int day, int month, int year)
{
    short totalDays = 0;
    for (int m = 1; m < month; m++) totalDays += NumberOfDaysInMonth(m, year);
    totalDays += day;
    return totalDays;
}
int main()
{
    short year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    short month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    short day = ReadPositiveNumberInRange("Enter a day to check? : ", 1, NumberOfDaysInMonth(month, year));
    cout << "\nNumber of days from beginning of the year is " << NumberOfDaysFromTheBeginingOfTheYear(day, month, year) << "\n";
    return 0;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
أساس ممتاز لمسائل التاريخ التالية.

</div>
