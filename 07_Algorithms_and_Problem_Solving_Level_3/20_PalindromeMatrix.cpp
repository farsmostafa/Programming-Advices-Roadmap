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

bool IsPalindromeMatrix(int matrix[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != matrix[rows - 1 - i][cols - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #20 : Write a program to check it the matrix is Palindrome or not.\n";
    cout << "\tex  : \n\t\tMatrix : \n\t\t1   2   1\n\t\t2   3   2\n\t\t1   2   1\n\n";
    cout << "\t\tOutput : The above matrix is a Palindrome Matrix.\n\n";
    cout << "-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    cout << "Matrix : \n\n";
    PrintMatrix(martrix, 3, 3);
    if (IsPalindromeMatrix(martrix, 3, 3))
    {
        cout << "\nThe above matrix is a Palindrome Matrix.\n";
    }
    else
    {
        cout << "\nThe above matrix is not a Palindrome Matrix.\n";
    }
    int martix2[3][3] = {{1, 2, 1}, {2, 3, 2}, {1, 2, 1}};
    cout << "\nMatrix 2 : \n\n";
    PrintMatrix(martix2, 3, 3);
    if (IsPalindromeMatrix(martix2, 3, 3))
    {
        cout << "\nThe above matrix is a Palindrome Matrix.\n";
    }
    else
    {
        cout << "\nThe above matrix is not a Palindrome Matrix.\n";
    }
    cout << "\n-------------------------------------------------";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
