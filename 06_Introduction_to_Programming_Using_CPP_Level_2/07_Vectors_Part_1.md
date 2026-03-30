<div dir="rtl">

# الفصل السابع: المتجهات - الجزء الأول (Vectors Part I)

## 🚀 الدرس الثامن والعشرون: مقدمة عن المتجهات، تعريفها، وتهيئتها (Introduction, Declaration and Initialization)

### 1. ما هي مشكلة المصفوفات العادية (Arrays)؟

عندما كنا نتعامل مع المصفوفات العادية int arr[100];، كان يجب علينا تحديد حجمها مسبقاً قبل تشغيل البرنامج. المشكلة هنا تكمن في الذاكرة:

إذا استخدمنا 5 عناصر فقط من أصل 100، فهناك 95 مكاناً محجوزاً في الذاكرة بلا فائدة (هدر للذاكرة).

إذا احتجنا إدخال 101 عنصر، سيتعطل البرنامج لعدم وجود مساحة كافية.

### 2. الحل السحري: المتجهات (Vectors - Dynamic Arrays)

في لغة C++، الـ Vector هو ببساطة عبارة عن "مصفوفة ديناميكية".

ينمو ويصغر حجمه تلقائياً أثناء تشغيل البرنامج (Runtime) كلما أضفت أو حذفت عناصر منه.

لا يحتاج لتحديد حجمه مسبقاً (إلا إذا أردت ذلك).

يمكن أن يحمل أي نوع من البيانات (int, float, double, bool أو حتى struct).

### 3. طريقة التعريف والتهيئة (Declaration & Initialization):

لتعريف فيكتور، نكتب الكلمة المحجوزة vector متبوعة بنوع البيانات بين أقواس الزاوية < > ثم اسم الفيكتور.
(ملاحظة تنظيمية: يُفضل دائماً المهندس أبو هدهود بدء اسم الفيكتور بحرف v صغير لتمييزه في الكود).

<div dir="ltr">

```CPP
#include <iostream>
#include <vector> // يجب تضمين مكتبة الفيكتور أولاً
using namespace std;

int main()
{
// تعريف فيكتور بدون قيم ابتدائية (حجمه الآن = صفر)
vector<int> vNumbersEmpty;

    // تعريف فيكتور مع إعطائه قيم ابتدائية (حجمه الآن = 5)
    vector<int> vNumbers = {10, 20, 30, 40, 50};

    return 0;

}
```

</div>

### 4. المرور على عناصر الفيكتور (التريكة الهندسية للسرعة):

أفضل طريقة لطباعة أو المرور على عناصر الفيكتور هي باستخدام حلقة التكرار المخصصة للمجموعات Ranged Loop (التي درسناها في الدرس 10). ولكن هناك فرق شاسع في الأداء بين طريقتين لكتابتها:

أ. الطريقة البطيئة (Pass by Value):
إذا كتبنا for(int Number : vNumbers)، سيقوم الكومبايلر بإنشاء متغير جديد في الذاكرة، ثم يأخذ نسخة (Copy) من العنصر الأول ويضعه فيه، ثم يطبعه، وهكذا. عملية "النسخ" هذه تأخذ وقتاً وذاكرة، وتصبح كارثية إذا كان الفيكتور يحتوي على Structs ضخمة (مثلاً بيانات طلاب بحجم 10 ميجابايت لكل طالب!).

ب. الطريقة الاحترافية والسريعة (Pass by Reference):
بإضافة علامة الـ Reference & هكذا for(int &Number : vNumbers)، أنت تخبر الكومبايلر: "لا تقم بإنشاء نسخ جديدة! اذهب مباشرة إلى عنوان العنصر الأصلي في الذاكرة واطبعه". هذا يجعل الكود الخاص بك أسرع بشكل ملحوظ ويوفر استهلاك الذاكرة.

<div dir="ltr">

```CPP
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vNumbers = {10, 20, 30, 40, 50};

    // الطريقة البطيئة (نسخ القيم - للمبتدئين)
    /*
    for (int Number : vNumbers)
    {
        cout << Number << endl;
    }
    */

    // الطريقة السريعة والاحترافية (عن طريق المرجع - للمحترفين)
    for (int &Number : vNumbers)
    {
        cout << Number << endl;
    }

    return 0;
}
```

</div>

## ➕ الدرس التاسع والعشرون: إضافة عناصر للمتجه (Add Elements - push_back)

بعد أن عرفنا الفيكتور، كيف يمكننا إضافة عناصر جديدة إليه أثناء تشغيل البرنامج (Runtime)؟
نستخدم دالة مدمجة مع الفيكتور تسمى push_back().

1. كيف يعمل الفيكتور في الذاكرة؟ (مفهوم الـ Stack)

الفيكتور يستخدم بنية بيانات (Data Structure) تسمى المكدس (Stack).
تخيل الـ Stack كأنه "خزان ماء" أو "علبة أقراص مدمجة (CDs)":

(LIFO - Last In, First Out): آخر عنصر يدخل هو أول عنصر يخرج.

عندما تستخدم push_back(10)، أنت تضع الرقم 10 في قاع الخزان.

إذا استخدمت push_back(20) بعدها، سيتم وضع الرقم 20 فوق الرقم 10.

وإذا استخدمت أداة الحذف المدمجة pop_back() (سندرسها لاحقاً)، ستقوم بحذف آخر عنصر تم إضافته (وهو 20 في هذه الحالة) وليس العنصر الأول.

💻 الكود الأساسي للإضافة:

<div dir="ltr">

```CPP
#include <iostream>
#include <vector>
using namespace std;

int main()
{
// 1. تعريف فيكتور فارغ
vector<int> vNumbers;

    // 2. إضافة العناصر ديناميكياً
    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    // 3. طباعة العناصر (باستخدام المرجع & للسرعة)
    for (int &Number : vNumbers)
    {
        cout << Number << " ";
    }
    // المخرجات ستكون: 10 20 30 40 50

    return 0;

}
```

</div>

2. تمرير المتجهات للدوال (Passing Vectors to Functions) - 🚨 تريكة هندسية خطيرة!

عندما تريد إنشاء دالة خارجية لتقوم بملء الفيكتور أو طباعته، يجب أن تنتبه لقاعدة ذهبية:
المصفوفات العادية (Arrays) تُرسل تلقائياً للدوال عن طريق المرجع (By Reference)، ولكن المتجهات (Vectors) لا تُرسل تلقائياً بالمرجع!

إذا أرسلت الفيكتور لدالة بدون علامة &، سيقوم الكومبايلر بعمل نسخة كاملة (Copy) من الفيكتور داخل الدالة.

إذا قمت بالتعديل على هذه النسخة (بإضافة عناصر)، لن يتأثر الفيكتور الأصلي الموجود في الـ main وسيظل فارغاً!

حتى لو كانت الدالة لغرض الطباعة فقط (لا تعدل شيئاً)، فمن الكارثي هندسياً أن تقوم بنسخ فيكتور قد يكون حجمه 2 جيجابايت فقط لتقرأه! استخدم دائماً & لتعطي الدالة "مفتاح/عنوان" الفيكتور الأصلي ليقرأ منه مباشرة.

💻 تطبيق عملي (قراءة الأرقام من المستخدم ديناميكياً):

هذا البرنامج يسأل المستخدم باستمرار عن أرقام لإضافتها للفيكتور حتى يكتب "No".

<div dir="ltr">

```CPP
#include <iostream>
#include <vector>
using namespace std;

// دالة للقراءة: لاحظ وضع الـ & لتعديل الفيكتور الأصلي مباشرة
void ReadNumbers(vector<int> &vNumbers)
{
char ReadMore = 'Y';
int Number;

    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        cout << "Please enter a number: ";
        cin >> Number;

        // إضافة الرقم للفيكتور الأصلي
        vNumbers.push_back(Number);

        cout << "Do you want to add more numbers? (Y/N): ";
        cin >> ReadMore;
    }

}

// دالة للطباعة: لاحظ وضع الـ & لسرعة الأداء وتجنب نسخ الفيكتور (حتى لو لم نعدل عليه)
void PrintVectorNumbers(vector<int> &vNumbers)
{
cout << "\nNumbers in Vector: \n";
for (int &Number : vNumbers)
{
cout << Number << endl;
}
}

int main()
{
vector<int> vNumbers; // فيكتور فارغ

    ReadNumbers(vNumbers); // تمرير الفيكتور لملئه
    PrintVectorNumbers(vNumbers); // تمرير الفيكتور لطباعته

    return 0;

}
```

</div>

## 🏗️ الدرس الثلاثون: متجه الهياكل (Vector of Structure)

الآن وقد فهمنا المتجهات جيداً، حان الوقت لرفع مستوى البرمجة لدينا. المتجه لا يقتصر على تخزين الأرقام (int أو double) فحسب، بل يمكنه تخزين أي نوع من البيانات، بما في ذلك الهياكل المخصصة (Structures).

تخيل أنك تريد بناء نظام لإدارة بيانات الموظفين (الاسم الأول، الاسم الأخير، الراتب). بدلاً من إنشاء 3 متجهات منفصلة، نقوم بإنشاء Struct يمثل الموظف، ثم ننشئ Vector ليخزن قائمة بهؤلاء الموظفين ديناميكياً.

1. خطوات التنفيذ:

تعريف الـ Struct الخاص بالموظف.

تعريف الفيكتور بنوع هذا الـ Struct: vector<stEmployee> vEmployees;

لملء الفيكتور، نقوم بإنشاء متغير "مؤقت" (Temp Variable) من نوع الموظف، نملأ بياناته، ثم نرفعه (push_back) إلى الفيكتور.

💻 تطبيق عملي (برنامج إدارة الموظفين):

<div dir="ltr">

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1. تعريف الهيكل (Structure)
struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;
};

// 2. دالة لإضافة الموظفين ديناميكياً (ممررة بالمرجع &)
void ReadEmployees(vector<stEmployee> &vEmployees)
{
    char ReadMore = 'Y';
    stEmployee TempEmployee; // متغير مؤقت لتخزين بيانات الموظف الواحد

    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        cout << "Enter First Name: ";
        cin >> TempEmployee.FirstName;

        cout << "Enter Last Name: ";
        cin >> TempEmployee.LastName;

        cout << "Enter Salary: ";
        cin >> TempEmployee.Salary;

        // إضافة الموظف "المؤقت" بكامل تفاصيله إلى الفيكتور الرئيسي
        vEmployees.push_back(TempEmployee);

        cout << "\nDo you want to add more employees? (Y/N): ";
        cin >> ReadMore;
        cout << endl;
    }
}

// 3. دالة للطباعة (ممررة بالمرجع &)
void PrintEmployees(vector<stEmployee> &vEmployees)
{
    cout << "\n--- Employees List ---\n";

    // استخدام الرينج لوب، ويجب وضع & لتجنب النسخ البطيء!
    for (stEmployee &Employee : vEmployees)
    {
        cout << "Name: " << Employee.FirstName << " " << Employee.LastName << "\n";
        cout << "Salary: " << Employee.Salary << "\n\n";
    }
}

int main()
{
    // تعريف فيكتور من نوع الهيكل (Struct)
    vector<stEmployee> vEmployees;

    ReadEmployees(vEmployees);
    PrintEmployees(vEmployees);

    return 0;
}

```

</div>

💡 القاعدة الذهبية من المهندس (1 طن مقابل 1 جرام):
أثناء طباعة الفيكتور باستخدام حلقة for (stEmployee &Employee : vEmployees)، لماذا يُعتبر وضع علامة & أمراً مصيرياً حتى لو لم نكن ننوي تعديل البيانات؟

بدون & (Pass by Value): سيقوم الكومبايلر بنسخ سجل الموظف بالكامل (والذي قد يكون ضخماً جداً - نرمز له بوزن 1 طن) ويضعه في متغير جديد لطباعته، وسيكرر هذا لكل موظف، مما يقتل أداء البرنامج!

مع & (Pass by Reference): الكومبايلر لا ينسخ شيئاً، بل يأخذ "عنوان الموظف" في الذاكرة (والذي نرمز له بوزن 1 جرام)، ويقرأ منه مباشرة. (تعامل دائماً مع العناوين لسرعة فائقة!).

## 🗑️ الدرس الحادي والثلاثون: حذف عناصر من المتجه (Remove Elements)

لقد تعلمنا كيف نضيف العناصر إلى المتجه باستخدام push_back(). الآن سنتعلم كيف نحذف هذه العناصر.
بما أن الـ Vector مبني على فكرة الـ (Stack - المكدس)، فإن عملية الإزالة تتبع نفس القاعدة: (LIFO - آخر من يدخل هو أول من يخرج).

1. دالة الحذف pop_back():

هذه الدالة تقوم بحذف العنصر الأخير فقط من المتجه (آخر عنصر قمت بإضافته).
تخيل أنك أضفت 10 ثم 20 ثم 30. عند استدعاء pop_back()، سيتم حذف 30. وإذا استدعيتها مرة أخرى، سيتم حذف 20، وهكذا.

2. خطر الانهيار (Crash) وأدوات الحماية:

ماذا يحدث لو قمت باستدعاء pop_back() على متجه فارغ تماماً؟
سيغضب الكومبايلر وينهار البرنامج (Crash) لأنه يحاول حذف شيء غير موجود! لتجنب ذلك، يوفر لنا الـ Vector أداتين للحماية:

empty(): دالة ترجع true إذا كان المتجه فارغاً، و false إذا كان يحتوي على عناصر.

size(): دالة ترجع عدد العناصر الحالية داخل المتجه (يجب أن يكون الحجم أكبر من 0 لنتمكن من الحذف).

3. مسح المتجه بالكامل clear():

بدلاً من عمل حلقة تكرار لحذف العناصر واحداً تلو الآخر، توفر C++ دالة clear() التي تقوم بتفريغ المتجه بالكامل بضربة واحدة.

💻 تطبيق عملي على جميع الدوال:

<div dir="ltr">

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vNumbers;

    // إضافة 5 عناصر
    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    // طباعة الحجم الحالي (النتيجة: 5)
    cout << "Size before pop: " << vNumbers.size() << endl;

    // حذف آخر عنصر (سيتم حذف 50)
    if (!vNumbers.empty()) // حماية: تأكد أن المتجه ليس فارغاً أولاً
    {
        vNumbers.pop_back();
    }

    // طباعة الحجم بعد الحذف (النتيجة: 4)
    cout << "Size after pop: " << vNumbers.size() << endl;

    // مسح المتجه بالكامل دفعة واحدة
    vNumbers.clear();

    // طباعة الحجم بعد المسح (النتيجة: 0)
    cout << "Size after clear: " << vNumbers.size() << endl;

    return 0;
}
```

</div>

## 🛠️ الدرس الثاني والثلاثون: دوال المتجهات الجاهزة (Vector Functions)

في هذا الدرس، سنتعرف على مجموعة من الدوال الجاهزة (Built-in Functions) والمفيدة جداً للتعامل مع المتجهات (Vectors) بخلاف الإضافة والحذف اللذين درسناهما.

1. أهم الدوال المدمجة:

front(): تُرجع العنصر الأول في المتجه (أول رقم دخل للـ Stack).

back(): تُرجع العنصر الأخير في المتجه (أخر رقم تم عمل push_back له).

size(): تُرجع عدد العناصر الحالية الموجودة فعلياً داخل المتجه.

capacity(): تُرجع السعة الإجمالية (المساحة المحجوزة) للمتجه في الذاكرة (وهي غالباً تختلف عن الحجم وتكون مساوية له أو أكبر منه لتتسع لإضافات مستقبلية).

empty(): تُرجع 1 (True) إذا كان المتجه فارغاً، و 0 (False) إذا كان يحتوي على عناصر.

2. الخطر الصامت (Exception / Crash):

ماذا يحدث لو قمت بتفريغ المتجه باستخدام clear() ثم حاولت طباعة أول عنصر باستخدام front() أو آخر عنصر بـ back()؟
البرنامج سينهار فوراً ويُصدر خطأ استثنائي (Exception أو Crash) لأنك تطلب عنصراً من مكان فارغ!

💡 نصيحة هندسية من المهندس أبو هدهود: دائماً قبل استخدام front() أو back()، تأكد أن المتجه ليس فارغاً باستخدام if (!vNumbers.empty()) أو if (vNumbers.size() > 0) لتحمي برنامجك من الانهيار المفاجئ.

💻 تطبيق عملي بالكود:

<div dir="ltr">

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vNumbers;

    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    // طباعة معلومات المتجه
    cout << "First Element: " << vNumbers.front() << endl; // النتيجة: 10
    cout << "Last Element: " << vNumbers.back() << endl;   // النتيجة: 50
    cout << "Size: " << vNumbers.size() << endl;           // النتيجة: 5
    cout << "Capacity: " << vNumbers.capacity() << endl;   // النتيجة: 6 (تختلف حسب حجز الكومبايلر للذاكرة)
    cout << "Is Empty? " << vNumbers.empty() << endl;      // النتيجة: 0 (False)

    // تفريغ المتجه بالكامل
    vNumbers.clear();

    // حماية الكود من الانهيار قبل استخدام front أو back
    if (!vNumbers.empty())
    {
        cout << "First Element after clear: " << vNumbers.front() << endl;
    }
    else
    {
        cout << "\nThe vector is empty now! Cannot access front or back elements." << endl;
        cout << "Is Empty? " << vNumbers.empty() << endl; // النتيجة: 1 (True)
    }

    return 0;
}
```

</div>

</div>
