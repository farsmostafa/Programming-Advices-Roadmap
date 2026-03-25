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

enum enPalindrome {
    NotPalindrome=0,
    Palindrome=1
};

int ReverseNumber(int number){
    int reversedNumber=0;
    while (number !=0)
    {
        reversedNumber = reversedNumber*10 + number%10;
        number/=10;
    }
    return reversedNumber;
}

enPalindrome IsPalindrome(int number){
    return (number == ReverseNumber(number))? enPalindrome::Palindrome : enPalindrome::NotPalindrome;
}

void PrintResult (int number){
cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    if (IsPalindrome(number) == enPalindrome::Palindrome)
        cout << "Yes, Number [ " << number << " ] is Palindrome Number";
    else
        cout << "No, Number [ " << number << " ] is Not Palindrome Number";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}


int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to read a number and check if it is Palindrome?";
    cout << "\n       NOTE : Palindrome is a number that reads the same from right to left.\n";
    cout <<"\tex  : 1234 => No , 12321 => Yes\n\n";
    int number = ReadPositiveNumber("Enter Positive Number : ");
    PrintResult(number);
    return 0;
}
