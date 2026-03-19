### 💡 Lesson #14: `\n` vs `std::endl` (Performance & Memory)

In C++, both are used to insert a new line, but they handle the **Output Buffer** differently.
Understanding this is crucial for writing high-performance code.

#### 1. The Output Buffer Concept
The **Buffer** is a temporary storage area in memory. When you use `cout`,
the program doesn't send data to the screen immediately (which is a slow operation); instead,
it stores it in the buffer and sends it in batches to optimize performance.

#### 2. `\n` (Escape Character)
* **Behavior:** It only inserts a new line character into the buffer.
* **Flushing:** It **does NOT** force the buffer to flush (send data to the screen) immediately.
* **Performance:** **Very Fast.** It allows the system to manage the buffer efficiently.
* **Best Use Case:** When printing a large amount of text or inside loops where speed is a priority.

#### 3. `std::endl` (Manipulator)
* **Behavior:** It inserts a new line **AND** forces a `flush` operation.
* **Flushing:** It tells the operating system: "Stop what you are doing, empty the buffer, and show this on the screen right now."
* **Performance:** **Slower.** Frequent flushing causes overhead and slows down the program execution.
* **Best Use Case:** During debugging (to see output exactly when it happens) or when immediate feedback is required.

---

### 🚀 **Developer's Strategy (Performance Optimization)**

As a professional developer, you should balance speed and visibility:

* **Avoid `endl` in Heavy Loops:** Using `endl` inside a loop that runs thousands of times will significantly degrade performance.
* Use `\n` instead.
* **Selective Flushing:** Use `\n` for most of your output, and use `endl` only at the very end of a large output block					
  or when you specifically need to clear the buffer.

> **Note:** In Competitive Programming (ICPC), always prefer `\n` to avoid **Time Limit Exceeded (TLE)** errors caused by unnecessary flushing.




### 
###
###
###
###
### 
###
###
###
###




### 💡 Lesson: Handling Strings with `getline(cin, stringVariable)`

When reading text from the user, you need to understand the difference between the standard `cin >>` and the more powerful `getline()` function.

#### 1. The Problem with `cin >>`
* **Behavior:** It reads characters until it encounters **whitespace** (space, tab, or newline).
* **The Issue:** If a user enters `"Fars Ahmed"`, `cin >>` will only store `"Fars"` and leave `" Ahmed"` in the input buffer.
* **Best for:** Single words, numbers, or continuous strings with no spaces.

#### 2. The Solution: `getline(cin, variable)`
* **Behavior:** It reads the **entire line** of text until it hits a newline character (`\n`), including all spaces.
* **The Result:** If a user enters `"Fars Ahmed"`, the entire full name is stored in the string variable.
* **Syntax:** `getline(cin, myStringVariable);`

#### 3. ⚠️ Common Bug: `cin >>` followed by `getline()`
If you read a number with `cin >> age;` and then try to use `getline(cin, name);`, the `getline` will appear to be "skipped."

* **Why?** `cin >>` leaves the newline character (`\n`) in the buffer. `getline` sees that `\n` and thinks the line is finished.
* **The Fix:** Use `cin.ignore();` after the `cin >>` to clear the newline from the buffer.

---

### 📝 Code Example:

string fullName;
int age;

cout << "Enter your age: ";
cin >> age;

cin.ignore(1,'\n'); // Crucial: ignores the '\n' left by cin >>

cout << "Enter your full name: ";
getline(cin, fullName);

cout << "Hello " << fullName << ", your age is " << age << endl;



### 
###
###
###
###
### 
###
###
###
###



### 💡 Lesson: Variable Scope & Scope Resolution Operator (`::`)

In C++, you can have two variables with the same name if they are in different **Scopes**.
Understanding how the compiler decides which one to use is vital for avoiding logical bugs.

#### 1. Global vs. Local Scope
* **Global Variable:** Declared outside of any function. It is stored in the **Data Segment** of
                       memory and is accessible from anywhere in the file.
* **Local Variable:** Declared inside a function or a block `{ }`. 
                      It is stored in the **Stack** and is only visible within that block.

#### 2. The Conflict (Shadowing)
If a local variable has the same name as a global variable, the local variable **"Shadows"** the global one.
By default, the compiler will always pick the most "local" one.

#### 3. The Solution: `::` (Scope Resolution Operator)
To access the **Global** variable when a **Local** variable with the same name exists, we use the `::` prefix.

* **Syntax:** `::variableName` (This tells the compiler to look in the Global Scope).

---

### 📝 Code Example:
```c

#include <iostream>
using namespace std;

int x = 100; // Global variable

int main() {
    int x = 10; // Local variable (Shadows global x)

    cout << "Local x = " << x << endl;   // Prints 10
    cout << "Global x = " << ::x << endl; // Prints 100 (using ::)

    ::x = 500; // Modifying the global x directly
    cout << "New Global x = " << ::x << endl; // Prints 500

    return 0;
}