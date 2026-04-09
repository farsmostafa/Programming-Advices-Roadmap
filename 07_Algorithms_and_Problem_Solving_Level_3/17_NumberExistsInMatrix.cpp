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

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #17 : Write a program to check if a given number exists in matrix or not.\n";
    cout << "\tex  : \n\t\t44   5   2\n\t\t5   11   9\n\t\t1   2   33\n\n";
    cout << "\t\tInput : Enter number to check : 11\n\n";
    cout << "\t\tOutput : The Number 11 is found in the matrix.\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    cout << "Matrix 1: \n\n";
    PrintMatrix(martrix, 3, 3);
    int number = ReadPositiveNumber("\nEnter number to check : ");
    if (IsNumberInMatrix(martrix, number, 3, 3))
    {
        cout << "\nThe Number " << number << " is found in the matrix.\n";
    }
    else
    {
        cout << "\nThe Number " << number << " is NOT found in the matrix.\n";
    }

    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
