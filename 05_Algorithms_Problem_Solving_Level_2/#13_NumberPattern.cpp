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

void PrintInvertedNumberPattern(int number){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    cout << "The Number Pattern is : \n";
    for (int i = 1; i <= number; i++)
    {
        cout << "\t";
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
    cout << "\n-------------------------------------------------------------------------------------------------\n\n";
    
}


int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to read a number and print inverted pattern as follows?\n";
    cout <<"\tex  : 3 => \n\t\t1 \n\t\t22 \n\t\t333 \n\t, 5 => \n\t\t1 \n\t\t22 \n\t\t333 \n\t\t4444 \n\t\t55555\n\n";
    PrintInvertedNumberPattern(ReadPositiveNumber("Enter Positive Number : "));
    return 0;
}
