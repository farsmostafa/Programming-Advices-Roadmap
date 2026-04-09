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

int MinNumberInMatrix(int matrix[3][3], int rows, int cols)
{
    int min = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int MaxNumberInMatrix(int matrix[3][3], int rows, int cols)
{
    int max = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #19 : Write a program to print the intersected numbers in two given matrices.\n";
    cout << "\tex  : \n\t\tMatrix : \n\t\t44   5   2\n\t\t5   11   9\n\t\t1   2   33\n\n";
    cout << "\t\tOutput : The Minimum Number in the above matrix is : 1\n";
    cout << "\t\t         The Maximum Number in the above matrix is : 44\n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    int martrix[3][3];
    FillMatrixWithRandomNumbers(martrix, 3, 3);
    cout << "Matrix : \n\n";
    PrintMatrix(martrix, 3, 3);
    cout << "\nMinimum Number in the above matrix is : " << MinNumberInMatrix(martrix, 3, 3) << endl;
    cout << "Maximum Number in the above matrix is : " << MaxNumberInMatrix(martrix, 3, 3) << endl;
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n--------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
