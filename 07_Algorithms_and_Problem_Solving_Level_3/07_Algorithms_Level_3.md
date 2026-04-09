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

</div>
```
