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

void PrintAllDigitsFrequencey(int number){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "All Digits Frequency in Number [ " << number << " ] is : \n";
    for (int i = 0; i <= 9; i++)
    {
        int digitFreq = CountDigitFrequency(i,number);
        if (digitFreq > 0)
        {
            cout << "\tDigit [ " << i << " ] Frequency is [ " <<digitFreq <<" ] time(s)\n";
        }
        
    }
    
    cout << "\n-------------------------------------------------------------------------------------------------\n\n";
}


int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program read a number , then print all digit frequency in that number\n";
    cout << "\tex  : 1223222  2  => \n\t\tDigit 1 Frequency is 1 time(s) \n\t\tDigit 2 Frequency is 5 time(s) \n\t\tDigit 3 Frequency is 1 time(s)\n\n";
    int number = ReadPositiveNumber("Enter Positive Number : ");
    PrintAllDigitsFrequencey(number);
    return 0;
}
