use HR_DB


Select * from Employees




Select Employees.FirstName , Employees.Gendor 
From Employees 
Where  Not Employees.Gendor = 'F'

Select Employees.FirstName , Employees.Gendor 
From Employees 
Where  Employees.Gendor<> 'F'


Select Employees.FirstName +  ' ' + Employees.LastName As Fullname , Employees.ExitDate
From Employees 
Where  Employees.ExitDate is Not Null;

Select Employees.FirstName +  ' ' + Employees.LastName As Fullname , Employees.DepartmentID
From Employees 
Where  Employees.DepartmentID = 1 or Employees.DepartmentID = 2 or Employees.DepartmentID = 5 or Employees.DepartmentID = 7 ;



Select Employees.FirstName +  ' ' + Employees.LastName As Fullname , Employees.DepartmentID
From Employees 
Where  Employees.DepartmentID in (1,2,5,7);


Select Departments.Name 
From Departments
Where Departments.ID in (Select Employees.DepartmentID From Employees Where Employees.MonthlySalary <= 210);


Select Employees.ID,Employees.FirstName +  ' ' + Employees.LastName As [Full Name] , Employees.MonthlySalary
From Employees 
Where  Employees.MonthlySalary in (
	Select Distinct Top 5 Employees.MonthlySalary
	From Employees
	Order By Employees.MonthlySalary Desc
);



Select Employees.FirstName +  ' ' + Employees.LastName As [Full Name] , DateDiff(YEAR , Employees.DateOfBirth,GetDate()) as Age
From Employees ;



Select Today = Getdate()

Select Employees.FirstName +  ' ' + Employees.LastName As [Full Name] , Employees.MonthlySalary
From Employees 
Where Employees.MonthlySalary >= 500 and Employees.MonthlySalary <= 1000;

Select Employees.FirstName +  ' ' + Employees.LastName As [Full Name] , Employees.MonthlySalary
From Employees 
Where Employees.MonthlySalary between 500 and 1000;


Select TotalCount = Count(Employees.MonthlySalary), 
					TotalSum = Sum(Employees.MonthlySalary), 
					Average = Avg(Employees.MonthlySalary), 
					MinSalary = Min(Employees.MonthlySalary), 
					MaxSalary = Max(Employees.MonthlySalary)
From Employees



Select Employees.DepartmentID, 
	   TotalCount = Count(Employees.MonthlySalary), 
	   TotalSum = Sum(Employees.MonthlySalary), 
	   Average = Avg(Employees.MonthlySalary), 
	   MinSalary = Min(Employees.MonthlySalary), 
	   MaxSalary = Max(Employees.MonthlySalary)
From Employees
Group By Employees.DepartmentID
Order By Employees.DepartmentID;



-- Not Valid
Select Employees.DepartmentID, 
	   Employees.FirstName
From Employees
Group By Employees.DepartmentID
Order By Employees.DepartmentID;



Select Employees.DepartmentID, 
	   TotalCount = Count(Employees.MonthlySalary), 
	   TotalSum = Sum(Employees.MonthlySalary), 
	   Average = Avg(Employees.MonthlySalary), 
	   MinSalary = Min(Employees.MonthlySalary), 
	   MaxSalary = Max(Employees.MonthlySalary)
From Employees
Group By Employees.DepartmentID
Having Count(Employees.MonthlySalary) > 120
Order By Employees.DepartmentID





Select * from(
	Select Employees.DepartmentID, 
		   TotalCount = Count(Employees.MonthlySalary), 
		   TotalSum = Sum(Employees.MonthlySalary), 
		   Average = Avg(Employees.MonthlySalary), 
		   MinSalary = Min(Employees.MonthlySalary), 
		   MaxSalary = Max(Employees.MonthlySalary)
	From Employees
	Group By Employees.DepartmentID
) R1
Where R1.TotalCount > 120
Order by R1.DepartmentID







-- ==============================================================================
-- 1. استعلام الاسترجاع الأساسي
-- SELECT Statement
-- ==============================================================================
-- الوصف: يستخدم هذا الاستعلام لجلب وعرض البيانات من قاعدة البيانات
-- يتم تخزين البيانات المسترجعة في جدول نتائج مؤقت يسمى
-- Result-Set

-- الصيغة العامة: لتحديد أعمدة معينة نكتب أسماء الأعمدة مفصولة بفاصلة
-- SELECT column1, column2, ... FROM table_name;

-- لاسترجاع كافة الأعمدة المتاحة في الجدول نستخدم النجمة
-- SELECT * FROM table_name;

-- أمثلة عملية:
-- استرجاع كافة بيانات الموظفين
SELECT * FROM Employees;

-- طريقة أخرى مطابقة لاسترجاع كافة بيانات الموظفين
SELECT Employees.* FROM Employees;

-- استرجاع أعمدة محددة فقط (توفير لموارد السيرفر)
SELECT ID, FirstName, LastName, MonthlySalary 
FROM Employees;

-- استرجاع أعمدة محددة مع إهمال باقي التفاصيل
SELECT ID, FirstName, DateOfBirth 
FROM Employees;

-- استرجاع كافة بيانات الأقسام
SELECT * FROM Departments;

-- استرجاع كافة بيانات الدول
SELECT * FROM Countries;


-- ==============================================================================
-- 2. استرجاع القيم الفريدة (غير المكررة)
-- SELECT DISTINCT Statement
-- ==============================================================================
-- الوصف: يستخدم هذا الاستعلام لاسترجاع القيم المختلفة فقط ومنع التكرار في النتائج
-- غالبا ما يحتوي العمود على قيم مكررة، هذا الأمر يقوم بتصفيتها وعرض القيم الفريدة
-- Distinct

-- الصيغة العامة: الكلمة المفتاحية تسبق أسماء الأعمدة
-- SELECT DISTINCT column1, column2, ... FROM table_name;

-- أمثلة عملية:

-- استرجاع جميع أرقام الأقسام (ستظهر أرقام الأقسام مكررة لكل موظف)
SELECT DepartmentID FROM Employees;

-- استرجاع أرقام الأقسام الفريدة فقط (معرفة الأقسام الموجودة فعليا بدون تكرار)
SELECT DISTINCT DepartmentID FROM Employees;

-- استرجاع جميع الأسماء الأولى للموظفين (قد يتكرر اسم "محمد" مثلا)
SELECT FirstName FROM Employees;

-- استرجاع قائمة بالأسماء الأولى الفريدة فقط
SELECT DISTINCT FirstName FROM Employees;

-- استرجاع الأسماء والأقسام بشكل طبيعي
SELECT FirstName, DepartmentID FROM Employees;

-- الاسترجاع الفريد بناء على دمج أكثر من عمود (يتجاهل التطابق التام في كلا العمودين معا)
SELECT DISTINCT FirstName, DepartmentID FROM Employees;
GO


-- ==============================================================================
-- 3. تصفية البيانات باستخدام الجملة الشرطية
-- WHERE Statement + AND, OR, NOT
-- ==============================================================================
-- تستخدم هذه الجملة لتصفية السجلات واستخراج البيانات التي تطابق شرطا معينا فقط
-- لا يقتصر استخدامها على استعلامات الاسترجاع بل تستخدم أيضا مع التحديث والحذف
-- SELECT, UPDATE, DELETE

-- يمكن دمج الشروط المتعددة باستخدام المعاملات المنطقية
-- AND, OR, NOT

-- المعامل الأول: يعرض السجل فقط إذا كانت جميع الشروط المرتبطة صحيحة
-- AND
-- المعامل الثاني: يعرض السجل إذا كان أحد الشروط المرتبطة على الأقل صحيحا
-- OR
-- المعامل الثالث: يعكس الشرط ويعرض السجل إذا كان الشرط غير صحيح
-- NOT

-- أمثلة عملية:

-- استرجاع الموظفين الذين تزيد رواتبهم عن 5000
SELECT * FROM Employees 
WHERE MonthlySalary > 5000;

-- استخدام AND (يجب تحقق الشرطين معا)
SELECT * FROM Employees 
WHERE DepartmentID = 1 AND MonthlySalary > 5000;

-- استخدام OR (يكفي تحقق أحد الشرطين)
SELECT * FROM Employees 
WHERE DepartmentID = 1 OR DepartmentID = 2;

-- استخدام NOT (استرجاع الموظفين الذين لا ينتمون للقسم رقم 1)
SELECT * FROM Employees 
WHERE NOT DepartmentID = 1;


-- ==============================================================================
-- 4. معامل التضمين
-- IN Operator
-- ==============================================================================
-- يسمح لك هذا المعامل بتحديد قيم متعددة داخل الجملة الشرطية
-- WHERE
-- يعتبر هذا المعامل اختصارا لكتابة شروط متعددة باستخدام
-- OR
-- يمكن استخدامه لمطابقة قيم مباشرة أو مع استعلام فرعي
-- Subquery

-- أمثلة عملية:

-- الطريقة القديمة والمطولة باستخدام OR
SELECT * FROM Employees 
WHERE DepartmentID = 1 OR DepartmentID = 2;

SELECT * FROM Employees 
WHERE DepartmentID = 1 OR DepartmentID = 2 OR DepartmentID = 7;

SELECT * FROM Employees 
WHERE DepartmentID = 1 OR DepartmentID = 2 OR DepartmentID = 5 OR DepartmentID = 7;

-- الطريقة الاحترافية والمختصرة لنفس النتيجة باستخدام IN
SELECT * FROM Employees 
WHERE DepartmentID IN (1, 2, 5, 7);

-- البحث باستخدام مجموعة نصوص
SELECT * FROM Employees 
WHERE FirstName IN ('Jacob', 'Brooks', 'Harper');

-- الاستعلامات الفرعية المتداخلة
-- Subqueries

-- استرجاع أسماء الأقسام التي تمتلك موظفين رواتبهم أقل من أو تساوي 210
SELECT Departments.Name 
FROM Departments 
WHERE ID IN (
    SELECT DepartmentID 
    FROM Employees 
    WHERE MonthlySalary <= 210 
);

-- استرجاع أسماء الأقسام التي لا يوجد بها أي موظف راتبه أقل من أو يساوي 210 باستخدام
-- NOT IN
SELECT Departments.Name 
FROM Departments 
WHERE ID NOT IN (
    SELECT DepartmentID 
    FROM Employees 
    WHERE MonthlySalary <= 210 
);
GO



-- ==============================================================================
-- 5. ترتيب النتائج
-- ORDER BY Keyword
-- ==============================================================================
-- يستخدم هذا الأمر لترتيب السجلات المسترجعة إما تصاعديا أو تنازليا
-- الترتيب الافتراضي يكون تصاعديا
-- ASC
-- للترتيب التنازلي نستخدم الكلمة المفتاحية
-- DESC

-- أمثلة عملية:

-- استرجاع بيانات القسم رقم 1 بدون ترتيب
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1;

-- ترتيب النتائج أبجديا حسب الاسم الأول (التصاعدي هو الافتراضي)
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName;

-- ترتيب النتائج أبجديا بشكل تصاعدي صريح
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName ASC;

-- ترتيب النتائج أبجديا بشكل تنازلي
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName DESC;

-- ترتيب النتائج حسب الراتب الشهري (تصاعدي افتراضي)
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1
ORDER BY MonthlySalary;

-- ترتيب النتائج حسب الراتب الشهري بشكل تصاعدي صريح
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1
ORDER BY MonthlySalary ASC;

-- ترتيب النتائج حسب الراتب الشهري بشكل تنازلي (من الأكبر للأصغر)
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1
ORDER BY MonthlySalary DESC;

-- الترتيب متعدد الأعمدة (ترتيب أبجدي للاسم، وإذا تطابق الاسم يرتب حسب الراتب تصاعديا)
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName, MonthlySalary;

-- الترتيب متعدد الأعمدة (ترتيب الاسم تصاعديا، والراتب تنازليا)
SELECT ID, FirstName, MonthlySalary 
FROM Employees
WHERE DepartmentID = 1
ORDER BY FirstName ASC, MonthlySalary DESC;


-- ==============================================================================
-- 6. تحديد عدد السجلات المسترجعة
-- SELECT TOP Clause
-- ==============================================================================
-- يستخدم هذا الأمر لتحديد عدد أو نسبة السجلات المطلوبة فقط بدلا من جلب كل البيانات
-- مفيد جدا لتحسين الأداء عند التعامل مع جداول ضخمة تحتوي على آلاف السجلات
-- ملاحظة: هذا الأمر خاص بخوادم مايكروسوفت (قواعد بيانات أخرى تستخدم قواعد مختلفة مثل)
-- LIMIT

-- أمثلة عملية:

-- استرجاع أول 5 موظفين فقط من الجدول
SELECT TOP 5 * 
FROM Employees;

-- استرجاع أول 10 بالمائة من إجمالي البيانات
SELECT TOP 10 PERCENT * 
FROM Employees;

-- استرجاع جميع الرواتب وترتيبها تنازليا (من الأكبر للأصغر)
SELECT MonthlySalary 
FROM Employees
ORDER BY MonthlySalary DESC;

-- استرجاع جميع الرواتب الفريدة (بدون تكرار) وترتيبها تنازليا
SELECT DISTINCT MonthlySalary 
FROM Employees
ORDER BY MonthlySalary DESC;

-- استرجاع أعلى 3 رواتب فريدة في الشركة
SELECT DISTINCT TOP 3 MonthlySalary 
FROM Employees
ORDER BY MonthlySalary DESC;

-- استخدام الاستعلام الفرعي لجلب بيانات الموظفين الذين يتقاضون واحدا من أعلى 3 رواتب
-- Subquery
SELECT ID, FirstName, MonthlySalary 
FROM Employees 
WHERE MonthlySalary IN (
    SELECT DISTINCT TOP 3 MonthlySalary 
    FROM Employees
    ORDER BY MonthlySalary DESC
)
ORDER BY MonthlySalary DESC;

-- استخدام الاستعلام الفرعي لجلب بيانات الموظفين الذين يتقاضون واحدا من أقل 3 رواتب
SELECT ID, FirstName, MonthlySalary 
FROM Employees 
WHERE MonthlySalary IN (
    SELECT DISTINCT TOP 3 MonthlySalary 
    FROM Employees
    ORDER BY MonthlySalary ASC
)
ORDER BY MonthlySalary ASC;
GO


-- ==============================================================================
-- 7. الأسماء المستعارة
-- SQL Aliases
-- ==============================================================================
-- الوصف: تستخدم الأسماء المستعارة لإعطاء اسم مؤقت لجدول أو عمود لتسهيل قراءته
-- الاسم المستعار يكون موجودا فقط أثناء تنفيذ الاستعلام ولا يغير اسم العمود الأصلي
-- يمكن إنشاء الاسم المستعار باستخدام الكلمة المفتاحية
-- AS
-- أو باستخدام علامة اليساوي

-- أمثلة عملية:

-- إجراء عمليات حسابية بسيطة وإعطاء أعمدة النتيجة أسماء مستعارة
SELECT A = 5 * 4, B = 6 / 2;

-- نفس العملية مع استرجاعها كأعمدة إضافية وهمية بجانب بيانات الجدول
SELECT A = 5 * 4, B = 6 / 2 
FROM Employees;

-- قسمة الراتب على 2 ووضع النتيجة في عمود مستعار اسمه A
SELECT ID, FirstName, A = MonthlySalary / 2 
FROM Employees;

-- دمج الاسم الأول والأخير في عمود واحد باستخدام الكلمة المفتاحية
-- AS
SELECT ID, FirstName + ' ' + LastName AS FullName 
FROM Employees;

-- نفس عملية الدمج السابقة ولكن باستخدام علامة اليساوي (طريقة مختصرة)
SELECT ID, FullName = FirstName + ' ' + LastName 
FROM Employees;

-- حساب الراتب السنوي بضرب الراتب الشهري في 12
SELECT ID, FirstName, MonthlySalary, YealySalary = MonthlySalary * 12 
FROM Employees;

-- استخراج أكثر من عمود مستعار في نفس الاستعلام (الراتب السنوي وقيمة المكافأة)
SELECT ID, 
       FirstName, 
       MonthlySalary, 
       YealySalary = MonthlySalary * 12, 
       BonusAmount = MonthlySalary * BonusPerc  
FROM Employees;

-- جلب تاريخ اليوم من النظام ووضعه في عمود مستعار
SELECT Today = GETDATE();

-- دمج دوال النصوص ودوال التواريخ لحساب العمر بناء على تاريخ الميلاد
SELECT ID, 
       FullName = FirstName + ' ' + LastName, 
       Age = DATEDIFF(YEAR, DateOfBirth, GETDATE()) 
FROM Employees;


-- ==============================================================================
-- 8. معامل النطاق
-- BETWEEN Operator
-- ==============================================================================
-- الوصف: يستخدم هذا المعامل لاسترجاع القيم التي تقع ضمن نطاق معين
-- النطاق المختار يتضمن نقطة البداية ونقطة النهاية (شامل للرقمين)
-- يمكن استخدامه مع الأرقام، النصوص، أو التواريخ

-- أمثلة عملية:

-- الطريقة القديمة والطويلة باستخدام المعاملات المنطقية لاسترجاع الرواتب من 500 إلى 1000
SELECT * FROM Employees 
WHERE MonthlySalary >= 500 AND MonthlySalary <= 1000;

-- الطريقة الاحترافية والمختصرة لنفس النتيجة باستخدام المعامل
-- BETWEEN
SELECT * FROM Employees 
WHERE MonthlySalary BETWEEN 500 AND 1000;


-- ==============================================================================
-- 9. الدوال التجميعية
-- Count, Sum, Avg, Min, Max Functions
-- ==============================================================================
-- الوصف: دوال مدمجة تقوم بإجراء عمليات حسابية على مجموعة من الصفوف لإرجاع قيمة واحدة

-- ترجع عدد الصفوف التي تطابق معيارا محددا
-- COUNT()
-- ترجع متوسط القيم لعمود رقمي
-- AVG()
-- ترجع إجمالي مجموع القيم لعمود رقمي
-- SUM()
-- ترجع أصغر قيمة في العمود
-- MIN()
-- ترجع أكبر قيمة في العمود
-- MAX()

-- أمثلة عملية:

-- تجميع كافة الإحصائيات للرواتب في الشركة بأكملها في استعلام واحد
SELECT TotalCount = COUNT(MonthlySalary), 
       TotalSum = SUM(MonthlySalary),
       Average = AVG(MonthlySalary),
       MinSalary = MIN(MonthlySalary),
       MaxSalary = MAX(MonthlySalary) 
FROM Employees;

-- تجميع نفس الإحصائيات ولكن لموظفي القسم رقم 1 فقط باستخدام شرط
SELECT TotalCount = COUNT(MonthlySalary), 
       TotalSum = SUM(MonthlySalary),
       Average = AVG(MonthlySalary),
       MinSalary = MIN(MonthlySalary),
       MaxSalary = MAX(MonthlySalary) 
FROM Employees 
WHERE DepartmentID = 1;

-- حساب إجمالي عدد الموظفين في الشركة بناء على المعرف الخاص بهم
SELECT TotalEmployees = COUNT(ID) 
FROM Employees;

-- ملاحظة هندسية دقيقة: دالة العدد تتجاهل دائما القيم الفارغة 
-- NULL
-- في المثال التالي، سيتم عد الموظفين المستقيلين فقط، لأن الموظف المستمر تاريخ استقالته فارغ
SELECT ResignedEmployees = COUNT(ExitDate) 
FROM Employees;
GO


-- ==============================================================================
-- 10. تجميع البيانات
-- GROUP BY Statement
-- ==============================================================================
-- الوصف: يستخدم هذا الأمر لتجميع الصفوف التي تحتوي على نفس القيم في صفوف ملخصة
-- مثال: إيجاد عدد العملاء في كل دولة
-- غالبا ما يتم استخدامه مع الدوال التجميعية لتجميع النتائج بناء على عمود أو أكثر
-- Aggregate Functions (COUNT, MAX, MIN, SUM, AVG)

-- الصيغة العامة: يكتب أمر التجميع بعد الجملة الشرطية وقبل أمر الترتيب
-- SELECT column_name FROM table_name WHERE condition GROUP BY column_name ORDER BY column_name;

-- أمثلة عملية:

-- تجميع كافة الإحصائيات للشركة بأكملها (بدون تجميع حسب عمود معين)
SELECT TotalCount = COUNT(MonthlySalary), 
       TotalSum = SUM(MonthlySalary),
       Average = AVG(MonthlySalary),
       MinSalary = MIN(MonthlySalary),
       MaxSalary = MAX(MonthlySalary) 
FROM Employees;

-- تجميع نفس الإحصائيات ولكن لموظفي القسم رقم 3 فقط
SELECT TotalCount = COUNT(MonthlySalary), 
       TotalSum = SUM(MonthlySalary),
       Average = AVG(MonthlySalary),
       MinSalary = MIN(MonthlySalary),
       MaxSalary = MAX(MonthlySalary) 
FROM Employees 
WHERE DepartmentID = 3;

-- الاستخدام الحقيقي للأمر: حساب الإحصائيات لكل قسم على حدة وعرض رقم القسم بجانب إحصائياته
SELECT DepartmentID, 
       TotalCount = COUNT(MonthlySalary), 
       TotalSum = SUM(MonthlySalary),
       Average = AVG(MonthlySalary),
       MinSalary = MIN(MonthlySalary),
       MaxSalary = MAX(MonthlySalary) 
FROM Employees
GROUP BY DepartmentID
ORDER BY DepartmentID;


-- ==============================================================================
-- 11. الجملة الشرطية للتجميع
-- HAVING Clause
-- ==============================================================================
-- الوصف: تمت إضافة هذه الكلمة المفتاحية لأن الجملة الشرطية العادية لا يمكن استخدامها مع الدوال التجميعية
-- WHERE
-- بعبارة أخرى، هي تمثل الجملة الشرطية الخاصة بعمليات التجميع
-- HAVING is the WHERE statement for GROUP BY

-- الصيغة العامة: تكتب بعد أمر التجميع لفلترة المجموعات
-- ... GROUP BY column_name HAVING condition ORDER BY ...

-- أمثلة عملية:

-- استرجاع إحصائيات الأقسام بشكل طبيعي
SELECT DepartmentID, 
       TotalCount = COUNT(MonthlySalary), 
       TotalSum = SUM(MonthlySalary),
       Average = AVG(MonthlySalary),
       MinSalary = MIN(MonthlySalary),
       MaxSalary = MAX(MonthlySalary) 
FROM Employees
GROUP BY DepartmentID
ORDER BY DepartmentID;

-- تطبيق الفلترة: استرجاع الأقسام التي يزيد عدد الرواتب (عدد الموظفين) فيها عن 100 فقط باستخدام
-- HAVING
SELECT DepartmentID, 
       TotalCount = COUNT(MonthlySalary), 
       TotalSum = SUM(MonthlySalary),
       Average = AVG(MonthlySalary),
       MinSalary = MIN(MonthlySalary),
       MaxSalary = MAX(MonthlySalary) 
FROM Employees
GROUP BY DepartmentID
HAVING COUNT(MonthlySalary) > 100;

-- حل هندسي بديل لنفس النتيجة السابقة باستخدام الاستعلامات الفرعية لتجنب استخدام
-- HAVING
SELECT * FROM (
    SELECT DepartmentID, 
           TotalCount = COUNT(MonthlySalary), 
           TotalSum = SUM(MonthlySalary),
           Average = AVG(MonthlySalary),
           MinSalary = MIN(MonthlySalary),
           MaxSalary = MAX(MonthlySalary) 
    FROM Employees
    GROUP BY DepartmentID
) R1
WHERE R1.TotalCount > 100;
GO




-- ==============================================================================
-- 12. معامل البحث عن نمط نصي
-- LIKE Operator
-- ==============================================================================
-- الوصف: يستخدم هذا المعامل داخل الجملة الشرطية للبحث عن نمط نصي محدد داخل عمود
-- WHERE
-- يكثر استخدامه مع الرموز التعبيرية للتعويض عن الأحرف
-- Wildcards
-- علامة النسبة المئوية تمثل صفر، حرف واحد، أو عدة أحرف
-- %
-- علامة الشرطة السفلية تمثل حرفا واحدا فقط في نفس المكان
-- _

-- أمثلة عملية:

-- استرجاع كافة الموظفين للبدء
SELECT * FROM Employees;

-- البحث عن أي اسم يبدأ بحرف 
-- a
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE 'a%';

-- البحث عن أي اسم ينتهي بحرف 
-- a
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE '%a';

-- البحث عن أي اسم يحتوي على المقطع التالي في أي مكان
-- tell
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE '%tell%';

-- البحث عن أي اسم يبدأ وينتهي بحرف
-- a
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE 'a%a';

-- البحث عن أي اسم يحتوي على حرف معين كحرف ثاني (شرطة سفلية واحدة في البداية)
-- a
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE '_a%';

-- البحث عن أي اسم يحتوي على حرف معين كحرف ثالث (شرطتين في البداية)
-- a
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE '__a%';

-- البحث عن اسم يبدأ بحرف معين ويتكون من 3 أحرف على الأقل (حرف البداية + شرطتين + نسبة مئوية)
-- a__%
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE 'a__%';

-- البحث عن اسم يبدأ بحرف معين ويتكون من 4 أحرف على الأقل 
-- a___%
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE 'a___%';

-- دمج أكثر من نمط باستخدام 
-- OR
-- البحث عن أسماء تبدأ بحرف a أو b
SELECT ID, FirstName FROM Employees
WHERE FirstName LIKE 'a%' OR FirstName LIKE 'b%';


-- ==============================================================================
-- 13. الرموز التعبيرية المتقدمة
-- SQL Wildcard Characters
-- ==============================================================================
-- الوصف: تستخدم هذه الرموز لتمثيل حرف أو أكثر في النصوص، وتعمل دائما مع المعامل
-- LIKE
-- الأقواس المربعة تمثل أي حرف مفرد موجود بداخلها
-- []
-- علامة الأس (أو الثمانية) تمثل أي حرف مفرد غير موجود داخل الأقواس (للنفي)
-- ^
-- علامة الشرطة تمثل أي حرف مفرد ضمن النطاق الأبجدي المحدد
-- -

-- أمثلة عملية للتحديث (لتجهيز البيانات للاختبار):
-- UPDATE Employees SET FirstName = 'Mohammed', LastName = 'Abu-Hadhoud' WHERE ID = 285;
-- UPDATE Employees SET FirstName = 'Mohammad', LastName = 'Maher' WHERE ID = 286;

-- الطريقة القديمة للبحث عن اسمين يختلفان في حرف واحد باستخدام
-- OR
SELECT ID, FirstName, LastName FROM Employees
WHERE FirstName = 'Mohammed' OR FirstName = 'Mohammad';

-- الطريقة الاحترافية والمختصرة باستخدام الأقواس المربعة 
-- سيبحث عن تطابق الاسم سواء كان الحرف قبل الأخير e أو a
SELECT ID, FirstName, LastName FROM Employees
WHERE FirstName LIKE 'Mohamm[ae]d';

-- يمكن نفي النمط السابق لاسترجاع الأسماء التي لا تتطابق باستخدام
-- NOT LIKE
SELECT ID, FirstName, LastName FROM Employees
WHERE FirstName NOT LIKE 'Mohamm[ae]d';

-- الطريقة القديمة للبحث عن أسماء تبدأ بحروف متعددة محددة
SELECT ID, FirstName, LastName FROM Employees
WHERE FirstName LIKE 'a%' OR FirstName LIKE 'b%' OR FirstName LIKE 'c%';

-- الطريقة الاحترافية لاسترجاع الموظفين الذين تبدأ أسماؤهم بأحد الحروف a أو b أو c
SELECT ID, FirstName, LastName FROM Employees
WHERE FirstName LIKE '[abc]%';

-- البحث باستخدام نطاق الحروف (من a إلى l)
-- سيسترجع كل الأسماء التي تبدأ بأي حرف يقع ضمن هذا النطاق الأبجدي
SELECT ID, FirstName, LastName FROM Employees
WHERE FirstName LIKE '[a-l]%';
GO
































