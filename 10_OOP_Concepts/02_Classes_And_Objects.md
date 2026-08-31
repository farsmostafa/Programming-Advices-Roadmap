<div dir="rtl">

# Classes and Objects

---

## 📝 الدرس: Classes and Objects
<!-- Video 02: Classes and Objects.mp4 -->

السلام عليكم ورحمة الله وبركاته.

في الدرس السابق تعرّفنا على **أهمية OOP** — التفكير **Top-Down** والتعامل مع **Objects (أشياء)** بدل Functions متفرّقة. اليوم نطبّق هذا عملياً ونفهم **Class** و **Object**.

---

### 🔤 من أين جاءت كلمة Class؟

**Class** مشتقة من **Classification** = **التصنيف**.

في نظام الجامعة، لما فكّرت بالبرنامج كـ **أشياء** (Student, Course, Doctor...) — **صنّفت** الكود:

```
Student   ← كل Functions/Variables المتعلقة بالطالب
Course    ← كل ما يخص الكورس
Doctor    ← كل ما يخص الدكتور
Employee  ← ...
```

كل "صنف" = **Class**. زي "Class A" و "Class B" في الطائرة — **تصنيفات**.

> **قاعدة:** قبل ما يكون Object، لازم يكون Class. `clsStudent`, `clsCourse`, `clsEmployee`...

---

### 🔄 مراجعة سريعة: FP → OOP

| FP | OOP |
|----|-----|
| 2000 Function متفرّقة | نفس الـ Functions **موزّعة** تحت Objects |
| صعب الوصول والتذكّر | كل Object = **بوابة** لكل ما يخصّه |
| Functional = Procedural (نفس الشيء) | OOP = paradigm مختلف |

---

### 📦 Class vs Struct

**Struct** (من C++ Level 1):
- **Data Type** — مظلّة تجمع Variables مرتبطة
- `stPerson Person1` → Variable من نوع Struct

**Class** — نفس الفكرة + **Methods**:

| | Struct | Class |
|---|--------|-------|
| Data Type | ✅ | ✅ |
| Variables (Members) | ✅ | ✅ |
| Functions داخلها | ❌ (في الدورة) | ✅ Methods |

> مبدئياً: **Class = Struct + Methods**. الفرق الكامل يُشرح لاحقاً في الكورس.

---

### 💻 مثال: clsPerson

<div dir="ltr">

```cpp
#include <iostream>
using namespace std;

class clsPerson
{
public:
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }
};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Mohammed";
    Person1.LastName = "Abu Hadeed";

    cout << Person1.FullName();  // Mohammed Abu Hadeed
    return 0;
}
```

</div>

---

### 🔒 private by default — لماذا لم يظهر شيء؟

لو عرّفت Class **بدون** `public:`:

<div dir="ltr">

```cpp
class clsPerson
{
    string FirstName;   // private (default)
    string LastName;    // private (default)
    string FullName() { return FirstName + " " + LastName; }
};

clsPerson Person1;
Person1.FirstName = "Mohammed";  // ❌ لا يظهر في IntelliSense — private!
```

</div>

**قاعدة:** كل شيء داخل Class **private by default** — حتى بدون كتابة `private:`.

| `public:` | المعنى |
|-----------|--------|
| Members تحته | **Exposed** للخارج — Developer يراهم عبر `.` |
| بدون `public:` | **Private** — للاستخدام الداخلي فقط |

---

### 🎯 Object = Instance

| المصطلح | المعنى |
|---------|--------|
| **Class** | التعريف / القالب (Blueprint) — Data Type |
| **Object** | Variable من نوع Class = **Instance** (نسخة) |

<div dir="ltr">

```cpp
clsPerson Person1;   // Object — Instance من clsPerson
string s1;           // Object — Instance من class string
int x;               // Variable من نوع int (ليس Object بالمصطلح OOP)
```

</div>

**Class = Blueprint** (مخطط العمارة على ورق أزرق) — **Object = البناء الحقيقي**.

> لا تتعامل مع Class مباشرة — لازم تعرّف **Object** منها.

---

### 📌 string — أكبر مثال على Class

طول ما كنت تكتب `string s1` — كنت **تعرّف Object** من class `string`!

<div dir="ltr">

```cpp
string s1;
s1.length();    // Method
s1.clear();     // Method
s1.replace();   // Method
```

</div>

Microsoft جمعوا كل ما يخص String في **Class واحدة** — Classification. `s1.` يُظهر **public Methods** فقط؛ Methods داخلية **مخفية** عنك (private).

---

### 🏋️ تمرين عملي

طبّق الكود بنفسك — الملف:

**[`practice/#02_ClassesAndObjects_Task.cpp`](practice/#02_ClassesAndObjects_Task.cpp)**

---

### 💡 Key Concepts (فيديو 02)

- **Class** = Classification — تصنيف الكود تحت مظلّة Object
- **Class** = Data Type + Members + Methods
- **Object** = Instance — Variable من نوع Class
- **Method** = Function/Procedure **داخل** Class
- **private by default** — استخدم `public:` لإظهار Members للخارج
- **string** = Class جاهزة — كنت تستخدم Objects من قبل

### 📌 Examples (فيديو 02)

- University: `clsStudent`, `clsCourse`, `clsDoctor`
- Hospital: `clsPatient`, `clsClinic`, `clsPharmacy`
- `Person1.FullName()` — استدعاء Method عبر Object

---

## 📝 الدرس: Class Members
<!-- Video 03: Class Members.mp4 -->

---

### 📋 Members = محتويات Class/Object

**Member** = **عضو** — مثل "أعضاء Class A Developers في الشركة".

محتويات Class/Object تُسمى **Members**، وتنقسم لقسمين:

```
Class Members
├── Data Members        ← Variables — تخزّن Data
└── Method Members      ← Functions/Procedures — لا تخزّن Data
    (Function Members)
```

---

### 📊 Data Members vs Method Members

| النوع | مثال | الوظيفة |
|-------|------|---------|
| **Data Member** | `FirstName`, `LastName` | تخزين Data (محمد، أبو هدهود) |
| **Method Member** | `FullName()` | Function ترجع `FirstName + LastName` |

<div dir="ltr">

```cpp
class clsPerson
{
public:
    string FirstName;    // Data Member
    string LastName;     // Data Member

    string FullName()    // Method Member (Function Member)
    {
        return FirstName + " " + LastName;
    }
};
```

</div>

---

### 🔗 Methods ترى Data Members

داخل `FullName()` — `FirstName` و `LastName` **مرئيان** كأنهما **Global Variables** داخل Class:

- Method داخل Class → يرى **كل** Variables المعرفة في Class (public أو private)
- بالنسبة للـ Method: Data Members = Variables "Global" داخل Class

---

### 📝 Class = Template

| Class | Object |
|-------|--------|
| Template / Form **فارغ** | **نسخة** تشتغل عليها |
| لا تستخدمها مباشرة | `clsPerson Person1` — Instance |

> `int x` → Variable من int | `clsPerson Person1` → **Object** من clsPerson

---

### 💡 Key Concepts (فيديو 03)

- **Members** = Data Members + Method/Function Members
- **Data Member** = Variable داخل Class — يخزّن Data
- **Method Member** = Function داخل Class
- Methods داخل Class ترى Data Members مباشرة
- **Object** = Instance = نسخة من Class

### 📌 Examples (فيديو 03)

- `FirstName`, `LastName` → Data Members
- `FullName()` → Method Member

---

## 📝 الدرس: Objects In Memory
<!-- Video 04: Objects In Memory.mp4 -->

---

### 🧠 كيف يُمثَّل Object في الذاكرة؟

Class = Data Type → تقدر تعرّف **أكثر من Object** (زي `int x, y, z`):

<div dir="ltr">

```cpp
clsPerson Person1;
clsPerson Person2;

Person1.FirstName = "Mohammed";
Person1.LastName = "Abu Hadeed";

Person2.FirstName = "Ali";
Person2.LastName = "Maher";
```

</div>

---

### 📐 تمثيل الذاكرة

```
┌─────────────────────────────────────────────────────────────┐
│  SHARED (مكان واحد لكل Objects من نفس Class)               │
│  ┌─────────────────────────────────────────────────────┐   │
│  │  Function Members: FullName(), ...                   │   │
│  └─────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────┘
         ▲                              ▲
         │                              │
┌────────┴────────┐          ┌─────────┴─────────┐
│  Person1        │          │  Person2          │
│  (Own Space)    │          │  (Own Space)      │
│                 │          │                   │
│  FirstName:     │          │  FirstName:       │
│    Mohammed     │          │    Ali            │
│  LastName:      │          │  LastName:        │
│    Abu Hadeed   │          │    Maher          │
└─────────────────┘          └───────────────────┘
     Data Members                  Data Members
     (منفصلة)                     (منفصلة)
```

---

### 📌 القواعد

| نوع Member | في الذاكرة |
|------------|-----------|
| **Data Members** | **منفصلة** — كل Object له مساحته (Own Space) |
| **Function Members** | **Shared** — مكان واحد مشترك لكل Objects |

**لماذا Function Members مشتركة؟**
- Functions **لا تخزّن Data**
- لا داعي تكرارها 10,000 مرة لو عندك 10,000 Person
- توفير Memory

**Person1 ≠ Person2 في Data** — محمد ≠ علي. لكن `FullName()` **نفس الـ Function** للاثنين.

---

### 💡 Key Concepts (فيديو 04)

- كل Object = **Own Space** للـ Data Members
- Function Members = **Shared** بين كل Objects من نفس Class
- Object يمثّل **Data Members** في Memory
- 10,000 Objects → Data منفصل، Functions مشتركة

### 📌 Examples (فيديو 04)

- Person1: Mohammed + Abu Hadeed
- Person2: Ali + Maher
- `FullName()` — Shared Method

---

## 📝 الدرس: Access Specifiers / Modifiers
<!-- Video 05: Access SpecifiersModifiers.mp4 -->

---

### 🛡️ OOP = Control على الكود

**Access Specifiers** (Access Modifiers) = **من يصل** للـ Member و**من لا يصل**.

---

### 👥 ثلاث جهات تستفيد من Members

```
                    ┌─────────────────────┐
                    │      Class          │
                    │  ┌───────────────┐  │
     1. Outside ───►│  │   Members     │  │◄─── 2. Inside (Methods)
     (Developer     │  └───────────────┘  │
      via Object)   └──────────┬──────────┘
                               │
                    3. Inheriting Classes
                       (الوراثة — لاحقاً)
```

---

### 🔑 الثلاثة Access Specifiers

| Specifier | من برا Class | داخل Class | Classes الوارثة |
|-----------|:------------:|:----------:|:---------------:|
| **private** | ❌ | ✅ | ❌ |
| **protected** | ❌ | ✅ | ✅ |
| **public** | ✅ | ✅ | ✅ |

---

### 1️⃣ private

- **خاص** بالـ Class فقط — أعضاء Class (Methods + Variables) فقط
- من **برا** → `Person1.Var1` ❌ لا يظهر
- Classes **الوارثة** → ❌ لا تراه

**الاستخدام:**
- Variables/Functions **داخلية** — لا تريد Developer يراها
- **حماية** Variables الحساسة من التعديل العشوائي

---

### 2️⃣ protected

- **private للخارج** + **public للورثة**
- من برا → ❌ | داخل Class → ✅ | Class وارث → ✅

> يُشرح بالتفصيل مع **Inheritance** (فيديو 20+).

---

### 3️⃣ public

- **Exposed** للجميع — برا، جوا، ورثة
- `FirstName`, `LastName`, `FullName()` — public

---

### ⚠️ Default = private

<div dir="ltr">

```cpp
class clsPerson
{
    int Var1 = 5;              // private — حتى بدون كتابة private:
    int Function1() { return 40; }  // private

protected:
    int Var2;
    int Function2();

public:
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

    void Function3()
    {
        Function1();   // ✅ OK — inside class
        Var1 = 10;     // ✅ OK — inside class
        Function2();   // ✅ OK — inside class
    }
};

int main()
{
    clsPerson Person1;

    Person1.FirstName;     // ✅ public
    Person1.FullName();    // ✅ public
    Person1.Function3();   // ✅ public

    // Person1.Var1;       // ❌ private
    // Person1.Function1(); // ❌ private
    // Person1.Function2(); // ❌ protected from outside
}
```

</div>

---

### 🔍 ماذا يرى Developer عند `Person1.`؟

**يظهر فقط:** Members الـ **public** — `FirstName`, `LastName`, `FullName()`, `Function3()`

**لا يظهر:** `Var1`, `Function1` (private) | `Var2`, `Function2` (protected)

---

### 📌 string — مثال عملي

<div dir="ltr">

```cpp
string s1;
s1.   // IntelliSense يُظهر public Methods فقط
```

</div>

داخل `string` class — Methods **كثيرة private** (Capacity, internal helpers). Microsoft **أخفوها**:
- **Security** — لا تخرب شيء
- **راحة** — لا يوجع رأسك بما لا تحتاجه

> "خافينهم عنك" = **Encapsulation** — نشرحها لاحقاً.

---

### 💡 Key Concepts (فيديو 05)

- **Access Specifier** = من له صلاحية الوصول للـ Member
- **private** — Class فقط | **protected** — Class + ورثة | **public** — الجميع
- **Default = private**
- private Methods = **Internal Use** — لا تعرّضها للـ Developer
- OOP = **More Secure Code** + **Control** + أقل أخطاء

### 📌 Examples (فيديو 05)

| Member | Specifier | Person1. يراه؟ |
|--------|-----------|----------------|
| Var1, Function1 | private | ❌ |
| Var2, Function2 | protected | ❌ (من برا) |
| FirstName, FullName | public | ✅ |

---

> **الدرس القادم:** Properties — Set and Get (فيديو 06)

</div>
