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

void ReadArray(int arr[], int &arrLength)
{
    cout << "\n\n------------\n\n";
    arrLength = ReadPositiveNumber("Enter how many elements in array : ");
    cout << "\nEnter array elements: \n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << "\n------------\n\n";
}
void PrintArray(int arr[], int arrLength)
{
    cout << "Array elements : ";
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool IsPalindromeArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[arrLength - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #41 : Write a program to fill array with numbers, then check if it is Palindrome array or not, \n\tNote : Palindrome array can be read the same from right to left and from left to right.\n ";
    cout << "\tex   : Enter how many number to be created in array : 5\n\t=>\tArray elements : 1 2 3 3 1\n\t\tYes, This is Palindrome Array\n\n";
    cout << "\tex   : Enter how many number to be created in array : 5\n\t=>\tArray elements : 1 2 3 4 5\n\t\tNo, This is Not Palindrome Array\n\n";
    cout << "------------------------\n\n";
    int arrLength, arr[100];
    ReadArray(arr, arrLength);
    PrintArray(arr, arrLength);
    if (IsPalindromeArray(arr, arrLength))
    {
        cout << "\nYes, This is Palindrome Array\n";
    }
    else
    {
        cout << "\nNo, This is Not Palindrome Array\n";
    }
    cout << "\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
