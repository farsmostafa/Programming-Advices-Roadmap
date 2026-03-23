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

int ReverseNumber(int number){
    int reversedNumber=0;
    while (number !=0)
    {
        reversedNumber = reversedNumber*10 + number%10;
        number/=10;
    }
    return reversedNumber;
}

void printDigits(int number){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Number Digits of Number [ " << number << " ] in Same order are : [  "; 
    short remainder;
    while (number >0)
    {
        remainder = number%10;
        number/=10;
        cout << remainder << "  ";
    }
    
    cout<<"]";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to read a number and print it in order from left to right.\n";
    cout << "\tex  : 1234 =>  1  2  3  4\n\n";

    int number = ReadPositiveNumber("Enter Positive Number : ");
    printDigits(ReverseNumber(number));
    return 0;
}
