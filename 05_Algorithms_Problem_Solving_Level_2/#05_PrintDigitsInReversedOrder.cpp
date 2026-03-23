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



void printDigits(int number){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Reversed Number Digits of Number [ " << number << " ] is : [  "; 
    short remainder;
    while (number >0)
    {
        remainder = number%10;
        number/=10;
        cout << remainder << "  ";
    }
    
    cout<<" ]";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "\n\nProblem #05 : Write a Program to read a number and print it in a reversed order \n\tex  : 1234 => 4 3 2 1\n\n";
    printDigits(ReadPositiveNumber("Enter Positive Number : "));
    return 0;
}
