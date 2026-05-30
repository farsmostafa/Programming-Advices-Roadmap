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

## 🧩 Problem #11: Date From Day Order In Year
### 📝 وصف المشكلة (Problem Description)
تحويل التاريخ إلى رقم اليوم داخل السنة، ثم عكس العملية مرة أخرى (من رقم اليوم إلى تاريخ فعلي).

### 💡 الفكرة البرمجية (Logic Breakdown)
الفكرة تعتمد على دالتين متكاملتين:
1. `NumberOfDaysFromTheBeginingOfTheYear` لحساب الترتيب السنوي.
2. `GetDateFromDayOrderInYear` لفك هذا الترتيب وإعادة بناء اليوم/الشهر/السنة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
// Source: #11_DateFromDayOrderInYear.cpp
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
struct sDate { short day; short month; short year; };
sDate GetDateFromDayOrderInYear(short dayOrder, short year)
{
    sDate date; date.year = year; date.month = 1;
    if (dayOrder < 1) { date.day = 0; return date; }
    while (dayOrder > NumberOfDaysInMonth(date.month, year))
    {
        dayOrder -= NumberOfDaysInMonth(date.month, year);
        date.month++;
    }
    date.day = dayOrder;
    return date;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
ربط الاتجاهين (Forward/Reverse) ممتاز جدًا، لكنه محتاج اتساق أعلى في التعامل مع `dayOrder` إذا تجاوزت نفس السنة.

## 🧩 Problem #12: Add Days To Date
### 📝 وصف المشكلة (Problem Description)
إضافة عدد أيام كبير إلى تاريخ معيّن وإرجاع التاريخ النهائي.
### 💡 الفكرة البرمجية (Logic Breakdown)
نحوّل التاريخ إلى رقم يوم داخل السنة + الأيام المضافة، ثم نتجاوز السنوات واحدة تلو الأخرى حتى نصل للسنة الصحيحة.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
// Source: #12_AddDaysToDate.cpp
// Uses DateAddDays + GetDateFromDayOrderInYear
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
المنهج صحيح ومرن جدًا. ملاحظة صغيرة: `daysToAdd` نوعه `short` وقد يقيّد المدخلات الكبيرة.

## 🧩 Problem #13: Date1 Less Than Date2
### 📝 وصف المشكلة (Problem Description)
التحقق هل التاريخ الأول أقدم من التاريخ الثاني.
### 💡 الفكرة البرمجية (Logic Breakdown)
مقارنة هرمية: سنة ثم شهر ثم يوم.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
bool IsDate1BeforeDate2(sDate date1, sDate date2){
    return (date1.year < date2.year) || 
           (date1.year == date2.year && date1.month < date2.month) || 
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
منطقي جدًا ومباشر. يوجد تنسيق غريب بسيط في تعريف `main` داخل الملف يحتاج ترتيب.

## 🧩 Problem #14: Date1 Equals Date2
### 📝 وصف المشكلة (Problem Description)
التحقق من التطابق الكامل بين تاريخين.
### 💡 الفكرة البرمجية (Logic Breakdown)
المساواة تكون فقط إذا (سنة + شهر + يوم) متطابقين بالكامل.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
bool IsDate1EqualsDate2(sDate date1, sDate date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
دالة صغيرة وصحيحة، وتكمل بشكل ممتاز دوال المقارنة الأخرى.

## 🧩 Problem #15: Last Day / Last Month
### 📝 وصف المشكلة (Problem Description)
فحص إذا كان التاريخ هو آخر يوم في شهره، وهل الشهر نفسه هو آخر شهر في السنة.
### 💡 الفكرة البرمجية (Logic Breakdown)
دالتان Boolean منفصلتان:
1. مقارنة اليوم مع `NumberOfDaysInMonth`.
2. التحقق أن الشهر يساوي 12.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
bool IsLastDayInMonth(sDate Date)
{
    return Date.day == NumberOfDaysInMonth(Date.month, Date.year);
}
bool IsLastMonthInYear(sDate Date)
{
    return Date.month == 12;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
تقسيم واضح وقابل لإعادة الاستخدام مباشرة في مسائل الزيادة/النقصان.

## 🧩 Problem #16: Increase Date By One Day
### 📝 وصف المشكلة (Problem Description)
تحديث التاريخ بيوم واحد بشكل صحيح عند نهاية الشهر أو نهاية السنة.
### 💡 الفكرة البرمجية (Logic Breakdown)
إذا كان اليوم الأخير من الشهر:
- إن كان ديسمبر: ننتقل لسنة جديدة.
- غير ذلك: ننتقل للشهر التالي.
وإلا نزيد اليوم فقط.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
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
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه الدالة هي قلب أغلب مسائل التاريخ اللاحقة، والimplementation الحالي ممتاز.

## 🧩 Problem #17: Difference In Days
### 📝 وصف المشكلة (Problem Description)
حساب عدد الأيام بين تاريخين.
### 💡 الفكرة البرمجية (Logic Breakdown)
نمشي يومًا بيوم من الأصغر للأكبر باستخدام `IncreaseDateByOneDay` مع عداد.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
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
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
صحيح جدًا وبسيط الفهم، لكنه خطي زمنيًا (O(days)) عند الفروق الكبيرة.

## 🧩 Problem #18: Your Age In Days
### 📝 وصف المشكلة (Problem Description)
حساب عمر المستخدم بالأيام بالاعتماد على تاريخ الميلاد وتاريخ النظام الحالي.
### 💡 الفكرة البرمجية (Logic Breakdown)
قراءة تاريخ الميلاد + جلب تاريخ النظام (`tm`) ثم إعادة استخدام دالة الفروق.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
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
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
حل ممتاز عمليًا، وتوابع `tm` مستخدمة بطريقة صحيحة.

## 🧩 Problem #19: Difference In Negative Days
### 📝 وصف المشكلة (Problem Description)
دعم إخراج فرق الأيام بالقيمة السالبة عندما يكون تاريخ البداية بعد تاريخ النهاية.
### 💡 الفكرة البرمجية (Logic Breakdown)
نفس دالة المسألة #17 بالفعل تدعم هذا عبر `swapFlagValue` وإرجاع `-counter`.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
return swapFlagValue ? -counter : counter;
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
حل ذكي جدًا لأنه يحافظ على دالة واحدة موحدة بدل نسختين منفصلتين للحالة الموجبة والسالبة.

## 🧩 Problem #20: Increase Date By X Days (Start Of Series)
### 📝 وصف المشكلة (Problem Description)
بداية سلسلة مسائل #20 إلى #32 الخاصة بزيادة التاريخ بأشكال متعددة (أيام، أسابيع، شهور، سنوات...).
### 💡 الفكرة البرمجية (Logic Breakdown)
في Problem #20 تحديدًا: زيادة التاريخ بعدد X من الأيام عبر تكرار دالة `IncreaseDateByOneDay`.
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
sDate IncreaseDateByXDays(sDate date, int days)
{
    for (int i = 0; i < days; i++)
    {
        date = IncreaseDateByOneDay(date);
    }
    return date;
}
```
</div>
### 🛠️ ملاحظات هندسية (Engineering Notes)
قاعدة ممتازة لباقي دوال السلسلة. الملف الأصلي `#20_To_32` يضم مجموعة كاملة ومترابطة من دوال الزيادة.
## 🧩 Problem #21: Increase Date By One Week
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة تاريخ كامل بمقدار أسبوع واحد. أهمية المسألة أنها لا تتعامل مع رقم اليوم فقط، بل يجب أن تحافظ على صحة التاريخ عند المرور من نهاية شهر إلى بداية شهر جديد أو من نهاية سنة إلى بداية سنة جديدة.

### 💡 الفكرة البرمجية (Logic Breakdown)
الفكرة تعتمد على إعادة استخدام الدالة الأساسية IncreaseDateByOneDay سبع مرات. بهذه الطريقة لا نكرر منطق الانتقال بين الشهور والسنين، ونضمن أن كل حالات الحدود مثل 31/12 أو آخر يوم في فبراير يتم التعامل معها من نفس المصدر.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه المسألة تؤكد قيمة بناء Primitive صغيرة صحيحة ثم تركيب دوال أكبر فوقها. الكود الكامل موجود في الملف المجمع لأن مسائل #20 إلى #32 تعمل كسلسلة واحدة مترابطة.
## 🧩 Problem #22: Increase Date By X Weeks
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ بعدد أسابيع يحدده المستخدم. كل أسبوع يساوي 7 أيام، لكن بدل تحويلها يدويًا لأيام، يتم الاعتماد على دالة الأسبوع الواحد.

### 💡 الفكرة البرمجية (Logic Breakdown)
نستخدم Loop بعدد الأسابيع، وفي كل مرة نستدعي IncreaseDateByOneWeek. هذا يجعل الدالة واضحة جدًا وسهلة التتبع، لأن كل مستوى من الدوال مسؤول عن وحدة زمنية محددة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل مناسب للتعلم لأنه يوضح مفهوم Layered Abstractions. لو أردنا تحسين الأداء لاحقًا، يمكن تحويل الأسابيع إلى أيام واستدعاء دالة أكثر مباشرة.
## 🧩 Problem #23: Increase Date By One Month
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ شهرًا واحدًا مع الحفاظ على يوم صالح. التحدي الحقيقي يظهر عند التعامل مع ديسمبر أو مع أيام مثل 31 عند الانتقال إلى شهر لا يحتوي 31 يومًا.

### 💡 الفكرة البرمجية (Logic Breakdown)
إذا كان الشهر الحالي هو ديسمبر، نزيد السنة ونرجع الشهر إلى يناير. بعدها نستخدم min بين اليوم الحالي وعدد أيام الشهر الجديد حتى لا ينتج تاريخ غير صالح.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
استخدام min هنا نقطة هندسية مهمة جدًا؛ لأنها تمنع أخطاء مثل 31/1 إلى 31/2. هذا يوضح أن Date Arithmetic ليس مجرد جمع أرقام.
## 🧩 Problem #24: Increase Date By X Months
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ بعدد شهور. هذه المسألة تبني مباشرة فوق منطق زيادة شهر واحد.

### 💡 الفكرة البرمجية (Logic Breakdown)
نكرر IncreaseDateByOneMonth بعدد الشهور المطلوب. كل تكرار يتولى بنفسه تصحيح نهاية السنة وعدد أيام الشهر.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
الوضوح هنا أهم من السرعة. التكرار يجعل السلوك قابلًا للفهم، خصوصًا أثناء التعلم ومراجعة الحالات الحدية.
## 🧩 Problem #25: Increase Date By One Year
### 📝 وصف المشكلة (Problem Description)
المطلوب إضافة سنة واحدة لتاريخ معيّن. التحدي الأساسي هو تاريخ 29 فبراير إذا انتقلنا إلى سنة غير كبيسة.

### 💡 الفكرة البرمجية (Logic Breakdown)
نزيد year بمقدار 1، ثم نثبت day باستخدام min بين اليوم الحالي وعدد أيام نفس الشهر في السنة الجديدة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
الحل يحافظ على صحة التاريخ بدل افتراض أن نفس اليوم موجود في كل سنة. هذه نقطة مهمة جدًا في أي نظام تقويم.
## 🧩 Problem #26: Increase Date By X Years
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ بعدد سنوات باستخدام الطريقة التكرارية.

### 💡 الفكرة البرمجية (Logic Breakdown)
نكرر IncreaseDateByOneYear بعدد السنوات المطلوب. كل سنة يتم تطبيق نفس قواعد التصحيح الخاصة بالأيام والشهور.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
النسخة التكرارية ممتازة لفهم المنطق، لكنها قد لا تكون الأفضل أداءً عند القيم الكبيرة جدًا.
## 🧩 Problem #27: Increase Date By X Years Faster
### 📝 وصف المشكلة (Problem Description)
المطلوب تنفيذ نفس فكرة زيادة السنوات لكن بطريقة أسرع وأكثر مباشرة.

### 💡 الفكرة البرمجية (Logic Breakdown)
بدل تكرار الزيادة سنة بسنة، نضيف عدد السنوات مباشرة إلى year، ثم نصحح day باستخدام NumberOfDaysInMonth.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه نسخة محسّنة من حيث الأداء. الجميل أنها لا تضحي بصحة التاريخ لأنها ما زالت تعالج حالة 29 فبراير ونهايات الشهور.
## 🧩 Problem #28: Increase Date By One Decade
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ بعقد واحد، أي عشر سنوات.

### 💡 الفكرة البرمجية (Logic Breakdown)
الدالة لا تعيد كتابة منطق جديد، بل تستدعي IncreaseDateByXYearsFaster بقيمة 10.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
إعادة الاستخدام هنا ممتازة. الدالة تصبح اسمًا دلاليًا واضحًا فوق منطق السنوات السريع.
## 🧩 Problem #29: Increase Date By X Decades
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ بعدد عقود. كل عقد يساوي عشر سنوات.

### 💡 الفكرة البرمجية (Logic Breakdown)
نكرر دالة IncreaseDateByOneDecade بعدد العقود المطلوب، فنحافظ على نفس منطق التصحيح في كل خطوة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل واضح ومناسب للتدرج التعليمي، لكنه أقل سرعة من النسخة المباشرة في المسألة التالية.
## 🧩 Problem #30: Increase Date By X Decades Faster
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ بعدد عقود بطريقة مباشرة وسريعة.

### 💡 الفكرة البرمجية (Logic Breakdown)
نضيف decades * 10 إلى السنة مباشرة، ثم نعيد ضبط اليوم بحيث لا يتجاوز عدد أيام الشهر في السنة الجديدة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه النسخة هي الأفضل أداءً عند القيم الكبيرة، وتوضح الفرق بين الحل التكراري والحل المباشر.

## 🧩 Problem #31: Increase Date By One Century
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ بمقدار قرن كامل، أي 100 سنة، مع الحفاظ على صحة اليوم داخل الشهر.

### 💡 الفكرة البرمجية (Logic Breakdown)
الدالة تضيف 100 مباشرة إلى السنة، ثم تستخدم NumberOfDaysInMonth مع min لتجنب تاريخ غير صالح مثل 29 فبراير في سنة غير كبيسة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه نسخة مباشرة عالية الأداء، وتوضح أن الزيادات الكبيرة لا تحتاج Loop إذا كان التغيير في السنة فقط.
## 🧩 Problem #32: Increase Date By One Millennium
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ بمقدار ألف سنة. المسألة تختبر نفس فكرة القرون لكن على مدى أكبر.

### 💡 الفكرة البرمجية (Logic Breakdown)
نزيد year بمقدار 1000 ثم نصحح day بنفس أسلوب مسائل السنوات والعقود، لأن صلاحية اليوم تعتمد على الشهر والسنة الجديدة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
المنطق ممتاز ويؤكد أن نفس قاعدة تصحيح اليوم يمكن استخدامها مع أي قفزة زمنية كبيرة.
## 🧩 Problem #33: Decrease Date By One Day
### 📝 وصف المشكلة (Problem Description)
بداية سلسلة إنقاص التاريخ. المطلوب طرح يوم واحد من التاريخ مع التعامل الصحيح مع بداية الشهر وبداية السنة.

### 💡 الفكرة البرمجية (Logic Breakdown)
إذا كان اليوم أكبر من 1 نقلله مباشرة. إذا كان اليوم 1، نرجع للشهر السابق، ولو كنا في يناير نرجع إلى ديسمبر من السنة السابقة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه الدالة هي الأساس لكل دوال الإنقاص التالية، لذلك صحة Boundary Cases فيها مهمة جدًا.
## 🧩 Problem #34: Decrease Date By X Days
### 📝 وصف المشكلة (Problem Description)
طرح عدد أيام يحدده المستخدم من تاريخ معين.

### 💡 الفكرة البرمجية (Logic Breakdown)
نكرر DecreaseDateByOneDay بعدد الأيام المطلوب، فتنتقل كل حالة عبر نفس منطق اليوم الواحد.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل واضح وسهل المراجعة، لكنه خطي الأداء حسب عدد الأيام.
## 🧩 Problem #35: Decrease Date By One Week
### 📝 وصف المشكلة (Problem Description)
طرح أسبوع واحد من التاريخ، أي سبعة أيام.

### 💡 الفكرة البرمجية (Logic Breakdown)
نكرر طرح يوم واحد سبع مرات حتى نحافظ على نفس منطق الانتقال بين الشهور والسنين.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
إعادة استخدام ممتازة للدالة الأساسية بدل كتابة حسابات جديدة.
## 🧩 Problem #36: Decrease Date By X Weeks
### 📝 وصف المشكلة (Problem Description)
طرح عدد أسابيع من تاريخ معين.

### 💡 الفكرة البرمجية (Logic Breakdown)
نحول الأسابيع إلى أيام ضمنيًا عبر Loop بعدد Weeks * 7، وكل مرة نطرح يومًا واحدًا.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
واضح ومنطقي، ومناسب جدًا للتعلم رغم أنه قد يكون أبطأ في القيم الكبيرة.
## 🧩 Problem #37: Decrease Date By One Month
### 📝 وصف المشكلة (Problem Description)
طرح شهر واحد مع مراعاة اختلاف أطوال الشهور.

### 💡 الفكرة البرمجية (Logic Breakdown)
إذا كان الشهر يناير نرجع إلى ديسمبر وننقص السنة، وإلا ننقص الشهر فقط. بعدها نصحح اليوم باستخدام min.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
تصحيح اليوم ضروري لحالات مثل 31 مارس عند الرجوع إلى فبراير.
## 🧩 Problem #38: Decrease Date By X Months
### 📝 وصف المشكلة (Problem Description)
طرح عدد شهور من التاريخ.

### 💡 الفكرة البرمجية (Logic Breakdown)
نكرر DecreaseDateByOneMonth بعدد الشهور المطلوب حتى نحافظ على قواعد التصحيح نفسها.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل تكراري واضح ومتين، ومناسب عندما نريد تتبع الحركة شهرًا بشهر.
## 🧩 Problem #39: Decrease Date By One Year
### 📝 وصف المشكلة (Problem Description)
طرح سنة واحدة من التاريخ مع الحفاظ على يوم صالح.

### 💡 الفكرة البرمجية (Logic Breakdown)
نقلل السنة بمقدار 1، ثم نضبط اليوم حسب عدد أيام الشهر في السنة الجديدة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
يعالج بدقة حالة 29 فبراير عند الرجوع إلى سنة غير كبيسة.
## 🧩 Problem #40: Decrease Date By X Years
### 📝 وصف المشكلة (Problem Description)
طرح عدد سنوات من التاريخ بالطريقة التكرارية.

### 💡 الفكرة البرمجية (Logic Breakdown)
نكرر DecreaseDateByOneYear بعدد السنوات المطلوبة، وكل تكرار يصحح اليوم إن احتاج.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

`cpp
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
`

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
واضح ومناسب تعليميًا، مع إمكانية استخدام النسخة السريعة لاحقًا لتحسين الأداء.

</div>

