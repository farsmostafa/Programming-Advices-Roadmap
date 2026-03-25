#include <iostream>
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

void PrintInvertedLetterPattern(int number){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "The Inverted Letter Pattern is : \n";
    for (int i = number; i >= 1; i--)
    {
        cout << "\t";
        for (int j = 0; j < i; j++)
        {
            cout << char(i+64);
        }
        cout << endl;
    }
    cout << "\n-------------------------------------------------------------------------------------------------\n\n";
    
}


int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to read a number and print inverted letter pattern as follows?\n";
    cout <<"\tex  : 3 => \n\t\tCCC \n\t\tBB \n\t\tA \n\t, 5 => \n\t\tEEEEE \n\t\tDDDD \n\t\tCCC \n\t\tBB \n\t\tA\n\n";
    PrintInvertedLetterPattern(ReadPositiveNumber("Enter Positive Number : "));
    return 0;
}
