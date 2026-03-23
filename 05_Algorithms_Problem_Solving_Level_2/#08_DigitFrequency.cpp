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

int CountDigitFrequency(short digitToCheck , int number){
    int remainder,freqCounter=0;
    while (number >0)
    {
        remainder = number%10;
        if (remainder == digitToCheck)
        {
            freqCounter++;
        }
        number/=10;
    }
    return freqCounter;
}
void PrintDigitFrequncy (int digit,int number){
cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Digit [ " << digit << " ] Frequency is [ " <<  CountDigitFrequency(digit,number) <<" ] time(s)";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}



int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program read a digit and a number , then print digit frequency in that number\n";
    cout << "\tex  : 1223222  2  => Digit 2 Frequency is 5 time(s)\n\n";
    int number = ReadPositiveNumber("Enter Positive Number : ");
    int digitToCheck = ReadPositiveNumber("Enter Digit To Count Its Frequency : ");
    PrintDigitFrequncy(digitToCheck,number);
    return 0;
}
