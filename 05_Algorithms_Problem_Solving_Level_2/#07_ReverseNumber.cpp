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
void PrintReversedNumber (int number){
cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Reverse of Number [ " << number << " ] is : [ " <<  ReverseNumber(number) <<" ]";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to read a number and print it reversed\n\tex  : 1234 => 4321\n\n";
    PrintReversedNumber(ReadPositiveNumber("Enter Positive Number : "));
    return 0;
}
