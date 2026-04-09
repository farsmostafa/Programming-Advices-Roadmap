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

int CountNumberInMatrix(int matrix1[3][3], int number, int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix1[i][j] == number)
            {
                count++;
            }
        }
    }
    return count;
}

bool IsSparseMatrix(int matrix[3][3], int rows, int cols)
{
    int matrixSize = rows * cols;
    return CountNumberInMatrix(matrix, 0, rows, cols) >= ceil((float)matrixSize / 2);
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #16 : Write a program to check if the matrix is Sparce or not.\n";
    cout << "\tex  : \n\t\t0   3   0\n\t\t0   0   1\n\t\t0   0   33\n\n";
    cout << "\t\tIn the above matrix, there are 5 zeroes and 4 non-zero numbers.\n";
    cout << "\t\tThe above matrix is a Sparse Matrix because the number of zeroes is greater than or equal to the number of non-zero numbers.\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    cout << "Matrix 1: \n\n";
    PrintMatrix(martrix, 3, 3);
    if (IsSparseMatrix(martrix, 3, 3))
    {
        cout << "\nThe above matrix is a Sparse Matrix.\n";
    }
    else
    {
        cout << "\nThe above matrix is NOT a Sparse Matrix.\n";
    }

    int matrix2[3][3] = {{0, 3, 0}, {0, 0, 1}, {0, 0, 33}};
    cout << "\nMatrix 2: \n\n";
    PrintMatrix(matrix2, 3, 3);
    if (IsSparseMatrix(matrix2, 3, 3))
    {
        cout << "\nThe above matrix is a Sparse Matrix.\n";
    }
    else
    {
        cout << "\nThe above matrix is NOT a Sparse Matrix.\n";
    }
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
