<div dir="rtl">

# ما هو OOP ولماذا؟

## 📝 الدرس: What is OOP and Why
<!-- Video 01: What is OOP and Why.mp4 -->

السلام عليكم ورحمة الله وبرRكاته.

نبدأ كورس **OOP as it Should Be (Concepts)** — أول درس يجيب على سؤال: **ما هو Object-Oriented Programming ولماذا نحتاجه؟**

---

## 🔁 من أين جئنا؟ (Functional Programming)

خلال الكورسات الثمانية السابقة تعلّمنا **Functional Programming (FP)**:

- تجزئة المشروع لـ **Small Functions** (سياسة **Divide & Conquer**)
- كل Function تعمل **شغلة واحدة فقط**
- بناء المشاريع من Functions و Procedures مرتّبة وراء بعض
- مئات التمارين والمشاريع على هذا الأسلوب

> **ملاحظة:** كورس 09 (Foundations Level 2) ليس شرطاً قبل هذا الكورس — المهم أن تكون مطبّقاً للكورسات 01–08.

الآن يمكن الإجابة عن السؤال الذي كان يُسأل سابقاً: **ما الفرق بين OOP و FP؟**

---

## 🏫 مثال: University System بـ FP

لو بنينا **نظام جامعة** باستخدام FP، سنحتاج **آلاف** الـ Functions، مثل:

| المجال | أمثلة Functions |
|--------|-----------------|
| الطلاب | `AddStudent`, `UpdateStudent`, `DeleteStudent`, `CalculateAverage` |
| الكورسات | `AddCourse`, `UpdateCourse`, `DeleteCourse`, `EnrollStudentInCourse` |
| الدكاترة | `AssignCourseToDoctor`, `SendEmailToDoctor` |
| التواصل | `SendEmailToStudent`, `SendTextMsgToStudent` |
| الموظفين | `AddEmployee`, `UpdateEmployee`, `DeleteEmployee`, `CalculateSalary` |

في نظام كبير قد يصل العدد إلى **1000–2000 Function** أو أكثر — **وهذا ليس المشكلة بحد ذاتها.**

---

## ❌ المشكلة الحقيقية: الفوضى لا العدد

### تشبيه جهات الاتصال

تخيّل عندك **1000 Contact** (اسم + رقم) — كل واحد على ورقة منفصلة **بدون تنظيم**:

- لما تطلب رقم "محمد أبو هدهود" → تدور بين كل الأوراق
- الـ 1000 Contact **موجودين**، لكن **التعامل معهم صعب**

لو نظّمتهم أبجدياً (A → Z) → حياتك تصير سهلة، **حتى لو كانوا 10,000.**

### نفس الفكرة في FP

| ليس المشكلة | المشكلة الفعلية |
|-------------|-----------------|
| وجود 1000 أو 10000 Function | Functions **غير منظّمة** |
| | صعوبة **الوصول** و**التذكّر** |
| | صعوبة **التعامل** كـ Developer |
| | احتمال **إعادة كتابة** Function موجودة أصلاً |

> **الخلاصة:** المشكلة ليست في **كمية** الكود — المشكلة في **غياب التنظيم**.

---

## ✅ الحل: Object-Oriented Programming

**OOP** جاءت لحل مشكلة **تنظيم الكود** — واحدة من أهم فضائلها.

### الفرق الجوهري في طريقة التفكير

| Functional Programming | Object-Oriented Programming |
|------------------------|----------------------------|
| تفكير من **تحت لفوق** (Bottom-Up) | تفكير من **فوق لتحت** (Top-Down) |
| تبرمج **Functions** | تبرمج **أشياء (Objects)** |
| تتعامل مع آلاف Functions مباشرة | تتعامل مع **Objects** كبوابات للوصول للكود |

**OOP** تجعلك تفكّر في الكود **كما تفكّر في الحياة العملية.**

---

## 🧩 Top-Down: ما هي "الأشياء" في نظام الجامعة؟

بدل ما نبدأ من Functions، نسأل: **ما هي الكائنات (Objects) في نظام الجامعة؟**

```
University System
├── Student      (طالب)
├── Course       (كورس)
├── Employee     (موظف)
├── Doctor       (دكتور)
├── Major        (تخصص)
├── College      (كلية)
├── Department   (قسم)
└── ...
```

كل "شيء" = **Object**.

---

## 📦 تنظيم الـ Functions تحت Objects

نفس الـ 2000 Function — لكن **موزّعة** تحت مظلّة كل Object:

```
Student
├── FirstName, LastName, Email, Address  ← Members (Variables)
├── CalculateAverage()                   ← Methods
├── SendEmail()
├── EnrollInCourse()
├── PayFees()
└── UnEnrollFromCourse()

Doctor
├── SendEmail()
├── TotalStudents()
└── TakeVacation()

College
├── Name
├── PhoneNumber
└── Department
```

| المصطلح | المعنى |
|---------|--------|
| **Class** | القالب/التعريف (مثل Struct لكن أقوى) |
| **Object** | نسخة حقيقية من Class (مثل `Student1`) |
| **Members** | المتغيّرات داخل Class |
| **Methods** | Functions/Procedures **داخل** Class |

> **Method** = أي Function أو Procedure موجود **داخل** Class. احفظ هذا المصطلح.

---

## 🔗 الربط مع Struct (من C++ Level 1)

قبل Struct كنا نعرّف متغيّرات الطالب **في الشارع** (منفصلة):

```cpp
string FirstName;
string LastName;
float GPA;
```

بعد Struct — جمعناها تحت مظلّة واحدة:

```cpp
struct stStudent {
    string FirstName;
    string LastName;
    float GPA;
};
```

**Class** شبيهة بـ Struct — لكن **تضيف Methods أيضاً:**

<div dir="ltr">

```cpp
class clsStudent {
    string FirstName;
    string LastName;
    float GPA;

public:
    void CalculateAverage() { /* ... */ }
    void SendEmail() { /* ... */ }
    void EnrollInCourse(int CourseID) { /* ... */ }
};
```

</div>

---

## 💻 كيف يتغيّر تعاملك مع الكود؟

### Functional Programming

```cpp
CalculateAverage(StudentID);
SendEmail(StudentID, "Hello");
EnrollStudentInCourse(StudentID, 10);
```

→ لازم **تتذكّر** أسماء آلاف Functions.

### Object-Oriented Programming

<div dir="ltr">

```cpp
Student1.CalculateAverage();
Student1.SendEmail("Hello");
Student1.EnrollInCourse(10);
Student1.PayFees();
Student1.UnEnrollFromCourse(10);
```

</div>

→ أنت واقف على **Object** واحد (`Student1`) — كل ما تحتاجه **قدّامك** بعد النقطة `.`

**Developer جديد** يدخل على المشروع:
- لا يحفظ 2000 Function
- يعرف: عندي Class اسمها `Student` → أعمل Object → أوصل لكل شيء متعلق به

---

## 🎯 فوائد OOP (معاينة — سنشرحها بالتفصيل لاحقاً)

| الفائدة | الشرح المختصر |
|---------|---------------|
| **تنظيم الكود** | Functions مجمّعة تحت Objects — مثل دليل هاتف منظّم |
| **Top-Down Thinking** | تفكّر بالكائنات قبل التفاصيل |
| **Reusability** | إعادة استخدام الكود بسهولة |
| **Control & Security** | التحكم في من يصل لأي Method (Access Control) |
| **Inheritance (الوراثة)** | تعديل في مكان واحد ينعكس على كل الأبناء |
| **Contracts (العقود)** | OOP **تجبرك** على اتباع القواعد — الكود لا يعمل Compile إلا إذا طبّقت المطلوب |

### مثال على Inheritance (معاينة)

مشروع فيه 40–50 شاشة — تعديل في **مكان واحد** انعكس على كل الشاشات في **5 دقائق** — بدل ما تعدّل 50 مكان.

> FP: الاتفاق على القواعد **بالثقة** ("يا أحمد اعمل كذا...")
> OOP: الاتفاق **مُفرَض بالكود** — لا Compile بدون الالتزام

---

## 📊 FP vs OOP — ملخص سريع

```
┌─────────────────────────────────────────────────────────┐
│  FP: 2000 Function مرمية في "الشارع"                    │
│       ↓                                                 │
│  Developer يتذكر ويدور ويضيع                           │
├─────────────────────────────────────────────────────────┤
│  OOP: 2000 Function منظّمة تحت Objects                  │
│       ↓                                                 │
│  Developer يتعامل مع Student, Doctor, Course...        │
│  وكل Object بوابة لكل ما يخصّه                         │
└─────────────────────────────────────────────────────────┘
```

---

### 💡 Key Concepts

- **FP** = تجزئة المشروع لـ Functions صغيرة وبناؤها مثل Lego
- **OOP** = البرمجة الشيئية — تبرمج **Objects** لا Functions منفصلة
- المشكلة في FP للأنظمة الكبيرة = **عدم التنظيم**، لا عدد Functions
- **Class** = تعريف Object (Members + Methods)
- **Method** = Function/Procedure داخل Class
- **Top-Down** = تبدأ من الكائنات (Student, Course...) ثم التفاصيل
- OOP = تنظيم + Reusability + Control + Inheritance + Contracts

### 📌 Examples

**University System Objects:** Student, Course, Employee, Doctor, Major, College, Department

**Student Object — Methods:**
- `CalculateAverage()` — حساب المعدل
- `SendEmail()` — إرسال إيميل **لهذا الطالب فقط**
- `EnrollInCourse(10)` — تسجيله في كورس رقم 10
- `PayFees()` — دفع الرسوم
- `UnEnrollFromCourse(10)` — سحب تسجيله من كورس

**Doctor Object — Methods:**
- `SendEmail()` — إيميل للدكتور
- `TotalStudents()` — عدد الطلاب المسجّلين معه
- `TakeVacation()` — إعطاء إجازة

---

> **الدرس القادم:** نبدأ التطبيق العملي — Classes, Objects, Members — خطوة بخطوة.

</div>
