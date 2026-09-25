-- ==============================================================================
-- 1. ربط الجداول الأساسي
-- SQL INNER JOIN
-- ==============================================================================
-- الوصف: تستخدم جملة الربط لدمج صفوف من جدولين أو أكثر بناء على عمود مشترك بينهما
-- JOIN
-- يقوم الربط الداخلي باسترجاع السجلات التي تمتلك قيما متطابقة في كلا الجدولين فقط
-- INNER JOIN
-- هندسيا، يمثل هذا النوع منطقة التقاطع الدقيقة بين الجدولين 
--
-- ملاحظة هامة: في بيئة قواعد البيانات، استخدام الكلمة المفتاحية
-- JOIN
-- يعادل تماما استخدام الكلمة المفتاحية
-- INNER JOIN

-- الصيغة العامة:
-- SELECT columns FROM table1 INNER JOIN table2 ON table1.column_name = table2.column_name;

-- ==============================================================================
-- أمثلة توضيحية (جدول العملاء والطلبات)
-- ==============================================================================

-- استرجاع بيانات العملاء المرتبطة بطلبات فعلية فقط
-- يتم الربط بناء على تطابق رقم العميل في كلا الجدولين
--
SELECT Customers.customer_id, Customers.first_name, Orders.amount
FROM Customers
INNER JOIN Orders
ON Customers.customer_id = Orders.customer;

-- نفس الاستعلام السابق مع إضافة جملة شرطية لتصفية الطلبات التي تزيد قيمتها عن 500
-- WHERE
SELECT Customers.customer_id, Customers.first_name, Orders.amount
FROM Customers
INNER JOIN Orders
ON Customers.customer_id = Orders.customer
WHERE Orders.amount >= 500;

-- ==============================================================================
-- أمثلة عملية متقدمة (قاعدة بيانات الموارد البشرية)
-- HR Database
-- ==============================================================================

-- 1. الربط بين جدولين (الموظفين والأقسام) لجلب اسم القسم بجانب بيانات الموظف
SELECT Employees.ID, 
       Employees.FirstName, 
       Employees.LastName, 
       Departments.Name AS DeptName
FROM Employees 
INNER JOIN Departments 
ON Employees.DepartmentID = Departments.ID;

-- 2. الربط بين جدولين مع استخدام فلتر لاسترجاع موظفي قسم تكنولوجيا المعلومات فقط
SELECT Employees.ID, 
       Employees.FirstName, 
       Employees.LastName, 
       Departments.Name AS DeptName
FROM Employees 
INNER JOIN Departments 
ON Employees.DepartmentID = Departments.ID
WHERE Departments.Name = 'IT';

-- 3. الربط بين ثلاثة جداول (الموظفين، الأقسام، الدول) لجلب كافة تفاصيل الموظف
-- يتم تسلسل جمل الربط تباعا لكل جدول جديد
SELECT Employees.ID, 
       Employees.FirstName, 
       Employees.LastName, 
       Departments.Name AS DeptName, 
       Countries.Name AS CountryName
FROM Employees 
INNER JOIN Departments 
ON Employees.DepartmentID = Departments.ID 
INNER JOIN Countries 
ON Employees.CountryID = Countries.ID;

-- 4. الربط بين ثلاثة جداول مع تصفية النتائج لموظفي الولايات المتحدة فقط
SELECT Employees.ID, 
       Employees.FirstName, 
       Employees.LastName, 
       Departments.Name AS DeptName, 
       Countries.Name AS CountryName
FROM Employees 
INNER JOIN Departments 
ON Employees.DepartmentID = Departments.ID 
INNER JOIN Countries 
ON Employees.CountryID = Countries.ID
WHERE Countries.Name = 'USA';
GO


-- ==============================================================================
-- 2. الربط الأيسر (الخارجي)
-- LEFT JOIN / LEFT OUTER JOIN
-- ==============================================================================
-- الوصف: يقوم الربط الأيسر باسترجاع كافة السجلات من الجدول الأول (الأيسر)
-- Table 1
-- بالإضافة إلى السجلات المتطابقة فقط من الجدول الثاني (الأيمن)
-- Table 2
-- في حال عدم وجود تطابق في الجدول الأيمن، ستظهر قيم الأعمدة فارغة
-- NULL
-- هندسيا، يمثل هذا النوع الدائرة اليسرى بالكامل في مخططات التقاطع مضافا إليها منطقة التقاطع
-- Venn Diagram
-- ملاحظة هامة: في بيئة قواعد البيانات، استخدام الكلمة المفتاحية
-- LEFT JOIN
-- يعادل تماما استخدام الكلمة المفتاحية
-- LEFT OUTER JOIN

-- الصيغة العامة:
-- SELECT columns FROM table1 LEFT JOIN table2 ON table1.column_name = table2.column_name;

-- ==============================================================================
-- أمثلة عملية (جدول العملاء والطلبات)
-- ==============================================================================

-- استرجاع جميع العملاء بلا استثناء، سواء كانت لديهم طلبات مسجلة أم لا
-- سيتم جلب بيانات الطلب للعميل المطابق، وإذا لم يمتلك العميل أي طلبات ستظهر قيمة الطلب فارغة
-- NULL
SELECT Customers.CustomerID, 
       Customers.Name, 
       Orders.Amount
FROM Customers 
LEFT JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;

-- نفس الاستعلام السابق تماما باستخدام الصيغة البديلة (الخارجية)
-- النتيجة متطابقة 100% ولا يوجد أي فرق في الأداء أو المخرجات
SELECT Customers.CustomerID, 
       Customers.Name, 
       Orders.Amount
FROM Customers 
LEFT OUTER JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;
GO


-- ==============================================================================
-- 3. الربط الأيمن (الخارجي)
-- RIGHT JOIN / RIGHT OUTER JOIN
-- ==============================================================================
-- الوصف: يقوم الربط الأيمن باسترجاع كافة السجلات من الجدول الثاني (الأيمن)
-- Table 2
-- بالإضافة إلى السجلات المتطابقة فقط من الجدول الأول (الأيسر)
-- Table 1
-- في حال عدم وجود تطابق في الجدول الأيسر، ستظهر قيم الأعمدة فارغة
-- NULL
-- هندسيا، يمثل هذا النوع الدائرة اليمنى بالكامل في مخططات التقاطع مضافا إليها منطقة التقاطع
-- Venn Diagram
-- ملاحظة هامة: في بيئة قواعد البيانات، استخدام الكلمة المفتاحية
-- RIGHT JOIN
-- يعادل تماما استخدام الكلمة المفتاحية
-- RIGHT OUTER JOIN

-- الصيغة العامة:
-- SELECT columns FROM table1 RIGHT JOIN table2 ON table1.column_name = table2.column_name;

-- ==============================================================================
-- 4. الربط الخارجي الكامل
-- FULL JOIN / FULL OUTER JOIN
-- ==============================================================================
-- الوصف: يقوم الربط الكامل باسترجاع كافة السجلات من كلا الجدولين (الأيمن والأيسر)
-- Table 1 & Table 2
-- يتم دمج السجلات المتطابقة في صفوف واحدة، أما السجلات غير المتطابقة في أي من الجدولين
-- فستظهر قيم الأعمدة المقابلة لها فارغة
-- NULL
-- هندسيا، يمثل هذا النوع دمج الدائرتين بالكامل (منطقة التقاطع زائد المناطق المستقلة)
-- احذر: الربط الكامل بين جداول ضخمة قد ينتج عنه مجموعة بيانات عملاقة تستهلك موارد السيرفر
-- ملاحظة هامة: في بيئة قواعد البيانات، استخدام الكلمة المفتاحية
-- FULL JOIN
-- يعادل تماما استخدام الكلمة المفتاحية
-- FULL OUTER JOIN

-- الصيغة العامة:
-- SELECT columns FROM table1 FULL OUTER JOIN table2 ON table1.column_name = table2.column_name;

-- ==============================================================================
-- أمثلة عملية للمقارنة (جدول العملاء والطلبات)
-- ==============================================================================

-- 1. الربط الداخلي (التقاطع فقط)
SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM Customers 
INNER JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;

-- 2. الربط الأيسر (العملاء كاملين + الطلبات المتطابقة)
SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM Customers 
LEFT OUTER JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;

-- 3. الربط الأيمن (الطلبات كاملة + العملاء المتطابقين)
SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM Customers 
RIGHT OUTER JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;

-- 4. الربط الكامل (جميع العملاء وجميع الطلبات مدمجة)
SELECT Customers.CustomerID, Customers.Name, Orders.Amount
FROM Customers 
FULL OUTER JOIN Orders 
ON Customers.CustomerID = Orders.CustomerID;
GO





