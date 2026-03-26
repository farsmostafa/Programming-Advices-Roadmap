#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 0);

    return number;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArrayWithRandomNumbers(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[], int arrLength)
{
    cout << "\nArray elements : ";
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int OddCount(int arr[], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #42 : Write a program to fill array with max size 100 with random numbers from 1 to 100, then print the count of Odd numbers.\n";
    cout << "\tex   : Enter how random many number to be created in array : 5\n\t=>\tArray elements : 55 96 99 6 61\n\t\tCount of Odd numbers in array : 3\n\n";
    cout << "------------------------\n\n";
    int arrLength, arr[100];
    arrLength = ReadPositiveNumber("Enter how many random number to be created in array : ");
    FillArrayWithRandomNumbers(arr, arrLength);
    PrintArray(arr, arrLength);
    cout << "Count of Odd numbers in array : " << OddCount(arr, arrLength) << endl;
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
