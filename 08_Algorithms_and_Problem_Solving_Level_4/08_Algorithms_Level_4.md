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
المطلوب تحويل التاريخ إلى رقم اليوم داخل السنة، ثم استخدام هذا الرقم لإعادة بناء التاريخ مرة أخرى. هذه المسألة تربط بين تمثيلين مهمين للتاريخ: التاريخ العادي، والترتيب السنوي.

### 💡 الفكرة البرمجية (Logic Breakdown)
نحسب أولًا عدد الأيام من بداية السنة حتى التاريخ المدخل. بعد ذلك نبدأ من شهر يناير ونطرح أيام كل شهر من dayOrder حتى نصل للشهر واليوم الصحيحين.

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

struct sDate
{
    short day;
    short month;
    short year;
};

sDate GetDateFromDayOrderInYear(short dayOrder, short year)
{
    sDate date;
    date.year = year;
    date.month = 1;
    if (dayOrder < 1)
    {
        date.day = 0;
        cout << "Invalid day order! Day order should be greater than 0.\n";
        return date;
    }else if (dayOrder > (IsLeapYear(year) ? 366 : 365))
    {
        short yearsToAdd = 0;
        while (dayOrder > (IsLeapYear(year + yearsToAdd) ? 366 : 365))
        {
            dayOrder -= (IsLeapYear(year + yearsToAdd) ? 366 : 365);
            yearsToAdd++;
        }
        date.year += yearsToAdd;
        cout << "Day order exceeds the number of days in the year " << year << ". It corresponds to a date in the year " << date.year << ".\n";
    }
    while (dayOrder > NumberOfDaysInMonth(date.month, year))
    {
        dayOrder -= NumberOfDaysInMonth(date.month, year);
        date.month++;
    }
    date.day = dayOrder;
    return date;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #11 :Write a program to print total days from the beginning of year, then Take the total days and convert them back to date.\n";
    cout << "\tex     : Please enter a year   ? 2022\n";
    cout << "\t         Please enter a month  ? 9\n";
    cout << "\t         Please enter a day    ? 20\n";
    cout << "\toutput : Number of days from beginning of the year is 263\n\n";
    cout << "\t         Date for [263] is: 20/9/2022";
    cout << "\n\n-------------------------------------------------\n";
    short year = ReadPositiveNumberInRange("Enter a year  to check? : ", 1, 9999);
    short month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    short day = ReadPositiveNumberInRange("Enter a day   to check? : ", 1, NumberOfDaysInMonth(month, year));
    cout << "\nNumber of days from beginning of the year is " << NumberOfDaysFromTheBeginingOfTheYear(day, month, year) << "\n";
    sDate date = GetDateFromDayOrderInYear(NumberOfDaysFromTheBeginingOfTheYear(day, month, year), year);
    cout << "Date for [" << NumberOfDaysFromTheBeginingOfTheYear(day, month, year) << "] is: "
         << date.day << "/" << date.month << "/" << date.year << "\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
المسألة ممتازة لأنها تثبت أن التاريخ يمكن تمثيله بأكثر من شكل. يوجد ملاحظة صغيرة في الدالة عند تجاوز dayOrder لسنة معينة: داخل while يتم استخدام year الأصلي في NumberOfDaysInMonth بدل date.year بعد التعديل.
## 🧩 Problem #12: Add Days To Date
### 📝 وصف المشكلة (Problem Description)
المطلوب قراءة تاريخ وعدد أيام، ثم حساب التاريخ الجديد بعد إضافة هذه الأيام. التحدي هنا أن عدد الأيام قد يعبر شهورًا وسنينًا كثيرة.

### 💡 الفكرة البرمجية (Logic Breakdown)
نحول التاريخ الحالي إلى ترتيب يوم داخل السنة، ثم نضيف الأيام المطلوبة. إذا تجاوز المجموع عدد أيام السنة، نطرح سنة كاملة ونزيد year حتى نصل للسنة النهائية.

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

struct sDate
{
    short day;
    short month;
    short year;
};

sDate GetDateFromDayOrderInYear(short dayOrder, short year)
{
    sDate date;
    date.year = year;
    date.month = 1;
    if (dayOrder < 1)
    {
        date.day = 0;
        cout << "Invalid day order! Day order should be greater than 0.\n";
        return date;
    }
    else if (dayOrder > (IsLeapYear(year) ? 366 : 365))
    {
        short yearsToAdd = 0;
        while (dayOrder > (IsLeapYear(year + yearsToAdd) ? 366 : 365))
        {
            dayOrder -= (IsLeapYear(year + yearsToAdd) ? 366 : 365);
            yearsToAdd++;
        }
        date.year += yearsToAdd;
        cout << "Day order exceeds the number of days in the year " << year << ". It corresponds to a date in the year " << date.year << ".\n";
    }
    while (dayOrder > NumberOfDaysInMonth(date.month, year))
    {
        dayOrder -= NumberOfDaysInMonth(date.month, year);
        date.month++;
    }
    date.day = dayOrder;
    return date;
}

sDate DateAddDays(sDate date, short daysToAdd)
{
    short totalDays = NumberOfDaysFromTheBeginingOfTheYear(date.day, date.month, date.year) + daysToAdd;
    date.month = 1;
    while (true)
    {
        short daysInCurrentYear = IsLeapYear(date.year) ? 366 : 365;
        if (totalDays <= daysInCurrentYear)
        {
            break;
        }
        totalDays -= daysInCurrentYear;
        date.year++;
    }
    sDate newDate = GetDateFromDayOrderInYear(totalDays, date.year);
    return newDate;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #12 :Write a program to read date and read how many days to add to it, print the results on screen.\n";
    cout << "\tex     : Please enter a year   ? 2022\n";
    cout << "\t         Please enter a month  ? 10\n";
    cout << "\t         Please enter a day    ? 10\n";
    cout << "\t         how many days to add  ? 2500\n";
    cout << "\toutput : Date for [263] is: 14/8/2029";
    cout << "\n\n-------------------------------------------------\n";
    sDate date;
    date.year = ReadPositiveNumberInRange("Enter a year  to check? : ", 1, 9999);
    date.month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    date.day = ReadPositiveNumberInRange("Enter a day   to check? : ", 1, NumberOfDaysInMonth(date.month, date.year));
    short daysToAdd = ReadPositiveNumberInRange("how many days to add? : ", 1, 9999);
    sDate newDate = DateAddDays(date, daysToAdd);
    cout << "Date for [" << daysToAdd << "] is: " << newDate.day << "/" << newDate.month << "/" << newDate.year;
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل قوي ومناسب للأرقام الكبيرة. ملاحظة: daysToAdd معرف كـ short في main، وهذا قد يحد القيم الكبيرة رغم أن الدالة نفسها تستقبل int في أجزاء أخرى.
## 🧩 Problem #13: Date1 Less Than Date2
### 📝 وصف المشكلة (Problem Description)
المطلوب مقارنة تاريخين ومعرفة هل التاريخ الأول يأتي قبل التاريخ الثاني.

### 💡 الفكرة البرمجية (Logic Breakdown)
نقارن السنة أولًا، ثم الشهر إذا كانت السنة متساوية، ثم اليوم إذا كان الشهر أيضًا متساويًا. هذا هو الترتيب الطبيعي للمقارنة الزمنية.

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

bool IsDate1BeforeDate2(sDate date1, sDate date2){
    return (date1.year < date2.year) || 
           (date1.year == date2.year && date1.month < date2.month) || 
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

    int
    main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #13 :Write a program to read date1, date2 and check if Date 1 is Less than Date 2\n";
    cout << "\tex     : Please enter a year 1  ? 2022\n";
    cout << "\t         Please enter a month 1 ? 10\n";
    cout << "\t         Please enter a day 1   ? 10\n";
    cout << "\t       : Please enter a year 2  ? 2022\n";
    cout << "\t         Please enter a month 2 ? 4\n";
    cout << "\t         Please enter a day 2   ? 10\n";
    cout << "\toutput : No, Date 1 is not less than Date 2";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    sDate date2 = ReadDate("Enter Date 2:");
    if (IsDate1BeforeDate2(date1, date2))
    {
        cout << "Yes, Date 1 is less than Date 2";
    }
    else
    {
        cout << "No, Date 1 is not less than Date 2";
    }
    
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
منطق المقارنة صحيح وواضح. يوجد فقط تنسيق غريب حول تعريف main في الملف ويستحق تنظيف لاحقًا.
## 🧩 Problem #14: Date1 Equals Date2
### 📝 وصف المشكلة (Problem Description)
المطلوب التحقق من أن تاريخين متطابقان بالكامل.

### 💡 الفكرة البرمجية (Logic Breakdown)
التاريخان يكونان متساويين فقط إذا كانت السنة والشهر واليوم كلها متساوية.

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

bool IsDate1EqualsDate2(sDate date1, sDate date2)
{
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #14 :Write a program to read date1, date2 and check if Date 1 Equals Date 2\n";
    cout << "\tex     : Please enter a year 1  ? 2022\n";
    cout << "\t         Please enter a month 1 ? 10\n";
    cout << "\t         Please enter a day 1   ? 10\n";
    cout << "\t       : Please enter a year 2  ? 2022\n";
    cout << "\t         Please enter a month 2 ? 4\n";
    cout << "\t         Please enter a day 2   ? 10\n";
    cout << "\toutput : No, Date 1 is not equal Date 2";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    sDate date2 = ReadDate("Enter Date 2:");
    if (IsDate1EqualsDate2(date1, date2))
    {
        cout << "Yes, Date 1 is equal Date 2";
    }
    else
    {
        cout << "No, Date 1 is not equal Date 2";
    }

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
دالة صغيرة لكنها مهمة جدًا لأنها تكمل دوال Before وAfter لاحقًا وتمنع تكرار شروط المساواة.
## 🧩 Problem #15: Last Day / Last Month
### 📝 وصف المشكلة (Problem Description)
المطلوب فحص خاصيتين في التاريخ: هل اليوم هو آخر يوم في الشهر؟ وهل الشهر هو آخر شهر في السنة؟

### 💡 الفكرة البرمجية (Logic Breakdown)
نستخدم NumberOfDaysInMonth لمعرفة آخر يوم فعلي في الشهر، ونقارن الشهر بالقيمة 12 لمعرفة هل هو ديسمبر.

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

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #15 : Write a program to read date and check \n   - If it is last bay in Month\n   - If it is last Month In Year \n";
    cout << "\tex     : Please enter a year  ? 2022\n";
    cout << "\t         Please enter a month ? 12\n";
    cout << "\t         Please enter a day   ? 10\n";
    cout << "\toutput : No, it is not last day in month\n";
    cout << "\t         Yes, it is last month in year\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    if (IsLastDayInMonth(date1))
        cout << "Yes, it is last day in month\n";
    else
        cout << "No, it is not last day in month\n";

    if (IsLastMonthInYear(date1))
        cout << "Yes, it is last month in year\n";
    else
        cout << "No, it is not last month in year\n";

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه الدوال تصبح أساسًا مهمًا في IncreaseDateByOneDay لأن الانتقال بين الشهور والسنين يعتمد عليها.
## 🧩 Problem #16: Increase Date By One Day
### 📝 وصف المشكلة (Problem Description)
المطلوب زيادة التاريخ يومًا واحدًا فقط، لكن مع التعامل الصحيح مع نهاية الشهر ونهاية السنة.

### 💡 الفكرة البرمجية (Logic Breakdown)
إذا لم يكن اليوم آخر يوم في الشهر نزيد day فقط. إذا كان آخر يوم، ننتقل للشهر التالي أو للسنة التالية إذا كان الشهر ديسمبر.

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

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #16 : Write a program to read a date and make a function to increase date by one day.\n";
    cout << "\tex     : Please enter a year  ? 2022\n";
    cout << "\t         Please enter a month ? 12\n";
    cout << "\t         Please enter a day   ? 10\n";
    cout << "\toutput : Date after adding one day is: 11/12/2022\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    sDate date2 = IncreaseDateByOneDay(date1);
    cout << "Date after adding one day is: " << date2.day << "/" << date2.month << "/" << date2.year;
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه واحدة من أهم دوال الكورس لأنها Primitive يعتمد عليها حساب الفروق وزيادة الأيام والأسابيع لاحقًا.
## 🧩 Problem #17: Difference In Days
### 📝 وصف المشكلة (Problem Description)
المطلوب حساب الفرق بالأيام بين تاريخين، مع خيار تضمين يوم النهاية.

### 💡 الفكرة البرمجية (Logic Breakdown)
نمشي من التاريخ الأصغر إلى الأكبر يومًا بيوم باستخدام IncreaseDateByOneDay ونزيد العداد. IncludeEndDay تضيف يومًا إضافيًا عند الحاجة.

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

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #17 : Write a program to read a Date1, Date2 and make a function to calculate the difference in days.\n   - Note: Date 1 should be less than Date2\n";
    cout << "\tex     : Please enter a year 1  ? 2022\n";
    cout << "\t         Please enter a month 1 ? 12\n";
    cout << "\t         Please enter a day 1   ? 10\n";
    cout << "\t       : Please enter a year 2  ? 2022\n";
    cout << "\t         Please enter a month 2 ? 12\n";
    cout << "\t         Please enter a day 2   ? 20\n";
    cout << "\toutput : The difference in days between 10/12/2022 and 20/12/2022 is 10 days.\n";
    cout << "\t       : the difference (including the end date) is 11 days.\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    sDate date2 = ReadDate("Enter Date 2:");
    int difference = GetDifferenceInDays(date1, date2);
    cout << "The difference in days between " << date1.day << "/" << date1.month << "/" << date1.year
         << " and " << date2.day << "/" << date2.month << "/" << date2.year
         << " is " << difference << " days.\n";
    cout << "the difference (including the end date) is " << GetDifferenceInDays(date1, date2, true)<< " days.\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
الحل واضح جدًا ويغطي الحالة السالبة عبر swapFlagValue. الأداء خطي بعدد الأيام، وهذا مقبول تعليميًا لكنه قد يكون مكلفًا للفترات الطويلة جدًا.
## 🧩 Problem #18: Your Age In Days
### 📝 وصف المشكلة (Problem Description)
المطلوب حساب عمر المستخدم بالأيام اعتمادًا على تاريخ ميلاده وتاريخ الجهاز الحالي.

### 💡 الفكرة البرمجية (Logic Breakdown)
نقرأ تاريخ الميلاد، ثم نحصل على تاريخ النظام عبر time و localtime، وبعدها نستخدم دالة فرق الأيام لحساب العمر.

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
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل عملي وممتاز لأنه يربط Date Utilities ببيانات حقيقية من نظام التشغيل.
## 🧩 Problem #19: Difference In Negative Days
### 📝 وصف المشكلة (Problem Description)
امتداد لمسألة فرق الأيام بحيث يمكن إرجاع فرق سالب إذا كان التاريخ الأول بعد التاريخ الثاني.

### 💡 الفكرة البرمجية (Logic Breakdown)
الدالة تفحص إذا كان date2 قبل date1، فتبدل الترتيب وتفعّل swapFlagValue، ثم تعيد النتيجة بالسالب.

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

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #17 : Write a program to read a Date1, Date2 and make a function to calculate the difference in days.\n   - Note: Date 1 should be less than Date2\n";
    cout << "\tex     : Please enter a year 1  ? 2022\n";
    cout << "\t         Please enter a month 1 ? 12\n";
    cout << "\t         Please enter a day 1   ? 10\n";
    cout << "\t       : Please enter a year 2  ? 2022\n";
    cout << "\t         Please enter a month 2 ? 12\n";
    cout << "\t         Please enter a day 2   ? 20\n";
    cout << "\toutput : The difference in days between 10/12/2022 and 20/12/2022 is 10 days.\n";
    cout << "\t       : the difference (including the end date) is 11 days.\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    sDate date2 = ReadDate("Enter Date 2:");
    int difference = GetDifferenceInDays(date1, date2);
    cout << "The difference in days between " << date1.day << "/" << date1.month << "/" << date1.year
         << " and " << date2.day << "/" << date2.month << "/" << date2.year
         << " is " << difference << " days.\n";
    cout << "the difference (including the end date) is " << GetDifferenceInDays(date1, date2, true)<< " days.\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
تصميم ذكي لأنه يحافظ على دالة واحدة بدل تكرار منطقين منفصلين للفروق الموجبة والسالبة.
## 🧩 Problems #20 To #32: Increase Date Problems
### 📝 وصف المشكلة (Problem Description)
هذه المجموعة تبني مكتبة صغيرة ومترابطة لزيادة التاريخ بعدة وحدات زمنية: يوم، عدد أيام، أسبوع، عدد أسابيع، شهر، عدد شهور، سنة، عدد سنوات، عقود، قرن، وألفية. الفكرة ليست حل مسألة واحدة فقط، بل بناء طبقة كاملة من Date Arithmetic يمكن إعادة استخدامها في أي برنامج يتعامل مع التقويم.

### 💡 الفكرة البرمجية (Logic Breakdown)
الفكرة الأساسية تبدأ من دالة واحدة موثوقة: IncreaseDateByOneDay. هذه الدالة تعرف كيف تنتقل من نهاية شهر إلى بداية الشهر التالي، ومن نهاية ديسمبر إلى بداية سنة جديدة. بعد ذلك يتم بناء بقية الدوال فوقها أو بجانبها:

• IncreaseDateByXDays تكرر زيادة يوم واحد عددًا معينًا من المرات.

• IncreaseDateByOneWeek و IncreaseDateByXWeeks يبنيان مفهوم الأسبوع فوق الأيام.

• IncreaseDateByOneMonth تتعامل مع انتقال الشهر، وتستخدم min لحماية التواريخ مثل 31/1 عند الانتقال إلى فبراير.

• دوال السنوات والعقود والقرون والألفية تستخدم إما التكرار أو القفز المباشر، ومع ذلك تظل تصحح اليوم حسب عدد أيام الشهر في السنة الجديدة.

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
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه المجموعة ممتازة لأنها توضّح مفهوم بناء API تدريجي: تبدأ من Primitive صغيرة صحيحة، ثم تبني دوال أعلى منها. وجود نسخ Faster مهم جدًا لأنه يوضح الفرق بين الحل التعليمي التكراري والحل العملي الأسرع. أهم نقطة هندسية في المجموعة كلها هي تصحيح اليوم بعد تغيير الشهر أو السنة، لأن Date Arithmetic يفشل غالبًا في حالات مثل 29 فبراير و31 من الشهر.

## 🧩 Problems #33 To #46: Decrease Date Problems
### 📝 وصف المشكلة (Problem Description)
هذه المجموعة هي النسخة العكسية من مجموعة الزيادة، وهدفها إنقاص التاريخ بوحدات مختلفة: يوم، أيام، أسبوع، أسابيع، شهر، شهور، سنة، سنوات، عقود، قرن، وألفية. قيمتها الأساسية أنها تختبر نفس منطق التقويم ولكن في الاتجاه العكسي، حيث تظهر حالات مثل الرجوع من 1/1 إلى 31/12 من السنة السابقة.

### 💡 الفكرة البرمجية (Logic Breakdown)
نقطة البداية هنا هي DecreaseDateByOneDay. إذا كان اليوم أكبر من 1، ننقصه مباشرة. أما إذا كان اليوم يساوي 1، نحتاج للرجوع إلى الشهر السابق، وإذا كان الشهر يناير نرجع إلى ديسمبر وننقص السنة.

بعد ذلك يتم بناء الدوال الأكبر بنفس النمط:

• DecreaseDateByXDays تكرر إنقاص يوم واحد.

• دوال الأسابيع تعتمد على تحويل الأسبوع إلى 7 أيام.

• DecreaseDateByOneMonth ترجع شهرًا للخلف وتصحح اليوم باستخدام min.

• دوال السنوات والعقود والقرون والألفية إما تكرر أو تقفز مباشرة، مع تصحيح اليوم بعد القفزة.

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
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه المجموعة ممتازة لتثبيت فهم Boundary Conditions. الرجوع للخلف أصعب ذهنيًا من التقدم للأمام لأنه يتطلب معرفة آخر يوم في الشهر السابق. استخدام NumberOfDaysInMonth في دالة الإنقاص يجعل الحل مرنًا مع فبراير والسنوات الكبيسة. وجود نسخ أسرع مثل DecreaseDateByXYearsFaster وDecreaseDateByXDecadesFaster يوضح نفس مبدأ تحسين الأداء بدون كسر صحة التاريخ.

## 🧩 Problems #47 To #53: More Date Helper Functions
### 📝 وصف المشكلة (Problem Description)
هذه المجموعة تضيف دوال مساعدة فوق منطق اليوم داخل الأسبوع. الهدف هنا ليس تعديل التاريخ، بل استخراج معلومات مفيدة منه: هل اليوم نهاية أسبوع؟ هل هو يوم عمل؟ كم يومًا متبقيًا لنهاية الأسبوع أو الشهر أو السنة؟ هذه دوال مهمة جدًا لأي نظام Attendance أو HR أو Scheduling.

### 💡 الفكرة البرمجية (Logic Breakdown)
كل شيء يبدأ من DayOfWeekOrder. بعد أن نعرف ترتيب اليوم داخل الأسبوع، نستطيع بناء أحكام أعلى:

• IsEndOfWeek تتحقق هل اليوم هو آخر يوم في الأسبوع.

• IsWeekEnd تعتبر الجمعة والسبت Weekend حسب ترتيب الأيام المستخدم.

• IsBusinessDay هي عكس IsWeekEnd.

• DaysUntilTheEndOfWeek تعتمد على الفرق بين ترتيب السبت وترتيب اليوم الحالي.

• DaysUntilTheEndOfMonth تستخدم عدد أيام الشهر الحالي.

• DaysUntilTheEndOfYear تستخدم ترتيب اليوم داخل السنة وعدد أيام السنة.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
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
    date.year = ReadPositiveNumberInRange("Enter a year  to check? : ", 1, 9999);
    date.month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    date.day = ReadPositiveNumberInRange("Enter a day   to check? : ", 1, NumberOfDaysInMonth(date.month, date.year));
    return date;
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

short DaysUntilTheEndOfWeek(sDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(sDate Date)
{
    return NumberOfDaysInMonth(Date.month, Date.year) - Date.day + 1; // +1 to include the current day
}

short DaysUntilTheEndOfYear(sDate Date)
{
    short totalDaysInYear = IsLeapYear(Date.year) ? 366 : 365;
    short daysPassed = NumberOfDaysFromTheBeginingOfTheYear(Date.day, Date.month, Date.year);
    return totalDaysInYear - daysPassed + 1; // +1 to include the current day
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #47 To #53 : Write a program to read a date and make functions as follows:\n";
    cout << "   - Overload the DayOfWeekOrder to take date structure\n";
    cout << "   - IsEndOfWeek\n";
    cout << "   - IsWeekEnd\n";
    cout << "   - IsBusinessDay\n";
    cout << "   - DaysUntilTheEndOfWeek\n";
    cout << "   - DaysUntilTheEndOfMonth\n";
    cout << "   - DaysUntilTheEndOfYear\n";
    cout << "\tex     : Today is Friday, 23/9/2022\n";
    cout << "\toutput : Is it End of Week ?\n";
    cout << "\t         => No Not end of week\n";
    cout << "\t         Is it Week End ?\n";
    cout << "\t         => Yes it is a Week end\n";
    cout << "\t         Is it Business Day ?\n";
    cout << "\t         => No it is Not a Business day\n";
    cout << "\t         - Days until the end of week  : 1 Day(s)\n";
    cout << "\t         - Days until the end of month : 8 Day(s)\n";
    cout << "\t         - Days until the end of year  : 100 Day(s)\n";

    cout << "\n-------------------------------------------------\n\n";

    sDate date1 = GetSystemDate();
    cout << "Today is " << DayShortName(DayOfWeekOrder(date1)) << ", " << date1.day << "/" << date1.month << "/" << date1.year << "\n\n";
    cout << "Is it End of Week ?\n";
    cout << "=> " << (IsEndOfWeek(date1) ? "Yes, it is End of week" : "No, it is Not end of week") << "\n";
    cout << "Is it Week End ?\n";
    cout << "=> " << (IsWeekEnd(date1) ? "Yes, it is a Week end" : "No, it is Not a Week end") << "\n";
    cout << "Is it Business Day ?\n";
    cout << "=> " << (IsBusinessDay(date1) ? "Yes, it is a Business day" : "No, it is Not a Business day") << "\n";
    cout << "- Days until the end of week  : " << DaysUntilTheEndOfWeek(date1) << " Day(s)\n";
    cout << "- Days until the end of month : " << DaysUntilTheEndOfMonth(date1) << " Day(s)\n";
    cout << "- Days until the end of year  : " << DaysUntilTheEndOfYear(date1) << " Day(s)\n";

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
المجموعة دي جميلة لأنها تحول دوال التقويم الأساسية إلى Business Logic قابلة للاستخدام في برامج حقيقية. الأفضل هنا أن تعريف Weekend مركزي في دالة واحدة، لأن أي تغيير في سياسة أيام العمل سيكون في مكان واحد فقط. كذلك استخدام +1 في نهاية الشهر والسنة يوضح أن الحساب شامل لليوم الحالي.

## 🧩 Problem #54: Calculate Vacation Days
### 📝 وصف المشكلة (Problem Description)
حساب أيام الإجازة الفعلية بين تاريخ بداية ونهاية مع استبعاد أيام نهاية الأسبوع.

### 💡 الفكرة البرمجية (Logic Breakdown)
نمر يومًا بيوم على الفترة، ونزيد العداد فقط إذا كان اليوم Business Day.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
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
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل صحيح وعملي، لكن فيه ملاحظة في ReadDate داخل الملف: قراءة اليوم قبل الشهر والسنة قد تجعل Validation اليوم يعتمد على قيم غير مهيأة.
## 🧩 Problem #55: Calculate Vacation Return Date
### 📝 وصف المشكلة (Problem Description)
حساب تاريخ الرجوع من الإجازة بناءً على تاريخ البداية وعدد أيام الإجازة الفعلية.

### 💡 الفكرة البرمجية (Logic Breakdown)
نستهلك أيام الإجازة فقط في أيام العمل، وبعد انتهاء العدد نتخطى أي Weekend حتى نصل ليوم عمل.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
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
    date.year = ReadPositiveNumberInRange("Enter a year  to check? : ", 1, 9999);
    date.month = ReadPositiveNumberInRange("Enter a month to check? : ", 1, 12);
    date.day = ReadPositiveNumberInRange("Enter a day   to check? : ", 1, NumberOfDaysInMonth(date.month, date.year));
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

sDate CalculateVacationReturnDate(sDate vacationStart, int vacationDays)
{
    while (vacationDays > 0)
    {
        if (IsBusinessDay(vacationStart))
        {
            vacationDays--;
        }
        vacationStart = IncreaseDateByOneDay(vacationStart);
    }

    while (IsWeekEnd(vacationStart))
    {
        vacationStart = IncreaseDateByOneDay(vacationStart);
    }
    return vacationStart;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #55 : Write a program to read Vacation Start DateFrom and make a function to calculate the vacation return Date.\n";
    cout << "            - Note: Weekends are excluded.";
    cout << "\tex     : Vacation Starts:\n";
    cout << "\t           - Please enter a Day? 1\n";
    cout << "\t           - Please enter a Month? 1\n";
    cout << "\t           - Please enter a Year? 2022\n";
    cout << "\t         Please enter a Vacation days? 23\n";
    cout << "\toutput : Return Date: Wednesday, 2/2/2022\n";

    cout << "\n-------------------------------------------------\n\n";
    sDate vacationStart = ReadDate("Vacation Starts:");
    int vacationDays = ReadPositiveNumberInRange("Please enter a Vacation days? ", 1, 365);
    sDate returnDate = CalculateVacationReturnDate(vacationStart, vacationDays);
    cout << "Return Date: " << DayShortName(DayOfWeekOrder(returnDate)) << ", " << returnDate.day << "/" << returnDate.month << "/" << returnDate.year;
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
منطق ممتاز لأن تاريخ العودة لا ينبغي أن يكون يوم عطلة.
## 🧩 Problem #56: Is Date1 After Date2
### 📝 وصف المشكلة (Problem Description)
التحقق هل التاريخ الأول يأتي بعد التاريخ الثاني.

### 💡 الفكرة البرمجية (Logic Breakdown)
بدل كتابة مقارنة جديدة، نستخدم نفي حالتي Before وEquals.

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


int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #56 :Write a program to read date1, date2 and check if Date 1 after Date 2 or not\n";
    cout << "\tex     : Please enter a year 1  ? 2022\n";
    cout << "\t         Please enter a month 1 ? 10\n";
    cout << "\t         Please enter a day 1   ? 10\n";
    cout << "\t       : Please enter a year 2  ? 2022\n";
    cout << "\t         Please enter a month 2 ? 4\n";
    cout << "\t         Please enter a day 2   ? 10\n";
    cout << "\toutput : Yes, Date 1 is After Date 2";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    sDate date2 = ReadDate("Enter Date 2:");
    if (IsDate1AfterDate2(date1, date2))
    {
        cout << "Yes, Date 1 is After Date 2";
    }
    else
    {
        cout << "No, Date 1 is not After Date 2";
    }

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
تصميم نظيف جدًا ويقلل تكرار منطق المقارنة.
## 🧩 Problem #57: Compare Date Function
### 📝 وصف المشكلة (Problem Description)
بناء دالة مقارنة موحدة تعيد Before أو Equal أو After.

### 💡 الفكرة البرمجية (Logic Breakdown)
نستخدم enum واضحًا، ثم نعتمد على دوال المقارنة السابقة لإرجاع الحالة المناسبة.

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

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #57 :Write a program to read Date1 & Date2, and write a function to compare dates, it shoud return:\n";
    cout << "\t\t-1 if Date1 is Before Date2\n";
    cout << "\t\t 0 if Date1 is Equal Date2\n";
    cout << "\t\t 1 if Date1 is After Date2\n";
    cout << "\tex     : Enter Date 1:\n";
    cout << "\t\t\tEnter a year  to check? : 2020\n";
    cout << "\t\t\tEnter a month to check? : 2\n";
    cout << "\t\t\tEnter a day   to check? : 29\n";
    cout << "\t       : Enter Date 2:\n";
    cout << "\t\t\tEnter a year  to check? : 2021\n";
    cout << "\t\t\tEnter a month to check? : 1\n";
    cout << "\t\t\tEnter a day   to check? : 1\n";
    cout << "\toutput : Compare Result: -1 (Date 1 is Before Date 2)\n";
    cout << "\n\n-------------------------------------------------\n";
    sDate date1 = ReadDate("Enter Date 1:");
    sDate date2 = ReadDate("Enter Date 2:");
    short compareResult = CompareDates(date1, date2);
    cout << "\nCompare Result: " << compareResult << " (Date 1 is " << (compareResult == -1 ? "Before" : (compareResult == 0 ? "Equal" : "After")) << " Date 2)\n"  ;

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه الدالة تجعل بقية مسائل الفترات أكثر وضوحًا وأقل عرضة للأخطاء.
## 🧩 Problem #58: Is Overlap Periods
### 📝 وصف المشكلة (Problem Description)
فحص هل فترتان زمنيتان تتداخلان.

### 💡 الفكرة البرمجية (Logic Breakdown)
إذا انتهت الفترة الثانية قبل بداية الأولى أو بدأت بعد نهاية الأولى فلا يوجد تداخل، وإلا فهناك تداخل.

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

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) ==
            enDateCompare::Before ||
        CompareDates(Period2.StartDate, Period1.EndDate) ==
            enDateCompare::After)
        return false;
    else
        return true;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #58 :Write a program to read Two Periods and check if they overlap or not.\n\n";
    cout << "\tex     : Enter Period 1:\n";
    cout << "\t       : Enter Date 1:\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 2\n";
    cout << "\t\t\tEnter a day   to check? : 1\n";
    cout << "\t       : Enter Date 2:\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 2\n";
    cout << "\t\t\tEnter a day   to check? : 10\n";
    cout << "\t       : Enter Period 2:\n";
    cout << "\t       : Enter Date 1:\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 2\n";
    cout << "\t\t\tEnter a day   to check? : 5\n";
    cout << "\t       : Enter Date 2:\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 2\n";
    cout << "\t\t\tEnter a day   to check? : 15\n";
    cout << "\toutput  : Yes, the periods overlap.\n\n";
    cout << "\n\n-------------------------------------------------\n";
    stPeriod Period1, Period2;
    cout << "Enter Period 1:\n";
    Period1.StartDate = ReadDate("Enter Date 1:");
    Period1.EndDate = ReadDate("Enter Date 2:");
    cout << "Enter Period 2:\n";
    Period2.StartDate = ReadDate("Enter Date 1:");
    Period2.EndDate = ReadDate("Enter Date 2:");
    if (IsOverlapPeriods(Period1, Period2))
        cout << "Yes, the periods overlap.\n";
    else
        cout << "No, the periods do not overlap.\n";    
        
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
شرط قياسي مهم جدًا في أي نظام حجوزات أو إجازات أو مواعيد.
## 🧩 Problem #59: Period Length In Days
### 📝 وصف المشكلة (Problem Description)
حساب طول فترة بالأيام مع خيار تضمين تاريخ النهاية.

### 💡 الفكرة البرمجية (Logic Breakdown)
نعيد استخدام GetDifferenceInDays بين StartDate و EndDate، ونمرر IncludeEndDate عند الحاجة.

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
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
مثال جيد على أن بناء دوال صغيرة يختصر مسائل كاملة لاحقًا.
## 🧩 Problem #60: Is Date Within Period
### 📝 وصف المشكلة (Problem Description)
فحص هل تاريخ معيّن يقع داخل فترة محددة.

### 💡 الفكرة البرمجية (Logic Breakdown)
التاريخ داخل الفترة إذا لم يكن قبل البداية ولم يكن بعد النهاية.

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
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
حل مختصر وقوي، ويستخدم في مسائل عدّ التداخل لاحقًا.

## 🧩 Problem #61: Count Overlap Days
### 📝 وصف المشكلة (Problem Description)
عدّ عدد الأيام المشتركة فعليًا بين فترتين زمنيتين.

### 💡 الفكرة البرمجية (Logic Breakdown)
نتأكد أولًا أن الفترتين تتداخلان، ثم نمشي على الفترة الأقصر يومًا بيوم ونعد الأيام التي تقع داخل الفترة الأخرى.

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

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) ==
            enDateCompare::Before ||
        CompareDates(Period2.StartDate, Period1.EndDate) ==
            enDateCompare::After)
        return false;
    else
        return true;
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

bool isDateInPeriod(sDate date, stPeriod period)
{
    return !(IsDate1BeforeDate2(date, period.StartDate) || IsDate1AfterDate2(date, period.EndDate));
}

int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    int Period1Length = PeriodLengthInDays(Period1, true);
    int Period2Length = PeriodLengthInDays(Period2, true);
    int OverlapDays = 0;
    if (!IsOverlapPeriods(Period1, Period2))
        return 0;
    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate,
                                Period1.EndDate))
        {
            if (isDateInPeriod(Period1.StartDate, Period2))
                OverlapDays++;
            Period1.StartDate =
                IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate,
                                Period2.EndDate))
        {
            if (isDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++;
            Period2.StartDate =
                IncreaseDateByOneDay(Period2.StartDate);
        }
    }
    return OverlapDays;
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #61 :Write a program to read a tow periods then count overlap days?\n\n";
    cout << "\tex     : Enter Period 1:\n";
    cout << "\t       : Enter Date 1:\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 1\n";
    cout << "\t\t\tEnter a day   to check? : 1\n";
    cout << "\t       : Enter Date 2:\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 1\n";
    cout << "\t\t\tEnter a day   to check? : 10\n";
    cout << "\t       : Enter Period 2:\n";
    cout << "\t       : Enter Date 1:\n";
    cout << "\t\t\tEnter a year  to check? : 2022\n";
    cout << "\t\t\tEnter a month to check? : 1\n";
    cout << "\t\t\tEnter a day   to check? : 5\n";
    cout << "\t       : Enter Date 2:\n";
    cout << "\t\t\tEnter a year  to check? : 2050\n";
    cout << "\t\t\tEnter a month to check? : 12\n";
    cout << "\t\t\tEnter a day   to check? : 30\n";
    cout << "\toutput  : Overlap Days Count = 5";
    cout << "\n\n-------------------------------------------------\n\n";
    stPeriod Period1, Period2;
    cout << "Enter Period 1:\n";
    Period1.StartDate = ReadDate("Enter Date 1:");
    Period1.EndDate = ReadDate("Enter Date 2:");
    cout << "Enter Period 2:\n";
    Period2.StartDate = ReadDate("Enter Date 1:");
    Period2.EndDate = ReadDate("Enter Date 2:");
    cout << "Overlap Days Count = " << CountOverlapDays(Period1, Period2) << "\n";
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
اختيار الفترة الأقصر يقلل عدد التكرارات، وهذه لمسة أداء جيدة.
## 🧩 Problem #62: Validate Date
### 📝 وصف المشكلة (Problem Description)
التحقق من صلاحية تاريخ حتى إذا دخل المستخدم اليوم والشهر والسنة بدون قيود مسبقة.

### 💡 الفكرة البرمجية (Logic Breakdown)
نرفض اليوم خارج 1..31، ونرفض الشهر خارج 1..12، ثم نتحقق أن اليوم لا يتجاوز أيام الشهر الفعلية.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumberInRange(string message, int From = INT_MIN, int To = INT_MAX)
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
    date.year = ReadPositiveNumberInRange("Enter a year : ", 1, 9999);
    date.month = ReadPositiveNumberInRange("Enter a month: ", 1, 12);
    date.day = ReadPositiveNumberInRange("Enter a day  : ", 1, NumberOfDaysInMonth(date.month, date.year));
    return date;
}

bool IsValidDate(sDate date)
{
    if (date.day < 1 || date.day > 31)
    {
        return false;
    }

    if (date.month < 1 || date.month > 12)
    {
        return false;
    }

    if (date.day < 1 || date.day > NumberOfDaysInMonth(date.month, date.year))
    {
        return false;
    }

    return true;
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #62 :Write a program to read Date and write a function to validate this date\n\n";
    cout << "\tex     : Enter Date:\n";
    cout << "\t\t\tEnter a year : 2022\n";
    cout << "\t\t\tEnter a month: 1\n";
    cout << "\t\t\tEnter a day  : 1\n";
    cout << "\toutput : Yes, this Date is valid.\n";
    cout << "\tex     : Enter Date:\n";
    cout << "\t\t\tEnter a year : 2022\n";
    cout << "\t\t\tEnter a month: 2\n";
    cout << "\t\t\tEnter a day  : 31\n";
    cout << "\toutput : No, this Date is not valid.\n";
    cout << "\n\n-------------------------------------------------\n\n";
    sDate date;
    date.day = ReadPositiveNumberInRange("Enter a day  : ");
    date.month = ReadPositiveNumberInRange("Enter a month: ");
    date.year = ReadPositiveNumberInRange("Enter a year : ");
    if (IsValidDate(date))
    {
        cout << "\nYes, this Date is valid.\n";
    }
    else
    {
        cout << "\nNo, this Date is not valid.\n";
    }
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
مهم جدًا قبل أي Parsing أو عمليات تاريخ. ملاحظة: استخدام INT_MIN/INT_MAX يحتاج تضمين <climits> لضمان الاعتمادية.
## 🧩 Problems #63 & #64: Read And Print Date String
### 📝 وصف المشكلة (Problem Description)
هذه المجموعة تتعامل مع تحويل التاريخ بين شكلين مهمين: نص يكتبه المستخدم بصيغة dd/mm/yyyy، وStruct من نوع sDate يحتوي اليوم والشهر والسنة كقيم رقمية. بعد التحويل إلى Struct، يتم طباعة الأجزاء منفصلة، ثم إعادة تحويل الـStruct إلى String مرة أخرى.

### 💡 الفكرة البرمجية (Logic Breakdown)
الفكرة تمر بثلاث مراحل واضحة:

• قراءة التاريخ كنص كامل من المستخدم باستخدام getline.

• تقطيع النص باستخدام SplitString على الفاصل / للحصول على اليوم والشهر والسنة.

• تحويل الأجزاء النصية إلى أرقام باستخدام stoi وتخزينها داخل sDate.

بعد ذلك يتم تنفيذ الاتجاه العكسي عبر DateToString، حيث يتم تركيب اليوم والشهر والسنة في String واحد بنفس صيغة الإدخال تقريبًا.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string ReadString(string Message)
{
    string sInput;
    cout << Message;
    getline(cin >> ws, sInput);
    return sInput;
}

struct sDate
{
    short Year;
    short Month;
    short Day;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
        return vString;
    }
}
string DateToString(sDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) +
           "/" + to_string(Date.Year);
}
sDate StringToDate(string DateString)
{
    sDate Date;
    vector<string> vDate;
    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}
string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #63 & #64 :Write a program to\n\n";
    cout << "\t1- Read Date String.\n";
    cout << "\t2- Convert it to date structure.\n";
    cout << "\t3- Print Day, Month, Year separately.\n";
    cout << "\t4- Then convert Date Structure to string and print it on the screen.";
    cout << "\tex     : Please Enter Date dd/mm/yyyy? 31/3/2022\n";
    cout << "\toutput : Day: 31\n";
    cout << "\t\t\tMonth: 3\n";
    cout << "\t\t\tYear: 2022\n";
    cout << "\t\t\tDate: 31/3/2022\n";
    cout << "\n\n-------------------------------------------------\n\n";

    string dateString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");
    sDate date = StringToDate(dateString);
    cout << "\nDay: " << date.Day;
    cout << "\nMonth: " << date.Month;  
    cout << "\nYear: " << date.Year;
    cout << "\nDate: " << DateToString(date);

    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
هذه المجموعة مهمة جدًا لأنها تنقلنا من الحسابات الرقمية للتاريخ إلى التعامل مع إدخال المستخدم الحقيقي. وجود StringToDate وDateToString معًا يجعل عندنا Conversion Layer واضحة. توجد ملاحظة هندسية صغيرة: SplitString لا ترجع قيمة في حالة كانت السلسلة النهائية فارغة، والأفضل لاحقًا ضمان 
eturn vString في نهاية الدالة دائمًا.

## 🧩 Problem #65: Format Date
### 📝 وصف المشكلة (Problem Description)
قراءة تاريخ ثم طباعته بأي Format يطلبه المستخدم مثل yyyy/dd-mm أو dd-mm-yyyy.

### 💡 الفكرة البرمجية (Logic Breakdown)
نستبدل الرموز dd و mm و yyyy بالقيم الفعلية باستخدام ReplaceWordInString بشكل متتابع.

### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string ReadString(string Message)
{
    string sInput;
    cout << Message;
    getline(cin >> ws, sInput);
    return sInput;
}

struct sDate
{
    short Year;
    short Month;
    short Day;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
        return vString;
    }
}
string DateToString(sDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) +
           "/" + to_string(Date.Year);
}
sDate StringToDate(string DateString)
{
    sDate Date;
    vector<string> vDate;
    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}
string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
                        sRepalceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return FormattedDateString;
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #65 :Write a program to read Date and write a function to format that date.\n\n";
    cout << "\tex     : Please Enter Date dd/mm/yyyy? 31/3/2022\n";
    cout << "\t       : Please Enter New Format? yyyy/dd-mm\n";
    cout << "\toutput : 2022/31-3\n";
    cout << "\t       : Day: 31, Month: 3, Year: 2022\n";
    cout << "\n\n-------------------------------------------------\n\n";

    string dateString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");
    string formatString = ReadString("Please Enter New Format? ");
    sDate date = StringToDate(dateString);
    string FormattedDate = FormateDate(date, formatString);
    cout << "Formatted Date: " << FormattedDate;
    cout << "\nDay: " << date.Day << ", Month: " << date.Month << ", Year: " << date.Year;
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)
فكرة ممتازة وقابلة للتوسيع، لكن اسم FormateDate فيه typo بسيط والأفضل لاحقًا FormatDate.

</div>




