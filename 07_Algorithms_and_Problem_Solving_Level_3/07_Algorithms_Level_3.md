<div dir="rtl">

# كورس 07: الخوارزميات وحل المشاكل - المستوى الثالث

# Algorithms & Problem Solving Level 3

### في هذا الكورس، ننتقل إلى مستوى متقدم من التفكير المنطقي (Logic) مع التركيز المكثف على الـ Matrices (المصفوفات ثنائية الأبعاد - 2D Arrays).

## 🧩 Problem #01: 3x3 Random Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3، وتعبئة جميع عناصرها بأرقام عشوائية (Random Numbers) تتراوح بين 1 و 100، ثم طباعتها على الشاشة بشكل مرتب.

### 💡 الفكرة البرمجية (Logic Breakdown)

• المصفوفة ثنائية الأبعاد (2D Array): تُعرّف كالتالي int matrix[3][3].

• التعبئة (Filling): للوصول إلى كل خلية داخل الـ Matrix، نستخدم Nested Loops (حلقات متداخلة).

• الحلقة الخارجية (Outer Loop) تمر على الـ Rows (الصفوف).

• الحلقة الداخلية (Inner Loop) تمر على الـ Columns (الأعمدة).

• التوليد العشوائي (Random Generation): نستخدم دالة تعتمد على rand() مع عمل srand() مرة واحدة فقط داخل الـ main.

### 💻 الكود المعتمد (Solution)

• تم دمج أفضل ما في حل المستخدم وحل الدكتور (إزالة الدوال غير المستخدمة، مع الاحتفاظ بالتنسيق الجمالي للمستخدم).

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Function to generate a random number within a specific range
int RandomNumber(int From, int To)
{
int randNum = rand() % (To - From + 1) + From;
return randNum;
}

// Function to fill the Matrix using Nested Loops
void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
for (short i = 0; i < rows; i++)
{
for (short j = 0; j < cols; j++)
{
matrix[i][j] = RandomNumber(1, 100);
}
}
}

// Function to print the Matrix with formatting
void PrintMatrix(int matrix[3][3], short rows, short cols)
{
cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
for (short i = 0; i < rows; i++)
{
for (short j = 0; j < cols; j++)
{
// setw(3) ensures alignment of columns regardless of number digits
cout << "\t" << setw(3) << matrix[i][j];
}
cout << endl;
}
}

int main()
{
// Seeds the random number generator in C++, called only once
srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #01 : Fill a 3x3 Matrix with Random Numbers";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;

}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• تم استخدام Data Type من نوع short لعدادات الـ Loops (i و j) لتقليل استهلاك الـ Memory كوننا نتعامل مع أحجام صغيرة جداً (3 صفوف فقط).

• الدالة setw(3) من مكتبة <iomanip> تعتبر الـ Best Practice لضمان ظهور الـ Matrix بشكل هندسي سليم، حيث تحجز 3 خانات لكل رقم، مما يمنع تشوه الأعمدة إذا اختلفت عدد الخانات (مثلاً رقم 9 بجوار رقم 100).

## 🧩 Problem #02: Sum Each Row In Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3 وتعبئتها بأرقام عشوائية (كما فعلنا في المسألة الأولى)، ثم يقوم بحساب المجموع (Sum) لكل صف (Row) على حدة، ويطبع مجاميع الصفوف مرتبة على الشاشة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• إعادة الاستخدام (Reusability): سنقوم بإعادة استخدام نفس الـ Functions السابقة الخاصة بتوليد الأرقام العشوائية وطباعة الـ Matrix.

• حساب مجموع الصف (Row Sum Logic): \* نُنشئ Function تستقبل الـ Matrix، ورقم الصف المطلوب (RowNumber).

• نقوم بتثبيت الـ RowNumber، ونمرر حلقة تكرار (Loop) على الأعمدة (Columns) الخاصة بهذا الصف فقط لجمع قيمها.

• طباعة المجاميع: ننشئ Function أخرى تمر بحلقة تكرار على جميع الـ Rows، وفي كل لفة تستدعي دالة المجموع وتطبع الناتج.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to calculate the sum of a specific row
int RowSum(int matrix[3][3], short rowNumber, short cols)
{
    int sum = 0;
    // Notice that 'rowNumber' is fixed, we only iterate over 'j' (Columns)
    for (short j = 0; j < cols; j++)
    {
        sum += matrix[rowNumber][j];
    }
    return sum;
}

// Function to print the sum of each row
void PrintEachRowSum(int matrix[3][3], short rows, short cols)
{
    cout << "\nThe Following are the sums of each row in the matrix:\n\n";
    for (short i = 0; i < rows; i++)
    {
        // Calling RowSum for each specific row 'i'
        cout << "\tRow " << i + 1 << " Sum = " << RowSum(matrix, i, cols) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #02 : Sum Each Row in Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    PrintEachRowSum(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Single Responsibility Principle (SRP): في هذا الحل، قمنا بفصل الـ Logic بذكاء. دالة RowSum مسؤولة فقط عن الحساب (Calculation)، ودالة PrintEachRowSum مسؤولة فقط عن الطباعة (Printing). هذا الفصل يسهل جداً عملية صيانة الكود لاحقاً وإعادة استخدامه.

• Time Complexity: الأداء هنا ممتاز ومثالي $O(R \times C)$، حيث تمر الـ Loops على كل عنصر في المصفوفة مرة واحدة للتعبئة، ومرة واحدة للحساب.

## 🧩 Problem #03: Sum Matrix Rows in Array

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3 وتعبئتها بأرقام عشوائية، ثم يقوم بحساب المجموع لكل صف وتخزين هذا المجموع في مصفوفة أحادية (1D Array) منفصلة، وأخيراً طباعة محتويات هذه المصفوفة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• مصفوفة أحادية (1D Array): نُعرف مصفوفة عادية بحجم 3 لتخزين نواتج الجمع لكل صف.

• تخزين المجاميع: نُنشئ Function تمر على صفوف الـ Matrix، وفي كل لفة تستدعي دالة RowSum وتُخزن الناتج في الـ Index المقابل في المصفوفة الأحادية.

• الطباعة: نُنشئ Function بسيطة للمرور على المصفوفة الأحادية وطباعة محتوياتها.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int RowSum(int matrix[3][3], short rowNumber, short cols)
{
    int sum = 0;
    for (short j = 0; j < cols; j++)
    {
        sum += matrix[rowNumber][j];
    }
    return sum;
}

// Function to calculate rows sum and store them in a 1D Array
void SumMatrixRowsInArray(int matrix[3][3], int rowsSum[3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        // Store the sum of row 'i' into the array at index 'i'
        rowsSum[i] = RowSum(matrix, i, cols);
    }
}

// Function to print the 1D Array
void PrintRowsSumArray(int rowsSum[3], short rows)
{
    cout << "\nThe Following are the sums of each row in the matrix:\n\n";
    for (short i = 0; i < rows; i++)
    {
        cout << "\tRow " << i + 1 << " Sum = " << rowsSum[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #03 : Sum Matrix Rows in Array";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];
    int rowsSum[3]; // 1D Array to hold the sums

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    SumMatrixRowsInArray(matrix, rowsSum, 3, 3);
    PrintRowsSumArray(rowsSum, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• فصل البيانات (Separation of Data): تخزين البيانات المُعالجة (المجاميع) في Data Structure منفصلة (المصفوفة الأحادية) بدلاً من طباعتها مباشرة يُعتبر من أفضل الممارسات، لأنه يسمح لك باستخدام هذه المجاميع لاحقاً في عمليات حسابية أخرى داخل البرنامج بدون الحاجة لإعادة حسابها.

## 🧩 Problem #04: Sum Each Column In Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3 وتعبئتها بأرقام عشوائية، ثم يقوم بحساب المجموع لكل عمود (Column) على حدة، ويطبع مجاميع الأعمدة مرتبة على الشاشة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• التفكير المعكوس (Inverted Logic): لحساب مجموع العمود، نثبت رقم العمود (Column Number) ونجعل حلقة التكرار (Loop) تمر على الصفوف (Rows).

• في دالة ColSum، المتغير الذي يزداد في حلقة التكرار هو المتغير الخاص بالصفوف (i)، بينما يظل متغير الأعمدة ثابتاً.

💻 الكود المعتمد (Solution)

```cpp
<div dir="ltr">

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to calculate the sum of a specific column
int ColSum(int matrix[3][3], short rows, short colNumber)
{
    int sum = 0;
    // Notice that 'colNumber' is fixed, we only iterate over 'i' (Rows)
    for (short i = 0; i < rows; i++)
    {
        sum += matrix[i][colNumber];
    }
    return sum;
}

// Function to print the sum of each column
void PrintEachColSum(int matrix[3][3], short rows, short cols)
{
    cout << "\nThe Following are the sums of each column in the matrix:\n\n";
    for (short j = 0; j < cols; j++)
    {
        // Calling ColSum for each specific column 'j'
        cout << "\tCol " << j + 1 << " Sum = " << ColSum(matrix, rows, j) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #04 : Sum Each Column in Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);
    PrintEachColSum(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• الوصول للأعمدة (Column Access): في المصفوفة ثنائية الأبعاد، الوصول لعناصر العمود الواحد يتطلب القفز في الذاكرة (لأن العناصر تُخزن صفاً بصف)، ولذلك قمنا بتثبيت الفهرس الثاني matrix[i][colNumber] وتحريك الفهرس الأول i للمرور عمودياً.

## 🧩 Problem #05: Sum Matrix Columns in Array

### 📝 وصف المشكلة (Problem Description)

المطلوب حساب مجموع كل عمود في الـ Matrix وتخزين هذه المجاميع في مصفوفة أحادية (1D Array) منفصلة، ثم طباعة محتوياتها على الشاشة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• تجميع الأفكار: ندمج فكرة تخزين البيانات في مصفوفة أحادية (من المسألة 3) مع فكرة حساب مجموع الأعمدة (من المسألة 4).

• نُنشئ مصفوفة أحادية بحجم 3، ونمرر حلقة تكرار على الأعمدة، وفي كل لفة نحسب المجموع (باستخدام ColSum) ونضعه في الـ Index المقابل في المصفوفة الأحادية.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Random Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int ColSum(int matrix[3][3], short rows, short colNumber)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        sum += matrix[i][colNumber];
    }
    return sum;
}

// Function to calculate columns sum and store them in a 1D Array
void SumMatrixColsInArray(int matrix[3][3], int colsSum[3], short rows, short cols)
{
    for (short j = 0; j < cols; j++)
    {
        // Store the sum of column 'j' into the array at index 'j'
        colsSum[j] = ColSum(matrix, rows, j);
    }
}

// Function to print the 1D Array
void PrintColsSumArray(int colsSum[3], short cols)
{
    cout << "\nThe Following are the sums of each column in the matrix:\n\n";
    for (short i = 0; i < cols; i++)
    {
        cout << "\tCol " << i + 1 << " Sum = " << colsSum[i] << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #05 : Sum Matrix Columns in Array";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];
    int colsSum[3]; // 1D Array to hold the sums

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    SumMatrixColsInArray(matrix, colsSum, 3, 3);
    PrintColsSumArray(colsSum, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• إعادة الاستخدام (Code Reusability): لاحظ كيف أننا استخدمنا نفس دالة ColSum التي كتبناها في المسألة السابقة دون أي تعديل، فقط قمنا بتغيير المكان الذي نضع فيه الناتج. هذا هو جوهر كتابة كود نظيف وقابل للتوسع والصيانة بسهولة.

## 🧩 Problem #06: 3x3 Ordered Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بإنشاء Matrix بحجم 3x3، وتعبئة عناصرها بأرقام تسلسلية مرتبة (Ordered Numbers) من 1 إلى 9، ثم طباعتها على الشاشة بشكل مرتب.

### 💡 الفكرة البرمجية (Logic Breakdown)

• تعريف عداد (Counter): نقوم بإنشاء متغير بسيط ونعطيه قيمة ابتدائية 1.

• التعبئة (Filling): باستخدام حلقات التكرار المتداخلة (Nested Loops)، نمر على كل عنصر في المصفوفة، ونسند إليه قيمة العداد الحالي، ثم نزيد العداد بمقدار 1 للخطوة التالية.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

// Function to fill the Matrix with ordered numbers (1, 2, 3...)
void FillMatrixWithOrderedNumbers(int matrix[3][3], short rows, short cols)
{
    short counter = 1;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = counter++;
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    cout << "The Following is a " << rows << "x" << cols << " Matrix filled with Ordered Numbers:\n\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #06 : Fill a 3x3 Matrix with Ordered Numbers";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithOrderedNumbers(matrix, 3, 3);
    PrintMatrix(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Post-Increment Operator (counter++): استخدام معامل الزيادة اللاحقة يسمح لنا بوضع القيمة الحالية للعداد داخل المصفوفة، ثم زيادة العداد بمقدار 1 في نفس السطر. هذا يجعل الكود أنظف وأقصر.

## 🧩 Problem #07: Transpose Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لإنشاء مصفوفة مرتبة (كما في المسألة السابقة) وطباعتها. ثم يتم عمل منقول (Transpose) لهذه المصفوفة وحفظه في مصفوفة أخرى وطباعة المصفوفة الناتجة.

### 💡 الفكرة البرمجية (Logic Breakdown)

• مفهوم الـ Transpose: منقول المصفوفة رياضياً يعني تحويل الصفوف إلى أعمدة، والأعمدة إلى صفوف.

• طريقة التنفيذ: في حلقات التكرار المتداخلة، نقوم بنسخ العنصر الموجود في الصف i والعمود j من المصفوفة الأصلية، ونضعه في الصف j والعمود i في المصفوفة الجديدة. أي أن transposedMatrix[i][j] = matrix[j][i].

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int matrix[3][3], short rows, short cols)
{
    short counter = 1;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = counter++;
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to transpose the matrix
void TransposeMatrix(int matrix[3][3], int transposedMatrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            // Swap the indices to transpose
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #07 : Transpose a 3x3 Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];
    int transposedMatrix[3][3];

    // Execution
    FillMatrixWithOrderedNumbers(matrix, 3, 3);

    cout << "The Following is the Original Matrix:\n\n";
    PrintMatrix(matrix, 3, 3);

    TransposeMatrix(matrix, transposedMatrix, 3, 3);

    cout << "\nThe Following is the Transposed Matrix:\n\n";
    PrintMatrix(transposedMatrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Index Manipulation: التلاعب بمؤشرات المصفوفات (i و j) هو جوهر التعامل مع الـ Data Structures. عكس الفهارس هنا حقق عملية رياضية معقدة بكود بسيط جداً وبدون استخدام دوال مساعدة إضافية.

## 🧩 Problem #08: Multiply Two Matrices

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لتعبئة مصفوفتين 3x3 بأرقام عشوائية من 1 إلى 10 وطباعتهما، ثم ضرب كل عنصر في المصفوفة الأولى مع العنصر المقابل له في المصفوفة الثانية وحفظ النتيجة في مصفوفة ثالثة وطباعتها.

### 💡 الفكرة البرمجية (Logic Breakdown)

• التعبئة والضرب: نستخدم نفس اللوجيك السابق لإنشاء مصفوفتين وتعبئتهما عشوائياً.

• عملية الضرب المباشر: نمر بحلقات التكرار على المصفوفتين، وفي كل دورة نقوم بضرب العنصر [i][j] من الأولى بالعنصر [i][j] من الثانية، ونخزن الناتج في المصفوفة الثالثة.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to multiply two matrices element by element
void MultiplyMatrix(int matrix1[3][3], int matrix2[3][3], int resultMatrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #08 : Multiply Two Matrices Element by Element";
    cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3], matrix2[3][3], resultMatrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    FillMatrixWithRandomNumbers(matrix2, 3, 3);

    cout << "The First Matrix:\n\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "\nThe Second Matrix:\n\n";
    PrintMatrix(matrix2, 3, 3);

    MultiplyMatrix(matrix1, matrix2, resultMatrix, 3, 3);

    cout << "\nThe Result Matrix (Matrix1 * Matrix2):\n\n";
    PrintMatrix(resultMatrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Element-wise Multiplication: لاحظ أن هذا الضرب هو ضرب مباشر للعناصر المتقابلة (Element-wise) وليس الضرب الرياضي المتقدم للمصفوفات (Matrix Multiplication). وهذا مثالي جداً في تطبيقات تعديل الصور (Image Masks) ومؤثرات الرؤية الرقمية.

## 🧩 Problem #09: Print Middle Row and Col of Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لتعبئة مصفوفة 3x3 بأرقام عشوائية، وطباعتها. ثم استخراج وطباعة عناصر الصف الأوسط (Middle Row) والعمود الأوسط (Middle Column) بشكل مستقل.

### 💡 الفكرة البرمجية (Logic Breakdown)

• حساب نقطة المنتصف: المصفوفة حجمها 3x3 (فهارسها: 0, 1, 2). بقسمة حجم الصفوف أو الأعمدة على 2 (3/2)، نحصل على الرقم 1 (بحكم أن نوع البيانات Integer يحذف الكسر)، وهذا هو فهرس المنتصف تماماً.

• طباعة الصف الأوسط: نثبت الفهرس الأول (الخاص بالصفوف) عند المنتصف، ونغير الفهرس الثاني بحلقة تكرار لطباعة الأعمدة.

• طباعة العمود الأوسط: نثبت الفهرس الثاني (الخاص بالأعمدة) عند المنتصف، ونغير الفهرس الأول بحلقة تكرار لطباعة الصفوف.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to print the middle row
void PrintMiddleRow(int matrix[3][3], short rows, short cols)
{
    short middleRowIndex = rows / 2;
    cout << "The Middle Row is    : ";
    for (short j = 0; j < cols; j++)
    {
        cout << setw(3) << matrix[middleRowIndex][j] << "  ";
    }
    cout << endl;
}

// Function to print the middle column
void PrintMiddleCol(int matrix[3][3], short rows, short cols)
{
    short middleColIndex = cols / 2;
    cout << "The Middle Column is : ";
    for (short i = 0; i < rows; i++)
    {
        cout << setw(3) << matrix[i][middleColIndex] << "  ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #09 : Print Middle Row and Col of Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);

    cout << "The Following is a 3x3 Matrix:\n\n";
    PrintMatrix(matrix, 3, 3);

    cout << "\n";
    PrintMiddleRow(matrix, 3, 3);
    PrintMiddleCol(matrix, 3, 3);

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Integer Division: الاستفادة من ميزة قسمة الـ Integers (بإهمال الكسور) هي طريقة ممتازة لتحديد نقطة ارتكاز (Center Point) في أي هيكل بيانات فردي الحجم دون الحاجة لكتابة كود معقد للتقريب.

## 🧩 Problem #10: Sum of Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لإنشاء مصفوفة 3x3 عشوائية وطباعتها، ثم حساب المجموع الكلي (Sum) لجميع العناصر الموجودة بداخل هذه المصفوفة وطباعته.

### 💡 الفكرة البرمجية (Logic Breakdown)

• المُجمّع (Accumulator): نقوم بإنشاء متغير بسيط sum = 0 ونضعه خارج حلقات التكرار.

• المرور والتجميع: نستخدم حلقتي تكرار متداخلتين للمرور على كل عنصر في المصفوفة، وفي كل دورة نقوم بجمع قيمة العنصر الحالي وإضافتها إلى المتغير sum.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to calculate the sum of all elements in the matrix
int SumOfMatrix(int matrix[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #10 : Sum of All Numbers in Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix[3][3];

    // Execution
    FillMatrixWithRandomNumbers(matrix, 3, 3);

    cout << "The Following is a 3x3 Matrix:\n\n";
    PrintMatrix(matrix, 3, 3);

    int totalSum = SumOfMatrix(matrix, 3, 3);
    cout << "\nThe Sum of all numbers in the matrix is : " << totalSum << endl;

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• Time Complexity: حساب مجموع كامل المصفوفة يتطلب المرور على كل العناصر دفعة واحدة، مما يجعل الأداء $O(R \times C)$ وهو الأداء الطبيعي والأمثل لهذه العملية.

## 🧩 Problem #11: Check Matrices Equality

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بمقارنة مصفوفتين للتأكد مما إذا كانتا متساويتين (Equal) أم لا. في هذا السياق (حسب حل الدكتور)، المساواة تعني أن المجموع الكلي لعناصر المصفوفة الأولى يساوي المجموع الكلي لعناصر المصفوفة الثانية.

### 💡 الفكرة البرمجية (Logic Breakdown)

• حساب مجموع المصفوفة الأولى باستخدام دالة SumOfMatrix التي قمنا ببنائها في المسألة السابقة.

• حساب مجموع المصفوفة الثانية باستخدام نفس الدالة.

• مقارنة المجموعين، وإرجاع قيمة منطقية (true أو false).

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
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

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int SumOfMatrix(int matrix[3][3], short rows, short cols)
{
    int sum = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Function to check if matrices are equal (by comparing their sums)
bool AreEqualMatrices(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
    return SumOfMatrix(matrix1, rows, cols) == SumOfMatrix(matrix2, rows, cols);
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #11 : Check Matrices Equality (By Sum)";
    cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3], matrix2[3][3];

    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    FillMatrixWithRandomNumbers(matrix2, 3, 3);

    cout << "Matrix 1: \n\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "\nMatrix 2: \n\n";
    PrintMatrix(matrix2, 3, 3);

    if (AreEqualMatrices(matrix1, matrix2, 3, 3))
    {
        cout << "\nYES: Both matrices are equal.\n";
    }
    else
    {
        cout << "\nNo: Matrices are NOT equal.\n";
    }

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• إعادة الاستخدام (Code Reusability): استخدام دالة حساب المجموع الجاهزة يختصر الكود ويجعله مقروءاً جداً، فبدلاً من كتابة اللوجيك مرة أخرى، استطعنا مقارنة المصفوفتين في سطر كود واحد فقط.

## 🧩 Problem #12: Check Typical Matrices

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لمقارنة مصفوفتين للتأكد مما إذا كانتا متطابقتين تماماً (Typical)، أي أن كل عنصر في المصفوفة الأولى يساوي العنصر المقابل له في المصفوفة الثانية بالملي.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نمر بحلقات تكرار متداخلة على كلا المصفوفتين في نفس الوقت.

• نقارن كل عنصر [i][j] من المصفوفة الأولى مع نظيره [i][j] من الثانية.

• بمجرد العثور على اختلاف واحد فقط، نخرج من الدالة فوراً بإرجاع false، مما يوفر وقت المعالجة.

• إذا انتهت الحلقات دون العثور على أي اختلاف، نرجع true في النهاية.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to check if matrices are exactly the same element by element
bool AreTypicalMatrices(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return false; // Exit immediately if any mismatch is found
            }
        }
    }
    return true; // If loops finish without mismatch, they are typical
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "\n-------------------------------------------------\n";
    cout << "Problem #12 : Check Typical Matrices";
    cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3], matrix2[3][3];

    FillMatrixWithRandomNumbers(matrix1, 3, 3);
    FillMatrixWithRandomNumbers(matrix2, 3, 3);

    cout << "Matrix 1: \n\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "\nMatrix 2: \n\n";
    PrintMatrix(matrix2, 3, 3);

    if (AreTypicalMatrices(matrix1, matrix2, 3, 3))
    {
        cout << "\nYES: Both matrices are typical.\n";
    }
    else
    {
        cout << "\nNo: Matrices are NOT typical.\n";
    }

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• الأداء (Early Return): فكرة الخروج المبكر (return false) بمجرد إيجاد أول اختلاف تعتبر من أقوى الممارسات الهندسية، لأنها تمنع البرنامج من إكمال حلقات التكرار وفحص باقي العناصر بلا فائدة إذا كان الشرط قد سقط بالفعل.

## 🧩 Problem #13: Check Identity Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج للتحقق مما إذا كانت المصفوفة هي مصفوفة الوحدة (Identity Matrix). مصفوفة الوحدة هي مصفوفة مربعة جميع عناصر القطر الرئيسي فيها تساوي 1، وباقي العناصر تساوي 0.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نمر على عناصر المصفوفة ونختبر شرطين أساسيين لتصيد الخطأ مبكراً.

• عناصر القطر الرئيسي (حيث الفهرس i يساوي الفهرس j) يجب أن تكون 1. إذا وجدنا أي عنصر فيها لا يساوي 1، نرجع false.

• باقي العناصر في المصفوفة (حيث i لا يساوي j) يجب أن تكون 0. إذا وجدنا أي عنصر فيها لا يساوي 0، نرجع false.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to check if a matrix is an Identity Matrix
bool IsIdentityMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            // Check diagonal elements (must be 1)
            if (i == j && matrix[i][j] != 1)
            {
                return false;
            }
            // Check rest of elements (must be 0)
            else if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #13 : Check Identity Matrix";
    cout << "\n-------------------------------------------------\n\n";

    // Defining a clear identity matrix for testing
    int matrix1[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

    cout << "Matrix 1: \n\n";
    PrintMatrix(matrix1, 3, 3);

    if (IsIdentityMatrix(matrix1, 3, 3))
    {
        cout << "\nYES: Matrix is an Identity Matrix.\n";
    }
    else
    {
        cout << "\nNo: Matrix is NOT an Identity Matrix.\n";
    }

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• التفكير المنطقي: بدلاً من التحقق من أن كل شيء صحيح (مما يتطلب إكمال كل اللفات لتأكيده)، نحن نبحث عن "الخطأ". بمجرد إيجاد شرط واحد مكسور في المصفوفة، نوقف العمل ونرجع false فوراً.

## 🧩 Problem #14: Check Scalar Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج للتحقق مما إذا كانت المصفوفة هي مصفوفة قياسية (Scalar Matrix). وهي مصفوفة قطرية جميع عناصر قطرها الرئيسي متساوية (لها نفس الرقم)، وباقي العناصر تساوي 0.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نقرأ أول عنصر في القطر الرئيسي [0][0] ونخزنه كقيمة مرجعية.

• نمر على المصفوفة، وإذا كنا في القطر الرئيسي (i يساوي j)، نتأكد أن العنصر يساوي القيمة المرجعية المخزنة، وإلا نرجع false.

• إذا كنا خارج القطر الرئيسي (i لا يساوي j)، نتأكد أن العنصر يساوي 0، وإلا نرجع false.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to check if a matrix is a Scalar Matrix
bool IsScalarMatrix(int matrix[3][3], short rows, short cols)
{
    // Store the first diagonal element as a reference
    int firstDiagElement = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            // Check diagonal elements (must match the reference element)
            if (i == j && matrix[i][j] != firstDiagElement)
            {
                return false;
            }
            // Check rest of elements (must be 0)
            else if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #14 : Check Scalar Matrix";
    cout << "\n-------------------------------------------------\n\n";

    // Defining a clear scalar matrix for testing
    int matrix1[3][3] = { {9, 0, 0}, {0, 9, 0}, {0, 0, 9} };

    cout << "Matrix 1: \n\n";
    PrintMatrix(matrix1, 3, 3);

    if (IsScalarMatrix(matrix1, 3, 3))
    {
        cout << "\nYES: Matrix is a Scalar Matrix.\n";
    }
    else
    {
        cout << "\nNo: Matrix is NOT a Scalar Matrix.\n";
    }

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• تخزين القيمة المرجعية: تخزين أول عنصر في المتغير firstDiagElement فكرة ذكية جداً لتجنب مقارنة العنصر الحالي بالعنصر السابق، مما يسهل اللوجيك بشكل كبير ويمنع تداخل الشروط.

## 🧩 Problem #15: Count Number In Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يبحث عن رقم معين (يدخله المستخدم) داخل مصفوفة 3x3، ويقوم بعد مرات تكرار هذا الرقم داخل المصفوفة، ثم طباعة النتيجة النهائية.

### 💡 الفكرة البرمجية (Logic Breakdown)

• تعريف متغير كعداد (Counter) بقيمة ابتدائية 0.

• نمر بحلقات تكرار على كامل المصفوفة.

• في كل لفة، نقارن العنصر الحالي بالرقم المطلوب. إذا تطابقا، نزيد العداد بمقدار 1.

• نرجع قيمة العداد النهائية بعد الانتهاء من فحص كل العناصر.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Bug Fixed: Added 'return number' to properly return user input
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

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to count how many times a number appears in the matrix
short CountNumberInMatrix(int matrix[3][3], int numberToCount, short rows, short cols)
{
    short count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == numberToCount)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #15 : Count Number In Matrix";
    cout << "\n-------------------------------------------------\n\n";

    // Hardcoding a matrix for demonstration
    int matrix1[3][3] = { {9, 1, 12}, {0, 9, 1}, {0, 9, 9} };

    cout << "Matrix 1: \n\n";
    PrintMatrix(matrix1, 3, 3);

    int number = ReadPositiveNumber("\nEnter the number to count in matrix: ");
    short count = CountNumberInMatrix(matrix1, number, 3, 3);

    cout << "\nThe Number " << number << " is found " << count << " times in the matrix.\n";

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}
```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• إصلاح الأخطاء (Bug Fix): تم تعديل دالة ReadPositiveNumber وإضافة return number في نهايتها، وهو أمر جوهري وأساسي لكي ترجع الدالة القيمة المطلوبة للبرنامج الرئيسي وتمنع أي سلوك غير متوقع (Undefined Behavior) كان يحدث بسبب نسيان إرجاع القيمة.

## 🧩 Problem #16: Check Sparse Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج للتحقق مما إذا كانت المصفوفة المُدخلة هي "مصفوفة متناثرة" (Sparse Matrix). تُعرف المصفوفة المتناثرة في هذا السياق بأنها المصفوفة التي يكون عدد الأصفار (0s) فيها أكبر من أو يساوي عدد الأرقام الأخرى (Non-zero numbers).

### 💡 الفكرة البرمجية (Logic Breakdown)

• حساب الحجم الكلي: لمعرفة إجمالي عدد العناصر نضرب عدد الصفوف في الأعمدة (مثلاً 3 × 3 = 9).

• استخدام دالة العد (Reuse): نستخدم دالة CountNumberInMatrix التي بنيناها في المسألة السابقة لعد كم مرة يظهر الرقم 0 في المصفوفة.

• المقارنة: نتحقق هل عدد الأصفار أكبر من أو يساوي نصف إجمالي عناصر المصفوفة TotalSize / 2.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <cmath> // لاستخدام دالة ceil
#include <iomanip>
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

short CountNumberInMatrix(int matrix[3][3], int numberToCount, short rows, short cols)
{
    short count = 0;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == numberToCount)
            {
                count++;
            }
        }
    }
    return count;
}

// Function to check if a matrix is sparse
bool IsSparseMatrix(int matrix[3][3], short rows, short cols)
{
    short matrixSize = rows * cols;
    // نتأكد هل عدد الأصفار أكبر من أو يساوي نصف حجم المصفوفة
    // استخدمنا (float) و ceil لضمان تقريب الأرقام الفردية للأعلى (مثال: 9/2 = 4.5 -> 5)
    return (CountNumberInMatrix(matrix, 0, rows, cols) >= ceil((float)matrixSize / 2));
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #16 : Check Sparse Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3] = { {0, 0, 12}, {9, 9, 1}, {0, 0, 9} };

    cout << "Matrix 1:\n\n";
    PrintMatrix(matrix1, 3, 3);

    if (IsSparseMatrix(matrix1, 3, 3))
    {
        cout << "\nYes: The matrix is Sparse.\n";
    }
    else
    {
        cout << "\nNo: The matrix is NOT Sparse.\n";
    }

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• القسمة والتقريب للأعلى (Ceil and Float Cast): عندما نقسم رقم فردي مثل 9 على 2 برمجياً، النتيجة تكون 4 (لأن نوع البيانات integer يهمل الكسر). لتصحيح ذلك، قمنا بتحويل المتغير لـ float أولاً (float)matrixSize لتصبح النتيجة 4.5، ثم استخدمنا دالة ceil لتقريبها للأعلى فتصبح 5. هذا يضمن عمل الكود بدقة مع المصفوفات الفردية الأبعاد.

## 🧩 Problem #17: Number Exists In Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يفحص هل رقم معين (يدخله المستخدم) موجود داخل المصفوفة أم لا. الهدف هنا ليس معرفة كم مرة تكرر الرقم، بل مجرد التأكد من "وجوده".

### 💡 الفكرة البرمجية (Logic Breakdown)

• نمر على كل عنصر في المصفوفة ونقارنه بالرقم المطلوب.

• بمجرد أن نجد الرقم، نقوم بعمل (Early Return) وإرجاع true فوراً لإنهاء الدالة.

• إذا انتهت الحلقات كلها دون العثور على الرقم، نُرجع false.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to check if a specific number exists in the matrix
bool IsNumberInMatrix(int matrix[3][3], int number, short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == number)
            {
                return true; // Early Return
            }
        }
    }
    return false;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #17 : Check if Number Exists in Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3] = { {77, 5, 12}, {22, 20, 1}, {1, 0, 9} };

    cout << "Matrix 1:\n\n";
    PrintMatrix(matrix1, 3, 3);

    int number = 20; // Hardcoded for demo, could use ReadPositiveNumber
    cout << "\nLooking for number: " << number << "\n";

    // الطريقة السريعة
    if (IsNumberInMatrix(matrix1, number, 3, 3))
    {
        cout << "\nYes: The number is there.\n";
    }
    else
    {
        cout << "\nNo: The number is NOT there.\n";
    }

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• الخروج المبكر (Early Return): كما نوه الدكتور أبو هدهود، يمكننا استخدام دالة العد CountNumberInMatrix > 0 لحل هذه المسألة، ولكنها أبطأ لأنها تجبر الكومبايلر على فحص كامل المصفوفة. بينما استخدام الخروج المبكر (Early Return) يجعل الدالة تتوقف عن الفحص وتُرجع true بمجرد العثور على الرقم (مثلاً من أول خانة)، مما يجعل الأداء (Time Complexity) $O(1)$ في أفضل الحالات.

## 🧩 Problem #18: Intersected Numbers in Matrices

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقارن بين مصفوفتين، ويقوم بطباعة "الأرقام المشتركة" (Intersected Numbers) الموجودة في كلتا المصفوفتين.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نمر على كل عنصر في المصفوفة الأولى باستخدام for loop.

• نأخذ هذا العنصر ونمرره إلى الدالة IsNumberInMatrix التي صنعناها للتو في المسألة السابقة، ونسألها: "هل هذا العنصر موجود في المصفوفة الثانية؟".

• إذا كان الجواب نعم (true)، نقوم بطباعة الرقم على الشاشة.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

bool IsNumberInMatrix(int matrix[3][3], int number, short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}

// Function to print intersected numbers between two matrices
void PrintIntersectedNumbers(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            int number = matrix1[i][j];
            // Check if the current element from Matrix1 exists in Matrix2
            if (IsNumberInMatrix(matrix2, number, rows, cols))
            {
                cout << setw(3) << number << " ";
            }
        }
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #18 : Intersected Numbers in Matrices";
    cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3] = { {77, 5, 12}, {22, 20, 1}, {1, 0, 9} };
    int matrix2[3][3] = { {5, 80, 90}, {22, 77, 1}, {10, 8, 33} };

    cout << "Matrix 1:\n\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "\nMatrix 2:\n\n";
    PrintMatrix(matrix2, 3, 3);

    cout << "\nIntersected Numbers are: \n\n";
    PrintIntersectedNumbers(matrix1, matrix2, 3, 3);
    cout << "\n";

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• قوة إعادة الاستخدام (Power of Reusability): لاحظ كيف أن الدالة PrintIntersectedNumbers أصبحت قصيرة جداً ومقروءة بشكل واضح لأننا اعتمدنا على دالة IsNumberInMatrix الجاهزة بدلاً من بناء حلقة تكرار ثالثة ورابعة بداخلها للبحث، مما يُقلل من تعقيد الكود (Nesting).

## 🧩 Problem #19: Min and Max Number In Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بالبحث عن "أصغر رقم" (Minimum) و "أكبر رقم" (Maximum) بداخل مصفوفة معينة، ثم يقوم بطباعتهما.

### 💡 الفكرة البرمجية (Logic Breakdown)

• تهيئة القيمة الابتدائية: أهم تريكة هنا هي ألا تضع القيمة الابتدائية بصفر (0). الأصح برمجياً هو أن تفترض أن أول عنصر في المصفوفة matrix[0][0] هو الأصغر (أو الأكبر) وتخزنه في متغير.

• المرور والتحديث: تمر على المصفوفة وتقارن كل عنصر بالمتغير الذي خزنته. إذا كان العنصر الجديد أصغر، تُحدث قيمة الـ Minimum. وإذا كان أكبر، تُحدث الـ Maximum.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << "\t" << setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to find the minimum number in the matrix
int MinNumberInMatrix(int matrix[3][3], short rows, short cols)
{
    // Start by assuming the very first element is the smallest
    int min = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j]; // Update the minimum
            }
        }
    }
    return min;
}

// Function to find the maximum number in the matrix
int MaxNumberInMatrix(int matrix[3][3], short rows, short cols)
{
    // Start by assuming the very first element is the largest
    int max = matrix[0][0];

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j]; // Update the maximum
            }
        }
    }
    return max;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #19 : Min and Max Number in Matrix";
    cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3] = { {77, 5, 12}, {22, 20, 6}, {14, 3, 9} };

    cout << "Matrix 1:\n\n";
    PrintMatrix(matrix1, 3, 3);

    cout << "\nMinimum Number is: " << MinNumberInMatrix(matrix1, 3, 3) << endl;
    cout << "Maximum Number is: " << MaxNumberInMatrix(matrix1, 3, 3) << endl;

    cout << "\n-------------------------------------------------\n\n";

    return 0;
}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• التهيئة الآمنة (Safe Initialization): لو قمنا بتهيئة int min = 0 وكانت المصفوفة تحتوي فقط على أرقام موجبة ضخمة (مثلاً تبدأ من 50)، فإن الدالة كانت سترجع 0 بالخطأ لأنه أصغر من كل الأرقام! لذلك، الاعتماد على العنصر الأول matrix[0][0] يحمي برنامجك تماماً من هذه الأخطاء المنطقية.

## 🧩 Problem #20: Palindrome Matrix

### 📝 وصف المشكلة (Problem Description)

المطلوب التحقق مما إذا كانت المصفوفة "متماثلة" (Palindrome Matrix) أم لا. في هذا السياق، المصفوفة تعتبر Palindrome إذا كان كل صف (Row) بداخلها يُقرأ من اليمين لليسار تماماً كما يُقرأ من اليسار لليمين.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نحن لا نحتاج لفحص المصفوفة بالكامل، بل يكفي فحص النصف الأول من كل صف ومقارنته بالنصف الثاني المعكوس.

• تمر الحلقة الخارجية i على جميع الصفوف.

• تمر الحلقة الداخلية j على الأعمدة حتى المنتصف فقط Cols / 2.

• نقارن العنصر الأيسر matrix[i][j] بالعنصر الذي يقابله في الجهة اليمنى matrix[i][Cols - 1 - j]. إذا اختلفا، نُرجع false.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int matrix[3][3], short rows, short cols)
{
for (short i = 0; i < rows; i++)
{
for (short j = 0; j < cols; j++)
{
cout << "\t" << setw(3) << matrix[i][j];
}
cout << endl;
}
}

// Function to check if the matrix is a Palindrome
bool IsPalindromeMatrix(int matrix[3][3], short rows, short cols)
{
for (short i = 0; i < rows; i++)
{
// Loop through the columns only up to the middle (Cols / 2)
for (short j = 0; j < cols / 2; j++)
{
// Compare the current element with its mirrored counterpart on the right side
if (matrix[i][j] != matrix[i][cols - 1 - j])
{
return false; // Not a palindrome if any mismatch is found
}
}
}
return true;
}

int main()
{
cout << "\n-------------------------------------------------\n";
cout << "Problem #20 : Palindrome Matrix";
cout << "\n-------------------------------------------------\n\n";

    int matrix1[3][3] = { {1, 2, 1}, {5, 5, 5}, {7, 3, 7} };

    cout << "Matrix 1:\n\n";
    PrintMatrix(matrix1, 3, 3);

    if (IsPalindromeMatrix(matrix1, 3, 3))
    {
        cout << "\nYes: The matrix is a Palindrome.\n";
    }
    else
    {
        cout << "\nNo: The matrix is NOT a Palindrome.\n";
    }

    cout << "\n-------------------------------------------------\n\n";

    return 0;

}

```

</div>

### 🛠️ ملاحظات هندسية (Engineering Notes)

• تحسين الأداء (Performance Optimization): لو جعلنا الحلقة الداخلية تستمر حتى النهاية Cols، لكنا نفحص كل زوج مرتين بلا أي داعٍ! إيقاف الفحص عند Cols / 2 يختصر وقت تنفيذ هذه الدالة إلى النصف، وهو ما يصنع فارقاً حاسماً في المصفوفات الضخمة (مثل معالجة الصور التي تحتوي على ملايين البيكسلات).

## 🧩 Problem #21: Fibonacci Series Using Loop

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج لطباعة سلسلة فيبوناتشي (Fibonacci Series) لعدد معين من الخانات (مثلاً 10). في هذه السلسلة، كل رقم هو مجموع الرقمين اللذين يسبقانه (1, 1, 2, 3, 5, 8...).

### 💡 الفكرة البرمجية (Logic Breakdown)

• المتغيرات الابتدائية: السلسلة تبدأ دائماً بالرقمين 1 و 1 (أو 0 و 1). نُعطي متغيرين قيماً ابتدائية Prev1 = 1 و Prev2 = 0.

• حلقة التكرار: نمر بحلقة تكرار تبدأ من 2 وحتى الرقم المطلوب.

• التحديث المستمر: في كل لفة، نجمع الرقمين السابقين للحصول على الرقم الجديد، ثم نقوم بترحيل القيم (نجعل الأول يأخذ قيمة الثاني، والثاني يأخذ القيمة الجديدة) للتحضير للفة القادمة.

### 💻 الكود المعتمد (Solution)

```cpp
#include <iostream>
using namespace std;

// Function to print Fibonacci series using an iterative loop
void PrintFibonacciUsingLoop(short number)
{
    int febNumber = 0;
    int prev2 = 0, prev1 = 1;

    cout << "1 "; // Print the first number manually

    for (short i = 2; i <= number; ++i)
    {
        febNumber = prev1 + prev2;
        cout << febNumber << " ";

        // Shift the variables for the next iteration
        prev2 = prev1;
        prev1 = febNumber;
    }
    cout << endl;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #21 : Fibonacci Series Using Loop";
    cout << "\n-------------------------------------------------\n\n";

    cout << "Fibonacci Series of 10: \n";
    PrintFibonacciUsingLoop(10);

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

### 🛠️ ملاحظات هندسية (Engineering Notes)

• الأداء (Iterative Performance): استخدام حلقة التكرار (Loop) هو الأسلوب الأفضل والأسرع لحل سلسلة فيبوناتشي برمجياً، حيث أن تعقيد الوقت (Time Complexity) هو $O(N)$ ولا يستهلك مساحة إضافية من الذاكرة (Call Stack) كما تفعل طريقة الاستدعاء الذاتي (Recursion).

## 🧩 Problem #22: Fibonacci Series Using Recursion

### 📝 وصف المشكلة (Problem Description)

المطلوب هو نفس المسألة السابقة (طباعة سلسلة فيبوناتشي لـ 10 أرقام)، ولكن هذه المرة باستخدام الاستدعاء الذاتي (Recursion) بدلاً من حلقات التكرار التقليدية.

### 💡 الفكرة البرمجية (Logic Breakdown)

• شرط التوقف (Base Case): تتوقف الدالة عن استدعاء نفسها عندما يصل العداد Number إلى صفر.

• تحديث المتغيرات: الدالة تستقبل الرقمين السابقين كبارامترات (Prev1 و Prev2). في كل استدعاء جديد، نُمرر لها القيم المُحدثة وننقص العداد بمقدار 1.

### 💻 الكود المعتمد (Solution)

```cpp
#include <iostream>
using namespace std;

// Function to print Fibonacci series using Recursion
void PrintFibonacciUsingRecursion(short number, int prev1, int prev2)
{
    int febNumber = 0;

    // Base Case
    if (number > 0)
    {
        febNumber = prev2 + prev1;
        cout << febNumber << " ";

        // Shift variables and pass to the next recursive call
        prev2 = prev1;
        prev1 = febNumber;

        PrintFibonacciUsingRecursion(number - 1, prev1, prev2);
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #22 : Fibonacci Series Using Recursion";
    cout << "\n-------------------------------------------------\n\n";

    cout << "Fibonacci Series of 10: \n1 ";

    // Pass the initial values (0 and 1) to start the series
    PrintFibonacciUsingRecursion(9, 0, 1);
    cout << endl;

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

### 🛠️ ملاحظات هندسية (Engineering Notes)

• خطر الاستدعاء الذاتي (Stack Overflow): رغم أن الـ Recursion يكتب كوداً أنيقاً ومختصراً، إلا أنه خطير جداً مع الأرقام الكبيرة. استدعاء الدالة لنفسها 1000 مرة مثلاً سيملأ الـ (Call Stack) بالكامل ويؤدي لانهيار البرنامج. لذلك يُفضل استخدام الـ Loop في بيئات الإنتاج الحقيقية.

## 🧩 Problem #23: Print First Letter of Each Word

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقرأ نصاً (String) من المستخدم، ثم يطبع الحرف الأول من كل كلمة موجودة في هذا النص.

### 💡 الفكرة البرمجية (Logic Breakdown)

• استخدام راية (Flag): نُعرف متغيراً من نوع bool (مثلاً isFirstLetter) ونعطيه قيمة مبدئية true لأن أول حرف في النص هو حتماً بداية كلمة (إذا لم يكن مسافة).

• المرور على النص: نتفحص كل حرف. إذا لم يكن الحرف مسافة فارغة وكان الـ Flag يساوي true، إذن هذا الحرف هو بداية كلمة فنقوم بطباعته.

• تحديث الراية: إذا صادفنا مسافة فارغة ، فهذا يعني أن الحرف القادم سيكون بداية كلمة جديدة، فنقوم بقلب الراية إلى true.

### 💻 الكود المعتمد (Solution)

```cpp

#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string s;
    cout << "Please enter your string:\n";
    getline(cin, s);
    return s;
}

// Function to print the first letter of each word
void PrintFirstLetterOfEachWord(string s)
{
    bool isFirstLetter = true;

    cout << "\nFirst letters of this string: \n";

    for (short i = 0; i < s.length(); i++)
    {
        // Print if it's not a space and isFirstLetter is true
        if (s[i] != ' ' && isFirstLetter)
        {
            cout << s[i] << " ";
        }

        // Update the flag: if current char is space, next char is a first letter
        isFirstLetter = (s[i] == ' ' ? true : false);
    }
    cout << endl;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #23 : Print First Letter of Each Word";
    cout << "\n-------------------------------------------------\n\n";

    string text = ReadString();
    PrintFirstLetterOfEachWord(text);

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

### 🛠️ ملاحظات هندسية (Engineering Notes)

• آلة الحالة (State Machine Concept): فكرة استخدام الـ bool لتتبع "حالة" البرنامج (هل نحن بداخل كلمة أم خارجها؟) هي تطبيق مصغر لمفهوم برمجي قوي جداً يُسمى الـ State Machine، والذي يستخدم بكثرة في تحليل النصوص (Parsing) والمترجمات (Compilers).

## 🧩 Problem #24: Upper First Letter of Each Word

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقرأ نصاً (String)، ويقوم بتحويل الحرف الأول من كل كلمة إلى حرف كبير (Uppercase)، ثم يطبع النص المُعدل.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نفس لوجيك المسألة السابقة (استخدام Flag).

• بدلاً من طباعة الحرف الأول، نقوم بتعديله في مكانه داخل الـ String باستخدام دالة toupper() الموجودة في مكتبة <cctype>.

• نُرجع النص المُعدل (String) كاملاً للمستخدم.

### 💻 الكود المعتمد (Solution)

```cpp
#include <iostream>
#include <string>
#include <cctype> // For toupper
using namespace std;

string ReadString()
{
    string s;
    cout << "Please enter your string:\n";
    getline(cin, s);
    return s;
}

// Function to uppercase the first letter of each word
string UpperFirstLetterOfEachWord(string s)
{
    bool isFirstLetter = true;

    for (short i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ' && isFirstLetter)
        {
            // Modify the character in-place
            s[i] = toupper(s[i]);
        }

        isFirstLetter = (s[i] == ' ' ? true : false);
    }
    return s;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #24 : Upper First Letter of Each Word";
    cout << "\n-------------------------------------------------\n\n";

    string text = ReadString();

    cout << "\nString after conversion:\n";
    text = UpperFirstLetterOfEachWord(text);
    cout << text << endl;

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

### 🛠️ ملاحظات هندسية (Engineering Notes)

• قابلية التعديل (String Mutability): في لغة C++، النصوص (Strings) قابلة للتعديل مباشرة في الذاكرة (Mutable). يمكنك الوصول لأي حرف عن طريق الفهرس الخاص به s[i] وتغييره فوراً دون الحاجة لإنشاء نص جديد، مما يحسن الأداء.

## 🧩 Problem #25: Lower First Letter of Each Word

### 📝 وصف المشكلة (Problem Description)

المطلوب قراءة نص (String)، وتحويل الحرف الأول من كل كلمة إلى حرف صغير (Lowercase)، ثم طباعة النص المُعدل.

### 💡 الفكرة البرمجية (Logic Breakdown)

• الكود متطابق تماماً بنسبة 99% مع المسألة السابقة.

• التغيير الوحيد هو استخدام الدالة العكسية tolower() بدلاً من toupper().

### 💻 الكود المعتمد (Solution)

```cpp
#include <iostream>
#include <string>
#include <cctype> // For tolower
using namespace std;

string ReadString()
{
    string s;
    cout << "Please enter your string:\n";
    getline(cin, s);
    return s;
}

// Function to lowercase the first letter of each word
string LowerFirstLetterOfEachWord(string s)
{
    bool isFirstLetter = true;

    for (short i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ' && isFirstLetter)
        {
            // Modify the character in-place
            s[i] = tolower(s[i]);
        }

        isFirstLetter = (s[i] == ' ' ? true : false);
    }
    return s;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #25 : Lower First Letter of Each Word";
    cout << "\n-------------------------------------------------\n\n";

    string text = ReadString();

    cout << "\nString after conversion:\n";
    text = LowerFirstLetterOfEachWord(text);
    cout << text << endl;

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

### 🛠️ ملاحظات هندسية (Engineering Notes)

• إعادة الاستخدام (Code Pattern): تشابه هذا الكود مع الكود السابق يؤكد على قوة الأنماط البرمجية (Patterns). بمجرد أن تبتكر خوارزمية لتحديد "بداية الكلمات"، يمكنك تطبيق أي عملية تريدها (تكبير، تصغير، تلوين، الخ) بتبديل دالة واحدة فقط.

## 🧩 Problem #26: Upper/Lower All Letters of a String

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقرأ نصاً (String)، ثم يقوم بطباعته مرتين: المرة الأولى تكون فيها جميع الحروف كبيرة (Uppercase)، والمرة الثانية تكون فيها جميع الحروف صغيرة (Lowercase).

### 💡 الفكرة البرمجية (Logic Breakdown)

• المرور الشامل: نمر بحلقة التكرار (Loop) على جميع أحرف النص دون استثناء.

• التحويل المباشر: نُطبق دالة toupper() أو tolower() على كل حرف.

• أمان الدوال: دوال التحويل هذه ذكية بما يكفي لتتجاهل المسافات الفارغة وعلامات الترقيم والأرقام، فلا داعي لوضع شروط if للتحقق من نوع الحرف قبل تحويله.

### 💻 الكود المعتمد (Solution)

```CPP
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString()
{
    string s;
    cout << "Please enter your string:\n";
    getline(cin, s);
    return s;
}

// Function to upper all letters in the string
string UpperAllString(string s)
{
    for (short i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

// Function to lower all letters in the string
string LowerAllString(string s)
{
    for (short i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #26 : Upper and Lower All Letters";
    cout << "\n-------------------------------------------------\n\n";

    string text = ReadString();

    cout << "\nString after Uppercase:\n";
    text = UpperAllString(text);
    cout << text << endl;

    cout << "\nString after Lowercase:\n";
    text = LowerAllString(text);
    cout << text << endl;

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}

```

### 🛠️ ملاحظات هندسية (Engineering Notes)

• بساطة الكود: لاحظ كيف أن التخلص من الشروط المعقدة جعل الخوارزمية سريعة جداً. الاعتماد على قوة الـ Standard Library (مثل <cctype>) يوفر وقت التنفيذ (Execution Time) ويقلل احتمالية حدوث أخطاء برمجية (Bugs).

## 🧩 Problem #27: Invert Character Case

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقرأ حرفاً (Character) واحداً من المستخدم، ويقوم بعكس حالة هذا الحرف (Invert Case)، أي تحويله من كبير إلى صغير أو العكس، ثم يطبعه.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نستخدم دالة isupper() لفحص حالة الحرف المُدخل.

• إذا كان الحرف كبيراً (True)، نستخدم دالة tolower() لتحويله لأسفل.

• إذا كان الحرف صغيراً (False)، نستخدم دالة toupper() لتحويله لأعلى.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char ReadChar(string message)
{
    char l;
    cout << message;
    cin >> l;
    return l;
}

char InvertLetterCase(char l)
{
    // Using Ternary Operator to toggle between upper and lower cases
    return (isupper(l) ? tolower(l) : toupper(l));
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #27 : Invert Character Case";
    cout << "\n-------------------------------------------------\n\n";

    char letter = ReadChar("Please Enter a character: ");
    cout << "\nCharacter after inverting case : " << InvertLetterCase(letter);

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}

```
</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• حلك متطابق تماماً مع حل الدكتور من حيث المنطق الرياضي والأداء. كليكما استخدم "المعامل الثلاثي" (Ternary Operator) للتحقق من حالة الحرف وتغييرها في سطر واحد فقط، وهذا يعتبر من أفضل الممارسات (Best Practice) لتقليل حجم الكود وسهولة قراءته.

## 🧩 Problem #28: Invert All Letters Case

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقرأ نصاً (String) كاملاً، ثم يقوم بعكس حالة جميع حروفه، بحيث يتحول الحرف الكبير إلى صغير، والصغير إلى كبير، ثم يُطبع النص الناتج.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نقوم بالمرور على جميع أحرف الـ String باستخدام for loop.

• نُمرر كل حرف لدالة InvertLetterCase التي قمنا ببنائها في المسألة السابقة.

• نقوم بتعديل الحرف في مكانه داخل النص الأصلي.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

char InvertLetterCase(char l)
{
    return (isupper(l) ? tolower(l) : toupper(l));
}

string InvertAllStringLettersCase(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        // Modifying the character directly using the previous function
        str[i] = InvertLetterCase(str[i]);
    }
    return str;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #28 : Invert All Letters Case";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter a String: ");
    cout << "String after inverting all letters case: " << InvertAllStringLettersCase(str);

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}
```

</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• تطابق تام (Perfect Match) في الفكرة البرمجية. استخدامك لدالة InvertLetterCase داخل الـ Loop يجسد مفهوم الـ Reusability (إعادة استخدام الكود)، وهو ما فعله الدكتور أبو هدهود تماماً. أداء الكود ممتاز وهو $O(N)$.

## 🧩 Problem #29: Count Small/Capital Letters

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقوم بعدّ (حساب) الحروف داخل نص مُدخل، ويوفر القدرة على جلب ثلاثة أشياء: طول النص الكلي، عدد الحروف الكبيرة (Capital)، وعدد الحروف الصغيرة (Small).

### 💡 الفكرة البرمجية (Logic Breakdown)

• إنشاء Enum يُسمى enWhatToCount ليحتوي على الثلاث حالات المطلوبة.

• إنشاء دالة موحدة تستقبل النص، وتستقبل المتغير من نوع الـ Enum كـ (Default Parameter).

• الدالة تتفحص نوع الـ Enum المُرسل: إما أن تعيد طول النص كاملاً، وإما أن تمر بحلقة تكرار لعد الحروف الصغرى، وإما أن تعد الحروف الكبرى بناءً على طلب المستخدم.

### 💻 الكود المعتمد (Solution)

```cpp
<div dir="ltr">

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

// Enum to organize options clearly
enum enWhatToCount
{
    SmallLetters = 1,
    CapitalLetters = 2,
    AllLetters = 3
};

// Unified function with a default parameter
short CountLetters(string str, enWhatToCount whatToCount = enWhatToCount::AllLetters)
{
    if (whatToCount == enWhatToCount::AllLetters)
        return str.length();
        
    short count = 0;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (whatToCount == enWhatToCount::SmallLetters)
        {
            if (islower(str[i]))
                count++;
        }
        else if (whatToCount == enWhatToCount::CapitalLetters)
        {
            if (isupper(str[i]))
                count++;
        }
    }
    return count;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #29 : Count Small, Capital and All Letters";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter a String: ");
    
    cout << "\nString Length             : " << CountLetters(str, enWhatToCount::AllLetters);
    cout << "\nNumber of Small Letters   : " << CountLetters(str, enWhatToCount::SmallLetters);
    cout << "\nNumber of Capital Letters : " << CountLetters(str, enWhatToCount::CapitalLetters);

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}

```
</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• تفوق تنظيمي ملحوظ في حلك! الدكتور أبو هدهود قام بشرح طريقتين: الأولى بدائية عن طريق كتابة دالتين منفصلتين (واحدة للحروف الكبيرة وأخرى للصغيرة)، والثانية احترافية تعتمد على دالة موحدة تستخدم الـ Enum. أنت دخلت مباشرة إلى "الاحترافية" واستخدمت الطريقة المتقدمة، مطبقاً بذلك مبدأ (DRY: Don't Repeat Yourself) لتقليل حجم الكود وتسهيل صيانته.

## 🧩 Problem #30: Count Letters

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقرأ نصاً (String) ويقرأ حرفاً واحداً (Character) من المستخدم، ثم يعد كم مرة تكرر هذا الحرف بعينه داخل النص المكتوب.

### 💡 الفكرة البرمجية (Logic Breakdown)

• تمرير النص والحرف كبارامترات لدالة العد.

• المرور على جميع أحرف النص عن طريق for loop.

• اختبار ما إذا كان الحرف الحالي يساوي == الحرف المبعوث، وفي حالة التطابق نزيد العداد بمقدار 1.

### 💻 الكود المعتمد (Solution)

```cpp
<div dir="ltr">

#include <iostream>
#include <string>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

// Function to count the occurrences of a specific character
short CountLetters(string str, char c)
{
    short count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
            count++;
    }
    return count;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #30 : Count Specific Letter in a String";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter a String: ");
    
    // We expect a single character, so we take the first char of the string input
    char c = ReadString("Enter a character to count: ")[0];
    
    cout << "\nNumber of '" << c << "' in the string is : " << CountLetters(str, c);

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}

```
</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• التطابق التام. اللوجيك لديك ولدى الدكتور متماثل وهو يعتمد على المرور الخطي المباشر (Linear Search) بأداء $O(N)$، وهو الأداء الأمثل لهذا النوع من المهام.

## 🧩 Problem #31: Count Letters (Match Case or Not)

### 📝 وصف المشكلة (Problem Description)

تطوير للمسألة السابقة: البرنامج يعد تكرار حرف معين داخل نص، ولكنه يعطي المستخدم خياراً إضافياً، إما المطابقة التامة لحالة الحرف (Match Case)، وإما تجاهل حالة الحرف (مثلاً عند البحث عن a يتم عد كلاً من a و A).

### 💡 الفكرة البرمجية (Logic Breakdown)

• إضافة معامل افتراضي للدالة (Default Parameter) من نوع bool MatchCase = true.

• إذا كانت MatchCase تساوي true، نقارن الحروف مباشرة str[i] == c (تطابق دقيق).

• أما إذا أرسلنا false، فإننا نستخدم دالة tolower() على الحرفين معاً قبل إجراء المقارنة لتوحيد حالتهما، وبذلك يتم استيعاب الحروف الكبيرة والصغيرة في العد.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

char InvertLetterCase(char l)
{
    return (isupper(l) ? tolower(l) : toupper(l));
}

// Function with Default Parameter to handle Match Case logic
short CountLetters(string str, char c, bool MatchCase = true)
{
    short count = 0;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (MatchCase) // Exact match is required
        {
            if (str[i] == c)
                count++;
        }
        else // Case-insensitive match
        {
            if (tolower(str[i]) == tolower(c))
                count++;
        }
    }
    return count;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #31 : Count Letters (Match Case Options)";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter a String: ");
    char c = ReadString("Enter a character to count: ")[0];
    
    // Counting with MatchCase = true (Default)
    cout << "\nNumber of '" << c << "' in the string is : " 
         << CountLetters(str, c);
         
    // Counting with MatchCase = false (Case-Insensitive)
    cout << "\nNumber of '" << c << "' or '" << InvertLetterCase(c) << "' in the string is : " 
         << CountLetters(str, c, false);

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}

```
</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• اللوجيك متطابق بنسبة 100%. فكرة توحيد الحروف إلى الـ Lowercase باستخدام دالة tolower في جانبي المقارنة هي الحيلة الأذكى برمجياً في عملية التجاهل (Case Insensitive Search)، وقد طبقتها ببراعة.

## 🧩 Problem #32: Is Vowel

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يتحقق مما إذا كان الحرف المُدخل هو حرف عِلّة (Vowel) أم لا. حروف العلة الإنجليزية هي (a, e, i, o, u).

### 💡 الفكرة البرمجية (Logic Breakdown)

• لتبسيط الشرط وعدم تكراره للحروف الكبيرة والصغيرة (تجنب كتابة 10 شروط بدلاً من 5)، نقوم أولاً بتحويل الحرف المُدخل إلى Lowercase مؤقتاً في الذاكرة.

• ثم نفحص الحرف المخفض مع الحروف الخمسة الثابتة باستخدام المعامل المنطقي || (OR).

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char ReadChar(string message)
{
    char l;
    cout << message;
    cin >> l;
    return l;
}

// Function to check if a letter is a vowel
bool IsVowel(char l)
{
    char lowerL = tolower(l); // Convert to lowercase to minimize conditions
    return (lowerL == 'a' || lowerL == 'e' || lowerL == 'i' || lowerL == 'o' || lowerL == 'u');
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #32 : Check if Character is Vowel";
    cout << "\n-------------------------------------------------\n\n";

    char letter = ReadChar("Please Enter a character: ");
    
    if (IsVowel(letter))
    {
        cout << "\nYes, Character '" << letter << "' is a vowel.";
    }
    else
    {
        cout << "\nNo, Character '" << letter << "' is not a vowel.";
    }

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}
```

</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• الحلول متطابقة. تحويل الحرف لـ Lowercase أولاً قبل اختباره يُعتبر من قواعد كتابة الأكواد النظيفة (Clean Code Practices) لأنك وفرت على الكومبايلر وعلى المبرمج عبء قراءة شروط مزدوجة لا حاجة لها.

## 🧩 Problem #33: Count Vowels

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة برنامج يقرأ نصاً (String) من المستخدم، ثم يقوم بعدّ حروف العلة (Vowels) الموجودة في هذا النص وإرجاع المجموع النهائي.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نقوم بإعادة استخدام (Reuse) دالة IsVowel التي قمنا ببنائها في المسألة السابقة.

• نمر على النص كاملاً باستخدام حلقة تكرار (for loop).

• في كل لفة، نرسل الحرف الحالي إلى دالة IsVowel. إذا رجعت النتيجة true، نقوم بزيادة العداد بمقدار 1.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

// Reusing the IsVowel function
bool IsVowel(char l)
{
    char lowerL = tolower(l);
    return (lowerL == 'a' || lowerL == 'e' || lowerL == 'i' || lowerL == 'o' || lowerL == 'u');
}

// Function to count total vowels in a string
short CountVowels(string str)
{
    short count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #33 : Count Vowels in a String";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter a String: ");
    cout << "\nNumber of Vowels in string is: " << CountVowels(str);

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}

```
</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• الفكرة البرمجية متطابقة 100%. تطبيقك لمبدأ إعادة الاستخدام (Reusability) من خلال استدعاء دالة IsVowel داخل حلقة التكرار هو دليل على أنك بدأت تفكر كمهندس برمجيات يعتمد على الـ Modular Code.

## 🧩 Problem #34: Print All Vowels In String

### 📝 وصف المشكلة (Problem Description)

بدلاً من عدّ حروف العلة، المطلوب هو استخراج جميع حروف العلة (Vowels) الموجودة في النص المُدخل وطباعتها على الشاشة، مفصولة بمسافات.

### 💡 الفكرة البرمجية (Logic Breakdown)

• الفكرة مطابقة تماماً للمسألة السابقة.

• بدلاً من زيادة عداد عند التحقق من وجود حرف علة، سنقوم بطباعة الحرف مباشرة داخل الجملة الشرطية if.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

bool IsVowel(char l)
{
    char lowerL = tolower(l);
    return (lowerL == 'a' || lowerL == 'e' || lowerL == 'i' || lowerL == 'o' || lowerL == 'u');
}

// Function to print vowels instead of counting them
void PrintVowels(string str)
{
    for (short i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
        {
            cout << str[i] << " ";
        }
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #34 : Print All Vowels In String";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter a String: ");
    
    cout << "\nVowels in string : ";
    PrintVowels(str);

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}

```
</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• الحلول متطابقة تماماً. الكود نظيف، واستخدام نوع المتغير short في عداد الحلقة for هو ممارسة جيدة لتوفير الذاكرة.

## 🧩 Problem #35: Print Each Word In String

### 📝 وصف المشكلة (Problem Description)

هذه المسألة هي واحدة من أهم مسائل الكورس (String Parsing). المطلوب قراءة جملة كاملة من المستخدم (String)، ثم تقطيع هذه الجملة وطباعة كل كلمة على سطر مستقل.

### 💡 الفكرة البرمجية (Logic Breakdown)

• المحرف الفاصل (Delimiter): الكلمات تُفصل عادة بمسافة فارغة " ". سنبحث عن هذه المسافة.

• حلقة البحث والقص (find & substr):

نستخدم S1.find(delim) للبحث عن مكان أول مسافة.

نستخدم دالة substr(0, pos) لاقتطاع النص من البداية وحتى مكان المسافة (هذه هي الكلمة الأولى).

نستخدم دالة الـ erase() لقص الكلمة الأولى مع مسافتها من النص الكلي.

نستمر في هذه الحلقة طالما أن دالة البحث لا ترجع string::npos (أي طالما أن هناك مسافات).

• الكلمة الأخيرة: الكلمة الأخيرة في النص لن يكون بعدها مسافة غالباً، لذلك نضيف جملة شرطية في نهاية الدالة لطباعة ما تبقى من النص.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

// Function to parse and print each word separated by a space
void PrintEachWordInString(string S1)
{
    string delim = " ";
    short pos = 0;
    string sWord;

    cout << "\nYour string words are: \n";

    // Loop continues as long as the delimiter is found
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // Extract the word

        if (sWord != "") // Ensure we don't print empty strings
        {
            cout << "\t" << sWord << endl;
        }

        // Erase the extracted word and the delimiter to continue searching
        S1.erase(0, pos + delim.length());
    }

    // Print the final remaining word (if any)
    if (S1 != "")
    {
        cout << "\t" << S1 << endl;
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #35 : Print Each Word In String";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter your String : ");
    PrintEachWordInString(str);

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• تطابق تام! هذه هي الطريقة الكلاسيكية والصلبة (Standard) لتقطيع النصوص في لغة C++. منطق الـ while مع الـ find وتحديث الـ String باستخدام الـ erase يُظهر فهماً عميقاً لكيفية معالجة الـ Strings ديناميكياً.

## 🧩 Problem #36: Count Each Word In String

### 📝 وصف المشكلة (Problem Description)

بدلاً من طباعة الكلمات المقطعة، المطلوب هنا هو عدّ هذه الكلمات (عدد الكلمات الإجمالي في الجملة) وإرجاع العدد للمستخدم.

### 💡 الفكرة البرمجية (Logic Breakdown)

• اللوجيك المستخدم هنا هو نسخة كربونية من منطق التقطيع (Parsing) في المسألة 35.

• التغيير الوحيد: بدلاً من طباعة الكلمة على الشاشة، سنقوم بإنشاء عداد (Counter)، وكلما وجدنا كلمة واقتطعناها، نزيد العداد بمقدار 1.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

// Function to count the words using the parsing method
short CountWords(string S1)
{
    short counter = 0;
    string delim = " ";
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        
        if (sWord != "")
        {
            counter++;
        }
        
        S1.erase(0, pos + delim.length());
    }

    // Count the last word
    if (S1 != "")
    {
        counter++;
    }

    return counter;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #36 : Count Each Word In String";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter your String : ");
    cout << "\nYour string words count : " << CountWords(str);

    cout << "\n\n-------------------------------------------------\n\n";
    return 0;
}
```

</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• اللوجيك لديك ولدى الدكتور متطابق. قدرتك على تحويل دالة تقوم بـ "الطباعة" إلى دالة تقوم بـ "العد" باستخدام نفس المنهجية تدل على تحكمك الممتاز بالخوارزمية.

## 🧩 Problem #37: Split String

### 📝 وصف المشكلة (Problem Description)

هذه المسألة تمثل خطوة مهمة جداً لتأسيس أداة برمجية سنستخدمها كثيراً في المستقبل. المطلوب إنشاء دالة تُسمى SplitString تقوم بتقطيع النص ووضع جميع الكلمات داخل هيكل بيانات (Vector of Strings) لتتمكن من إرجاعه واستخدامه لاحقاً.

### 💡 الفكرة البرمجية (Logic Breakdown)

• نستخدم نفس أداة التقطيع والمسح (find & erase) للمسافات.

• نُعرّف Vector محلي داخل الدالة من نوع String.

• كلما اقتطعنا كلمة، نقوم بدفعها push_back إلى الـ Vector، ثم في نهاية الدالة نُرجع هذا الـ Vector للـ main.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

// Function that returns a Vector containing the parsed words
vector<string> SplitString(string S1, string delim = " ")
{
    vector<string> vWords;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        
        if (sWord != "")
        {
            vWords.push_back(sWord);
        }
        
        S1.erase(0, pos + delim.length());
    }

    // Push the remaining last word to the vector
    if (S1 != "")
    {
        vWords.push_back(S1);
    }

    return vWords;
}

// Utility function to print vector content
void PrintWords(vector<string> &vWords)
{
    cout << "\nYour string words are: \n";
    for (string &word : vWords)
    {
        cout << "\t" << word << endl;
    }
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #37 : Split String into a Vector";
    cout << "\n-------------------------------------------------\n\n";

    string str = ReadString("Please Enter your String : ");
    
    // Splitting the string and capturing the result in a vector
    vector<string> vWords = SplitString(str);
    
    cout << "\nYour string Tokens : " << vWords.size() << endl;
    PrintWords(vWords);

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• الحلول متطابقة تماماً. بناء دالة للتقطيع (Split) وإرجاع مصفوفة ديناميكية (Vector) هي مهارة أساسية ستحتاجها في قراءة ملفات قواعد البيانات والمستندات (مثل استخراج البيانات من ملفات CSV حيث تكون العناصر مفصولة بفاصلة ,).

## 🧩 Problem #38: Trim Left, Trim Right, Trim

### 📝 وصف المشكلة (Problem Description)

المطلوب كتابة دالة تقوم بإزالة المسافات الفارغة الزائدة (Spaces) من بداية النص (Trim Left)، ومن نهاية النص (Trim Right)، ودالة ثالثة تقوم بإزالتها من الاتجاهين معاً (Trim All).

### 💡 الفكرة البرمجية (Logic Breakdown)

• Trim Left: نمر على الكلمة من اليسار لليمين (من الفهرس 0). بمجرد أن نجد أول حرف "ليس مسافة"، نقوم باقتطاع النص من هذا الفهرس وحتى النهاية.

• Trim Right: نمر على الكلمة بالمعكوس (من اليمين لليسار، مبتدئين من length - 1). بمجرد أن نجد أول حرف "ليس مسافة"، نقتطع النص من البداية 0 وحتى هذا الحرف.

• Trim All: نقوم بتمرير النص لعملية TrimLeft، ونمرر النتيجة إلى TrimRight مباشرة (أو العكس).

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

// Remove leading spaces
string TrimLeft(string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            // Omit the second argument in substr to automatically take the rest of the string
            return str.substr(i); 
        }
    }
    return str; // If the string is all spaces, return it as is or handle accordingly
}

// Remove trailing spaces
string TrimRight(string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            return str.substr(0, i + 1); // +1 because length is index + 1
        }
    }
    return str;
}

// Remove both leading and trailing spaces
string TrimAll(string str)
{
    return TrimLeft(TrimRight(str));
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #38 : Trim Left, Trim Right, Trim All";
    cout << "\n-------------------------------------------------\n\n";

    // Simulating user input with spaces manually to show the effect
    string str = "      Hello World      ";
    
    cout << "Original String : [" << str << "]\n";
    cout << "Trim Left       : [" << TrimLeft(str) << "]\n";
    cout << "Trim Right      : [" << TrimRight(str) << "]\n";
    cout << "Trim All        : [" << TrimAll(str) << "]\n";

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• تألق ملحوظ في حلك! الدكتور استخدم الكود التالي في TrimLeft: return S1.substr(i, S1.length() - i);. ولكن حلك أنت return str.substr(i); هو الأفضل والأنظف (Cleaner Code)، لأن الدالة substr إذا لم تُعطها المعامل الثاني (الطول المطلوب)، فإنها تلقائياً تأخذ كل شيء حتى نهاية النص. أحسنت!

## 🧩 Problem #39: Join String

### 📝 وصف المشكلة (Problem Description)

هذه المسألة هي العملية العكسية لمسألة التقطيع (Split). المطلوب كتابة دالة JoinString تأخذ (Vector of Strings) وتقوم بدمج كافة عناصره لتكوين نص واحد متصل (String)، بحيث يتم الفصل بين الكلمات بـ Delimiter معين يتم تمريره (مثل المسافة، الفاصلة، أو الشَرطة).

### 💡 الفكرة البرمجية (Logic Breakdown)

• نُعرف متغيراً من نوع string sResult لتخزين النتيجة النهائية.

• نمر على كل كلمة في الـ Vector، ونقوم بلصق الكلمة + المحرف الفاصل delim داخل النتيجة.

• بعد نهاية الحلقة، سيكون هناك محرف فاصل "زائد" متصل بآخر كلمة. نستخدم دالة .erase (أو .substr) لحذفه من النتيجة النهائية.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to join a vector of strings into a single string
string JoinString(vector<string> &vWords, string delim = " ")
{
    string sResult;
    for (string &word : vWords)
    {
        sResult += word + delim;
    }
    
    // Remove the trailing delimiter
    if (sResult.length() > 0)
    {
        sResult.erase(sResult.length() - delim.length());
    }
    
    return sResult;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #39 : Join String (From Vector)";
    cout << "\n-------------------------------------------------\n\n";

    vector<string> vWords = {"Fars", "Alaa", "Mostafa"};
    
    cout << "Vector Items: Fars, Alaa, Mostafa\n";
    cout << "Joined with space : " << JoinString(vWords) << "\n";
    cout << "Joined with comma : " << JoinString(vWords, ", ") << "\n";
    cout << "Joined with dash  : " << JoinString(vWords, "-") << "\n";

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}
```

</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• الحلول منطقياً متطابقة وتعطي نفس النتيجة. في إزالة الفاصل الأخير الزائد، استخدم الدكتور دالة .substr للحصول على الجملة بدون الجزء الأخير، بينما استخدمت أنت الدالة التدميرية (Destructive Function) .erase لمسح الجزء الزائد في نفس المتغير. كلا الطريقتين صحيحتان ومقبولتان جداً في لغة C++.

## 🧩 Problem #40: Join String (Overloading)

### 📝 وصف المشكلة (Problem Description)

المطلوب توسيع إمكانيات دالة الدمج JoinString التي برمجناها في المسألة السابقة لكي تدعم (المصفوفات العادية - Standard Arrays) إلى جانب دعمها للمتجهات (Vectors).

### 💡 الفكرة البرمجية (Logic Breakdown)

• سنستخدم تقنية (التحميل الزائد للدوال - Function Overloading).

• نُعرّف دالة جديدة بنفس الاسم JoinString، ولكن هذه المرة البارامترات الخاصة بها مختلفة: ستستقبل مصفوفة string arr[] وتستقبل المتغير الخاص بطولها short length.

• نكتب حلقة تكرار مشابهة تقوم بدمج العناصر وإزالة المحرف الأخير.

### 💻 الكود المعتمد (Solution)

<div dir="ltr">

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. JoinString function for Vectors
string JoinString(vector<string> &vWords, string delim = " ")
{
    string sResult;
    for (string &word : vWords)
    {
        sResult += word + delim;
    }
    if (sResult.length() > 0)
    {
        sResult.erase(sResult.length() - delim.length());
    }
    return sResult;
}

// 2. Overloaded JoinString function for Standard Arrays
string JoinString(string words[], short length, string delim = " ")
{
    string sResult;
    for (short i = 0; i < length; i++)
    {
        sResult += words[i] + delim;
    }
    if (sResult.length() > 0)
    {
        sResult.erase(sResult.length() - delim.length());
    }
    return sResult;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "Problem #40 : Join String (Overloading with Array)";
    cout << "\n-------------------------------------------------\n\n";

    // Using Vector
    vector<string> vWords = {"Fars", "Alaa", "Mostafa"};
    cout << "Vector Joined   : " << JoinString(vWords, " ") << "\n";

    // Using Standard Array
    string arrWords[5] = {"Fars", "Alaa", "Mostafa", "Ahmed", "Ali"};
    cout << "Array Joined    : " << JoinString(arrWords, 5, " - ") << "\n";

    cout << "\n-------------------------------------------------\n\n";
    return 0;
}

```
</div>

### ⚖️ مقارنة حلي بحل الدكتور (Solution Comparison)

• تطابق تام (Perfect Match) في فهم واستخدام الـ Overloading. لغة C++ تكتشف نوع البيانات المرسل في الـ main وبناءً عليه تقرر استدعاء الدالة المناسبة (سواء النسخة الخاصة بالـ Vector أو النسخة الخاصة بالـ Array) بسلاسة.

</div>