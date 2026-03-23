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



int SumOfDigits(int number){
    int remainder,sum=0;
    while (number >0)
    {
        remainder = number%10;
        sum+=remainder;
        number/=10;
    }
    return sum;
}

void PrintSumOfDigits (int number){
cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Reverse of Number [ " << number << " ] is : [ " <<  SumOfDigits(number) <<" ]";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}


int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a Program to read a number and print the sum of its digits\n\tex  : 1234 => Sum Of Digits = 10\n\n";
    PrintSumOfDigits(ReadPositiveNumber("Enter Positive Number : "));
    return 0;
}
