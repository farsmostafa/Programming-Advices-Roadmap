<div dir="rtl">

# كورس 08: الخوارزميات وحل المشاكل - المستوى الرابع
# Algorithms & Problem Solving Level 4

| Problem Range | Status | Commit Hash |
|---|---|---|
| #01 - #10 | Completed | pending |

## 🧩 Problem #01: Number To Text
### 📝 وصف المشكلة (Problem Description)
المطلوب قراءة رقم موجب كبير نسبيًا (حتى حدود `long long`) ثم تحويله إلى تمثيل نصي باللغة الإنجليزية.  
المسألة تدريب قوي على التفكير الهرمي في الأرقام، لأن الرقم لا يُقرأ كقيمة واحدة، بل كمجموعات (وحدات، عشرات، مئات، آلاف، ملايين، مليارات).

### 💡 الفكرة البرمجية (Logic Breakdown)
نعتمد على `Recursion` لتقسيم الرقم تدريجيًا:
1. الأرقام من 1 إلى 19 لها أسماء ثابتة مباشرة.
2. الأرقام من 20 إلى 99 تنقسم إلى عشرات + باقي الآحاد.
3. ما بعد ذلك ينقسم إلى وحدات كبرى (Hundred / Thousand / Million / Billion) مع إعادة استدعاء نفس الدالة.
4. كل مستوى يعالج جزءه ويرجع استدعاءً لباقي الرقم.

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
    {
        return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 999999999999)
    {
        return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
    }

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
الحل صحيح ومنظم. الملاحظة الوحيدة: عند إدخال `0` يرجع نص فارغ، ويمكن لاحقًا إرجاع `"Zero"` لتجربة استخدام أوضح.

## 🧩 Problem #02 & #03: Leap Year
### 📝 وصف المشكلة (Problem Description)
المطلوب التحقق إذا كانت السنة كبيسة أو لا، وهي قاعدة أساسية في كل مسائل التاريخ.

### 💡 الفكرة البرمجية (Logic Breakdown)
قاعدة السنة الكبيسة:
1. إذا كانت السنة تقبل القسمة على 400 فهي كبيسة.
2. أو إذا كانت تقبل القسمة على 4 ولا تقبل القسمة على 100 فهي كبيسة.
3. غير ذلك فهي سنة عادية.

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
    {
        cout << year << " is a leap year.\n";
    }
    else
    {
        cout << year << " is not a leap year.\n";
    }
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
المنطق صحيح 100%. يوجد فقط خطأ مطبعي في مثال الإخراج داخل النص (`2023 is a leap year`) بينما المثال المفروض يكون `2024`.

## 🧩 Problem #04: Year Time Units
### 📝 وصف المشكلة (Problem Description)
المطلوب حساب عدد الأيام والساعات والدقائق والثواني في سنة محددة، مع مراعاة أن السنة الكبيسة تختلف عن العادية.

### 💡 الفكرة البرمجية (Logic Breakdown)
الفكرة ممتازة لأنها مبنية على طبقات:
1. نحدد الأيام أولًا عبر `IsLeapYear`.
2. الساعات = الأيام × 24.
3. الدقائق = الساعات × 60.
4. الثواني = الدقائق × 60.
هذا يضمن أن أي تعديل في المصدر الأساسي (عدد الأيام) ينعكس تلقائيًا على كل النتائج.

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

short NumberOfDaysInYear(int year)
{
    return IsLeapYear(year) ? 366 : 365;
}
short NumberOfHoursInYear(int year)
{
    return NumberOfDaysInYear(year) * 24;
}
int NumberOfMinutesInYear(int year)
{
    return NumberOfHoursInYear(year) * 60;
}
int NumberOfSecondsInYear(int year)
{
    return NumberOfMinutesInYear(year) * 60;
}

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
    cout << "\tex  : Please enter a year to check? 2000\n\n";
    cout << "\toutput : Number of Days in Year    [2000] is 366\n";
    cout << "\t         Number of Hours in Year   [2000] is 8784\n";
    cout << "\t         Number of Minutes in Year [2000] is 527040\n";
    cout << "\t         Number of Seconds in Year [2000] is 31622400\n";
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
تقسيم الدوال ممتاز ويطبق مبدأ الفصل بين الحساب والطباعة بشكل واضح.

## 🧩 Problem #05: Month Time Units
### 📝 وصف المشكلة (Problem Description)
نفس فكرة المسألة السابقة ولكن على مستوى شهر داخل سنة، مع ضرورة التعامل الصحيح مع فبراير.

### 💡 الفكرة البرمجية (Logic Breakdown)
1. نحسب أيام الشهر بدالة مستقلة.
2. نعتمد عليها لاشتقاق الساعات ثم الدقائق ثم الثواني.
3. نحمي الإدخال بدالة قراءة ضمن مدى `1..12` للشهر و`1..9999` للسنة.

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
    if (month < 1 || month > 12)
    {
        return 0;
    }
    if (month == 2)
    {
        return IsLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}
short NumberOfHoursInMonth(int month, int year)
{
    return NumberOfDaysInMonth(month, year) * 24;
}
int NumberOfMinutesInMonth(int month, int year)
{
    return NumberOfHoursInMonth(month, year) * 60;
}
int NumberOfSecondsInMonth(int month, int year)
{
    return NumberOfMinutesInMonth(month, year) * 60;
}

void PrintMonthInfo(int month, int year)
{
    cout << "\tNumber of Days in Month    [" << month << "] is " << NumberOfDaysInMonth(month, year) << endl;
    cout << "\tNumber of Hours in Month   [" << month << "] is " << NumberOfHoursInMonth(month, year) << endl;
    cout << "\tNumber of Minutes in Month [" << month << "] is " << NumberOfMinutesInMonth(month, year) << endl;
    cout << "\tNumber of Seconds in Month [" << month << "] is " << NumberOfSecondsInMonth(month, year) << endl;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to print Number of {Days, Hours, Minutes, Seconds} in a certain month.\n";
    cout << "\tex  : Please enter a year  to check? 2000\n\n";
    cout << "\tex  : Please enter a month to check? 2\n\n";
    cout << "\toutput : Number of Days in month    [2] is 29\n";
    cout << "\t         Number of Hours in month   [2] is 576\n";
    cout << "\t         Number of Minutes in month [2] is 34560\n";
    cout << "\t         Number of Seconds in month [2] is 2073600\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    PrintMonthInfo(month, year);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
دقة عالية في التحقق من المدخلات، وبنية الحساب قابلة لإعادة الاستخدام لاحقًا بسهولة.

## 🧩 Problem #06: Number Of Days In Month (Short Logic)
### 📝 وصف المشكلة (Problem Description)
المطلوب نسخة مختصرة لحساب عدد أيام شهر معيّن، مع الحفاظ على صحة النتيجة.

### 💡 الفكرة البرمجية (Logic Breakdown)
بدل سلسلة شروط طويلة، نستخدم:
1. مصفوفة ثابتة لأيام الشهور.
2. شرط خاص بفبراير فقط لتعديل 28/29 حسب السنة الكبيسة.

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
    if (month < 1 || month > 12)
    {
        return 0;
    }
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : days[month - 1];
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #06 :Write a program to print Number of Days in a certain Month.\n";
    cout << "\tex  : Please enter a year to  check? 2000\n\n";
    cout << "\tex  : Please enter a month to check? 2\n\n";
    cout << "\toutput : Number of Days in month    [2] is 29\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    int month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    cout << "\nNumber of Days in month [" << month << "] is " << NumberOfDaysInMonth(month, year) << "\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
الصيغة المختصرة هنا أفضل للصيانة وتقلل احتمالات الأخطاء عند تعديل الشهور مستقبلًا.

## 🧩 Problem #07: Day Name
### 📝 وصف المشكلة (Problem Description)
إدخال تاريخ كامل (يوم/شهر/سنة) ثم طباعة ترتيب اليوم داخل الأسبوع واسمه (Sunday, Monday, ...).

### 💡 الفكرة البرمجية (Logic Breakdown)
1. نتحقق من تاريخ الإدخال بحيث اليوم لا يتجاوز عدد أيام الشهر.
2. نحسب ترتيب اليوم عبر معادلة رياضية معروفة.
3. نستخدم مصفوفة أسماء أيام لتحويل الرقم إلى اسم مقروء.

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
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
الحل سريع، دقيق، وعملي جدًا لأي نظام يعتمد على تواريخ التقويم.

## 🧩 Problem #08: Month Calendar
### 📝 وصف المشكلة (Problem Description)
طباعة Calendar كامل لشهر محدد (شبكة أسبوعية من الأحد للسبت) بتنسيق مناسب للقراءة.

### 💡 الفكرة البرمجية (Logic Breakdown)
1. نحسب يوم الأسبوع لأول يوم في الشهر.
2. نطبع فراغات أول الصف قبل بداية الأيام.
3. نطبع الأيام من 1 إلى آخر يوم في الشهر.
4. كل 7 خانات ننتقل لسطر جديد.

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
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
النسخة الحالية جيدة جدًا في العرض. لو حبيت توحيد الستايل لاحقًا، نقدر نحول مخرجات `printf` إلى `cout` بالكامل أو العكس.

## 🧩 Problem #09: Year Calendar
### 📝 وصف المشكلة (Problem Description)
توسيع فكرة التقويم الشهري إلى تقويم سنوي كامل عبر طباعة كل الشهور بالترتيب.

### 💡 الفكرة البرمجية (Logic Breakdown)
1. نطبع عنوان السنة.
2. نمر على الشهور من 1 إلى 12.
3. نعيد استخدام `PrintMonthCalendar` لكل شهر.
هذا النوع من إعادة الاستخدام يقلل التكرار ويثبت منطق التقويم في مكان واحد.

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
    printf("  sun    mon    tue    wed    thu    fri    sat\n");
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

void PrintYearCalendar(short Year)
{
    cout << "_____________________________________________________________\n\n";
    cout << "                   Calendar - " << Year << "\n\n";
    cout << "_____________________________________________________________\n\n";
    for (int month = 1; month <= 12; month++)
    {
        PrintMonthCalendar(month, Year);
    }
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #09 :Write a program to print year Calender.\n";
    cout << "\tex  : Please enter a year  ? 2022\n\n";
    cout << "\tPrinting year calendar for 2022 :\n\n";
    
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    PrintYearCalendar(year);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
إعادة الاستخدام هنا ممتازة جدًا وتخلي تحديث منطق التقويم لاحقًا أسهل بكثير.

## 🧩 Problem #10: Days From Beginning Of Year
### 📝 وصف المشكلة (Problem Description)
المطلوب حساب رقم اليوم داخل السنة (مثال: 20/9/2022 يساوي اليوم 263 من السنة).

### 💡 الفكرة البرمجية (Logic Breakdown)
1. نجمع عدد أيام كل الشهور السابقة للشهر الحالي.
2. نضيف اليوم الحالي على المجموع.
3. نعتمد على `NumberOfDaysInMonth` لضمان التعامل الصحيح مع فبراير في السنوات الكبيسة.

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

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #10 :Write a program to print total days from the beginning of year.\n";
    cout << "\tex     : Please enter a year   ? 2022\n";
    cout << "\t         Please enter a month  ? 9\n";
    cout << "\t         Please enter a day    ? 20\n";
    cout << "\toutput : Number of days from beginning of the year is 263\n\n";

    cout << "\n\n-------------------------------------------------\n\n";
    short year = ReadPositiveNumberInRange("Enter a year to check? : ", 1, 9999);
    short month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    short day = ReadPositiveNumberInRange("Enter a day to check? : ", 1, NumberOfDaysInMonth(month, year));
    cout << "\nNumber of days from beginning of the year is " << NumberOfDaysFromTheBeginingOfTheYear(day, month, year) << "\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل قوي جدًا ويعتبر لبنة أساسية لمسائل التحويل بين التاريخ واليوم الترتيبي داخل السنة.

</div>
