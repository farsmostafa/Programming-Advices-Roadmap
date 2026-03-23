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

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : \n\tex  : \n\n";
    ReadPositiveNumber("Enter Positive Number : ");
    return 0;
}
int ReverseNumberDigits(int number){
    int reversedNumber=0;
    while (number !=0)
    {
        reversedNumber = reversedNumber*10 + number%10;
        number/=10;
    }
    return reversedNumber;
}