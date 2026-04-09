#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
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

string ReadString(string message)
{
    string word;
    cout << message;
    cin >> word;
    return word;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        cout << "\t";
        for (int j = 0; j < cols; j++)
        {
            printf("%02d\t", matrix[i][j]);
        }
        cout << endl;
    }
}

bool IsNumberInMatrix(int matrix[3][3], int number, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}

bool PrintIntersectedNumbers(int matrix1[3][3], int matrix2[3][3], int rows, int cols)
{
    bool isFound = false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (IsNumberInMatrix(matrix2, matrix1[i][j], rows, cols))
            {
                isFound = true;
                cout << matrix1[i][j] << " ";
            }
        }
    }
    return isFound;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #18 : Write a program to print the intersected numbers in two given matrices.\n";
    cout << "\tex  : \n\t\tMatrix 1 : \n\t\t44   5   2\n\t\t5   11   9\n\t\t1   2   33\n\n";
    cout << "\t\tMatrix 2 : \n\t\t1   2   3\n\t\t4   5   6\n\t\t7   8   9\n\n";
    cout << "\t\tOutput : The Intersected Numbers in the above two matrices are : 5 2 1 9\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3], martrix2[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    FillMatrixWithRandomNumbers(martrix2, 3, 3);
    cout << "Matrix 1: \n\n";
    PrintMatrix(martrix, 3, 3);
    cout << "Matrix 2: \n\n";
    PrintMatrix(martrix2, 3, 3);
    cout << "\nThe Intersected Numbers in the above two matrices are : ";
    bool isFound = PrintIntersectedNumbers(martrix, martrix2, 3, 3);
    if (!isFound)
    {
        cout << "No Intersected Numbers are found in the above two matrices.\n";
    }
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
