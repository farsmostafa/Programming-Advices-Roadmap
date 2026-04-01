<div dir="rtl">

# الفصل الرابع عشر: التعامل مع الملفات (Files)

## 📝 الدرس الثاني والخمسون: الكتابة على الملفات (Write Mode: Write Data To File)

في هذا الفصل، سننتقل إلى مستوى متقدم جداً وهو حفظ الـ Data الخاصة ببرنامجك بشكل دائم على الـ Hard Disk باستخدام الـ Files (الملفات)، بدلاً من الاعتماد على الـ RAM التي تفقد بياناتها بمجرد إغلاق البرنامج.

للبدء في التعامل مع الـ Files (سواء لإنشاء، كتابة، أو قراءة ملف)، نحتاج إلى استخدام Library مخصصة في C++ تُسمى <fstream> (اختصاراً لـ File Stream).

### 1. كيف تفتح وتكتب في File؟ (الخطوات الأساسية):

لكتابة بيانات داخل File، نتبع 4 خطوات رئيسية:

التعريف (Declaration): تعريف Variable من نوع fstream ليمثل الـ File داخل الكود.

الفتح (Opening): نستخدم الدالة .open() ونعطيها اسم الـ File والـ Mode (وضع الفتح). في هذا الدرس سنستخدم Write Mode عن طريق كتابة ios::out.

التأكد والكتابة (Check & Write): نتأكد أولاً أن الـ File تم فتحه بنجاح باستخدام دالة .is_open()، ثم نكتب بداخله باستخدام نفس طريقة cout بالضبط، ولكن باستخدام اسم الـ Variable الخاص بالـ File.

الإغلاق (Closing): 🚨 خطوة إجبارية! بمجرد الانتهاء، يجب إغلاق الـ File باستخدام .close() لتحريره والسماح للبرامج الأخرى أو لنظام التشغيل بالتعامل معه.

### 2. ما هو الـ Write Mode (ios::out)؟

عند فتح File باستخدام الـ Write Mode، يقوم الـ Compiler بالتالي:

إذا كان الـ File غير موجود، سيقوم بإنشائه (Creation) من الصفر.

إذا كان الـ File موجوداً بالفعل وبه بيانات قديمة، سيقوم بمسح وتصفير كل محتوياته (Overwrite)، ثم يكتب الـ Data الجديدة!

💻 تطبيق عملي بالكود:

<div dir="ltr">

```cpp
#include <iostream>
#include <fstream> // Library الخاصة بالتعامل مع الـ Files
using namespace std;

int main()
{
// 1. تعريف Variable من نوع fstream
fstream MyFile;

    // 2. فتح الـ File بوضع الكتابة (Write Mode)
    // إذا لم تضع مساراً كاملاً (مثل C:\\)، سيتم إنشاؤه في نفس المجلد (Directory) الخاص بالمشروع
    MyFile.open("MyFile.txt", ios::out);

    // 3. التأكد من أن الـ File مفتوح وجاهز
    if (MyFile.is_open())
    {
        // استخدام اسم الـ File Variable كأنه cout تماماً
        // 🚨 لا تنسَ إضافة \n أو endl وإلا ستلتصق كل النصوص ببعضها في سطر واحد!
        MyFile << "This is my first line\n";
        MyFile << "This is my second line\n";
        MyFile << "This is my third line\n";

        // 4. إغلاق الـ File (خطوة بالغة الأهمية)
        MyFile.close();
    }
    else
    {
        cout << "Error: Unable to open the file!" << endl;
    }

    return 0;

}
```

</div>

### 🔍 أين تجد الـ File الذي تم إنشاؤه؟

إذا كنت تستخدم Visual Studio، وتُريد رؤية الـ File النصي (.txt) الذي أنشأه كودك:

1. اذهب إلى نافذة Solution Explorer (غالباً على يمين الشاشة).

2. اضغط (Right-Click) على اسم المشروع (Project).

3. اختر Open Folder in File Explorer.

4. ستجد الـ File الذي أسميته MyFile.txt موجوداً هناك، ويمكنك فتحه ببرنامج الـ Notepad لترى النتيجة.

## ➕ الدرس الثالث والخمسون: إضافة البيانات للملفات (Append Mode: Append Data to File)

في الدرس السابق، استخدمنا وضع الكتابة (Write Mode) عن طريق ios::out. المشكلة في هذا الوضع أنه يمسح جميع الـ Data القديمة الموجودة في الـ File ويبدأ الكتابة من الصفر (Overwrite).

ماذا لو أردنا الاحتفاظ بالبيانات القديمة (مثل قائمة بأسماء سابقة) وإضافة بيانات جديدة في نهاية الـ File؟
هنا يأتي دور وضع الإضافة (Append Mode).

### 1. ما هو الـ Append Mode (ios::app)؟

هو وضع يسمح لك بفتح الـ File، وإبقاء جميع محتوياته القديمة كما هي دون مسح، وتوجيه المؤشر لأسفل الـ File بحيث يتم إضافة أي Data جديدة في النهاية.

### 2. الطريقة الاحترافية لفتح الـ File (دمج الأوضاع):

رغم أنه يمكنك استخدام ios::app بمفردها، إلا أن أفضل ممارسة (Best Practice) هي دمج وضع الكتابة مع وضع الإضافة باستخدام معامل Bitwise OR (|) هكذا:
ios::out | ios::app

لماذا ندمجهم معاً؟

ios::out: يضمن إنشاء الـ File من الصفر إذا لم يكن موجوداً أصلاً.

ios::app: يضمن عدم مسح الـ Data القديمة إذا كان الـ File موجوداً بالفعل.

💻 تطبيق عملي بالكود:

<div dir="ltr">

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream MyFile;

    // فتح الـ File بدمج وضع الكتابة مع وضع الإضافة باستخدام (|)
    MyFile.open("MyFile.txt", ios::out | ios::app);

    if (MyFile.is_open())
    {
        // هذه السطور ستتم إضافتها في نهاية الـ File
        // دون التأثير على البيانات القديمة (مثل Mohammed و Ali و Lama)
        MyFile << "This is a new line added using Append Mode.\n";
        MyFile << "Data is safe and not overwritten!\n";

        MyFile.close();
    }
    else
    {
        cout << "Error: Unable to open the file!" << endl;
    }

    return 0;
}
```

</div>

### 💡 الفائدة الهندسية:

استخدام الـ Append Mode هو الأساس في بناء أنظمة تسجيل الأحداث (Log Files)، حيث يقوم البرنامج بكتابة الأخطاء أو حركات المستخدمين سطراً تلو الآخر بمرور الوقت دون مسح السجل القديم الذي نحتاجه للـ Debugging!

## 📖 الدرس الرابع والخمسون: قراءة الملفات (Read Mode: Print File Content)

بعد أن تعلمنا كيف نكتب في الـ File ونضيف إليه، حان الوقت لنتعلم كيف نفتح الـ File بوضع القراءة (Read Mode) لنجلب كل محتوياته ونطبعها على الشاشة. للقيام بذلك، سنقوم ببناء Function مخصصة تقوم بهذه المهمة لتسهيل إعادة استخدامها.

### 1. ما هو الـ Read Mode (ios::in)؟

هو وضع (Mode) يفتح الـ File للقراءة (Input) فقط. هذا الوضع لا يسمح لك بتعديل الـ File نهائياً، وهو يعتبر الأسرع لأنه مخصص لجلب الـ Data فقط.

### 2. كيف نقرأ الـ File سطراً بسطر؟

سنستخدم دالة getline() التي تعرفنا عليها سابقاً مع الـ cin، ولكن هذه المرة سنمرر لها الـ Variable الخاص بالـ File. لكي نقرأ كل السطور، سنضع الدالة داخل while loop لتستمر في القراءة حتى تصل إلى نهاية الـ File.

💻 تطبيق عملي بالكود:

<div dir="ltr">

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function تستقبل اسم أو مسار الـ File كـ Parameter
void PrintFileContent(string FileName)
{
    fstream MyFile;

    // فتح الـ File بوضع القراءة (Read Mode)
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line; // Variable لتخزين كل سطر تتم قراءته

        // While Loop تستمر طالما أن دالة getline تقرأ سطراً جديداً بنجاح
        while (getline(MyFile, Line))
        {
            cout << Line << endl; // طباعة السطر على الشاشة
        }

        // إغلاق الـ File بعد الانتهاء
        MyFile.close();
    }
    else
    {
        cout << "Error: Unable to open the file!" << endl;
    }
}

int main()
{
    // استدعاء الـ Function وتمرير اسم الـ File لها
    PrintFileContent("MyFile.txt");

    return 0;
}
```

</div>

### 💡 الفائدة الهندسية:

بناء Function خاصة بقراءة الـ Files يسهل عليك تنظيم الكود الخاص بك. دالة getline(MyFile, Line) تقوم بسحب السطر بالكامل من الـ File وتضعه داخل الـ String، وتكرارها في الـ while loop هو الطريقة المثالية والآمنة لجلب كل الـ Data دون خسارة أي كلمات!

## 📥 الدرس الخامس والخمسون: تحميل البيانات من الـ File إلى الـ Vector (Load Data From File to Vector)

في الدروس السابقة، تعلمنا كيف نكتب، نضيف، ونقرأ من الـ File. ولكن يواجهنا تحدٍ برمجي حقيقي:
مكتبة fstream لا توفر طريقة مباشرة ومريحة للذهاب إلى "سطر معين" (Record) داخل الـ File لتعديله أو حذفه (مثلاً: لا يمكنك بسهولة تغيير اسم "محمد" إلى "علي" وحفظه مباشرة في نفس المكان داخل الـ File النصي).

### 1. الحل الهندسي الذكي (The Workaround):

للتغلب على هذه المشكلة، نستخدم خطة من ثلاث مراحل:

نفتح الـ File بوضع القراءة (Read Mode).

نقرأ محتوياته سطراً بسطر، ولكن بدلاً من طباعتها على الشاشة، نخزنها داخل Vector (لأن الـ Vector يوفر مرونة عالية جداً للبحث، التعديل، والحذف في الـ RAM).

(في الدروس القادمة) سنقوم بتعديل ما نريده داخل الـ Vector، ثم نفتح الـ File بوضع الـ Write Mode ليمسح محتوياته القديمة ونقوم بعمل Save للـ Vector المحدث بالكامل داخله!

في هذا الدرس، سنقوم بتطبيق الخطوتين 1 و 2 فقط (قراءة الـ File ووضعه داخل Vector).

### 2. التريكة الهندسية (Pass by Reference):

عند بناء الـ Function التي ستحمل الـ Data، يجب تمرير الـ Vector الخاص بنا باستخدام الـ Reference (&)، وذلك لكي ينعكس أي شيء نضيفه (push_back) داخل الـ Function على الـ Vector الأصلي الموجود في الـ main.

💻 تطبيق عملي بالكود:

<div dir="ltr">

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Function تقوم بفتح الـ File وتعبئة محتوياته داخل الـ Vector
// 🚨 نستخدم Reference (&) للـ Vector لكي نحتفظ بالبيانات بعد انتهاء الـ Function
void LoadDataFromFileToVector(string FileName, vector<string> &vFileContent)
{
    fstream MyFile;

    // الفتح بوضع القراءة
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        // قراءة الـ File سطراً بسطر
        while (getline(MyFile, Line))
        {
            // بدلاً من cout، نقوم بإضافة السطر مباشرة إلى الـ Vector
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }
}

int main()
{
    // 1. تعريف Vector فارغ من نوع String
    vector<string> vFileContent;

    // 2. استدعاء الـ Function وتمرير اسم الـ File والـ Vector الخاص بنا
    LoadDataFromFileToVector("MyFile.txt", vFileContent);

    // 3. طباعة محتويات الـ Vector للتأكد من أن البيانات تم تحميلها بنجاح
    cout << "--- Vector Content ---" << endl;

    // استخدام Ranged Loop مع Reference (&) لسرعة الأداء وتجنب عملية الـ Copy
    for (string &Line : vFileContent)
    {
        cout << Line << endl;
    }

    return 0;
}
```

</div>

### 💡 الفائدة الهندسية:

تخزين محتويات الـ File داخل Data Structure مرنة مثل الـ Vector هو الأساس الذي تُبنى عليه عمليات تعديل وحذف البيانات (Update & Delete) التي سندرسها في الدروس القادمة. يجب أن تتقن هذا الدرس تماماً!

## 💾 الدرس السادس والخمسون: حفظ الـ Vector إلى الـ File (Save Vector to File)

هذا الدرس هو الجزء الثاني والمُكمّل للدرس السابق. بعد أن قمنا بقراءة محتويات الـ File وتحميلها داخل Vector، نفترض أننا قمنا بالتعديل على هذا الـ Vector في الـ RAM. الآن، كيف نقوم بإعادة حفظ هذه البيانات المحدثة إلى الـ File من جديد؟

### 1. الوضع المطلوب (Write Mode ios::out):

بما أننا نريد استبدال محتويات الـ File القديمة بالبيانات المحدثة والموجودة في الـ Vector، فيجب أن نفتح الـ File باستخدام الـ Write Mode (ios::out).

استخدام وضع الـ ios::out سيضمن مسح محتويات الـ File القديمة تماماً، والبدء بكتابة بيانات الـ Vector الجديدة من الصفر لتجنب تكرار البيانات.

### 2. التريكة في استدعاء الـ Function:

على عكس درس التحميل (Load) الذي استخدمنا فيه الـ Reference (&) لتحديث الـ Vector في الـ main، نحن هنا في دالة الحفظ (Save) نحتاج فقط إلى قراءة الـ Vector. لذلك، سنمرر الـ Vector كـ Parameter عادي (بدون & للمتجه ككل)، ولكننا سنستخدم الـ & داخل حلقة الـ for لسرعة الوصول للعناصر.

💻 تطبيق عملي بالكود:

<div dir="ltr">

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Function تقوم بفتح الـ File وتخزين محتويات الـ Vector بداخله
void SaveVectorToFile(string FileName, vector<string> vFileContent)
{
    fstream MyFile;

    // 🚨 الفتح بوضع الكتابة (Write Mode) لمسح القديم وكتابة الجديد
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        // استخدام Ranged Loop مع Reference (&) للمرور على عناصر الـ Vector بسرعة
        for (string &Line : vFileContent)
        {
            // التحقق من أن السطر ليس فارغاً قبل كتابته في الـ File
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }

        // إغلاق الـ File
        MyFile.close();
    }
}

int main()
{
    // تعريف Vector مليء بالبيانات
    vector<string> vFileContent = {"Ali", "Shadi", "Maher", "Fadi", "Lama"};

    // استدعاء الـ Function وتمرير اسم الـ File والـ Vector
    SaveVectorToFile("MyFile.txt", vFileContent);

    cout << "Vector data has been saved to the file successfully!" << endl;

    return 0;
}

```

</div>

### 💡 الفائدة الهندسية:

بدمج ما تعلمناه في الدرس السابق (Load) وهذا الدرس (Save)، أصبح لدينا حجر الأساس للتعامل الاحترافي مع أي قواعد بيانات نصية. تقوم بقراءة الـ File، تحميله للـ Vector، التعديل على الـ Vector، ثم إعادة حفظه للـ File. هذه هي الدورة الكاملة للبيانات!

## 🗑️ الدرس السابع والخمسون: حذف سجل من الملف (Delete Record From File)

كما وضحنا سابقاً، لغة C++ ومكتبة fstream لا تسمحان لك بالوصول المباشر إلى سطر معين (Record) في منتصف الـ File وحذفه.
لذلك، نستخدم حيلة هندسية ذكية (The Workaround) تشبه تجميع مكعبات الـ Lego. نعتمد فيها على الدوال التي قمنا ببنائها في الدروس السابقة.

خطوات الحذف:

نستخدم دالة LoadDataFromFileToVector لتحميل كامل بيانات الـ File داخل Vector.

نقوم بالمرور على الـ Vector باستخدام الـ for loop للبحث عن الـ Record المطلوب.

بمجرد العثور على الـ Record، نقوم بتفريغ قيمته وتحويله إلى Empty String ("").

نستخدم دالة SaveVectorToFile لكتابة الـ Vector المحدث إلى الـ File (بما أن الدالة تتخطى السطور الفارغة، لن يتم كتابة الـ Record المحذوف).

💻 تطبيق عملي بالكود:

سنقوم ببناء دالة DeleteRecordFromFile تعتمد على الدوال السابقة وتنفذ المهمة.

<div dir="ltr">

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// (نفترض وجود دالة LoadDataFromFileToVector ودالة SaveVectorToFile ودالة PrintFileContent كما تم برمجتها سابقاً)

// Function تقوم بحذف سجل معين من الملف
void DeleteRecordFromFile(string FileName, string RecordToDelete)
{
    vector<string> vFileContent;

    // 1. تحميل البيانات من الـ File إلى الـ Vector
    LoadDataFromFileToVector(FileName, vFileContent);

    // 2. المرور على الـ Vector وتفريغ الـ Record المطلوب
    for (string &Line : vFileContent)
    {
        if (Line == RecordToDelete)
        {
            // تم العثور على السجل، نجعله فارغاً لكي لا يتم حفظه لاحقاً
            Line = "";
        }
    }

    // 3. إعادة حفظ الـ Vector المحدث إلى الـ File (وضع الكتابة سيمسح المحتوى القديم)
    SaveVectorToFile(FileName, vFileContent);
}

int main()
{
    string FileName = "MyFile.txt";

    cout << "--- File Content BEFORE Deletion ---" << endl;
    PrintFileContent(FileName);

    // تنفيذ عملية الحذف (البحث عن كلمة "Ali" وحذفها من الـ File)
    DeleteRecordFromFile(FileName, "Ali");

    cout << "\n--- File Content AFTER Deletion ---" << endl;
    PrintFileContent(FileName);

    return 0;
}

```

</div>

### 💡 الفائدة الهندسية:

هذا الدرس هو مثال عملي رائع على فكرة Reusability (إعادة الاستخدام). بدلاً من كتابة كود طويل ومعقد لحل مشكلة الحذف، قمنا ببساطة باستخدام دالتين قمنا بإنشائهما مسبقاً (Load و Save)، وأضفنا بينهما خطوة بسيطة لمعالجة الـ Vector. هكذا يبني المبرمجون المحترفون تطبيقاتهم المتقدمة!

## 🔄 الدرس الثامن والخمسون: تحديث سجل في الملف (Update Record In File)

كما فعلنا في درس الحذف (Delete)، لا توفر مكتبة fstream طريقة مباشرة لتعديل (Update) سطر معين (Record) داخل الـ File. سنستخدم نفس الحيلة الهندسية بالاعتماد على الـ Vector، ولكن بدلاً من تفريغ قيمة الـ Record، سنقوم بتغييرها إلى القيمة الجديدة.

خطوات التحديث:

نستخدم دالة LoadDataFromFileToVector لتحميل كامل بيانات الـ File داخل Vector.

نقرأ الـ Vector باستخدام for loop (مع تمرير العنصر بالمرجع & لتعديله) للبحث عن الـ Record المطلوب تحديثه.

بمجرد العثور على الـ Record، نقوم بتغيير قيمته إلى القيمة الجديدة (التي نمررها كـ Parameter).

نستخدم دالة SaveVectorToFile لكتابة الـ Vector المحدث بالكامل فوق الـ File القديم.

💻 تطبيق عملي بالكود:

بنية الكود مطابقة تقريباً بنسبة 99% لكود دالة الحذف السابقة، مع تغيير بسيط داخل جملة الـ if. سنقوم ببناء Function تستقبل 3 بارامترات: اسم الـ File، السجل القديم الذي نبحث عنه، والسجل الجديد الذي نريد وضعه مكانه.

<div dir="ltr">

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// (نفترض وجود دوال LoadDataFromFileToVector و SaveVectorToFile و PrintFileContent)

// Function تقوم بتحديث سجل معين في الملف
void UpdateRecordInFile(string FileName, string RecordToUpdate, string UpdateTo)
{
    vector<string> vFileContent;

    // 1. تحميل البيانات من الـ File إلى الـ Vector
    LoadDataFromFileToVector(FileName, vFileContent);

    // 2. المرور على الـ Vector للبحث عن الـ Record المطلوب
    for (string &Line : vFileContent)
    {
        if (Line == RecordToUpdate)
        {
            // تم العثور على السجل، نقوم باستبداله بالقيمة الجديدة
            Line = UpdateTo;
        }
    }

    // 3. إعادة حفظ الـ Vector المحدث إلى الـ File (ستكتب القيمة الجديدة بدلاً من القديمة)
    SaveVectorToFile(FileName, vFileContent);
}

int main()
{
    string FileName = "MyFile.txt";

    cout << "--- File Content BEFORE Update ---" << endl;
    PrintFileContent(FileName);

    // تنفيذ عملية التحديث (تغيير كل "Ali" لتصبح "Omar")
    UpdateRecordInFile(FileName, "Ali", "Omar");

    cout << "\n--- File Content AFTER Update ---" << endl;
    PrintFileContent(FileName);

    return 0;
}

```

</div>

### 💡 الفائدة الهندسية:

تُثبت هذه العملية مرة أخرى القوة الحقيقية لـ Reusability وإعادة استخدام الدوال كقطع الـ Lego. بمجرد أن بنيت دوال أساسية للتحميل (Load) والحفظ (Save)، أصبحت أي عملية أخرى (مثل Update و Delete) عبارة عن سطرين أو ثلاثة من المنطق البسيط يوضعان بينهما.

</div>
