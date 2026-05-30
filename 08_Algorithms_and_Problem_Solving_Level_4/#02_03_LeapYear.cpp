#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadPositiveNumber(string message)
{

    int number;
    cout << message;
    cin >> number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Please enter a valid number: ";
        cin >> number;
    }
    return number;
}
bool IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #02 & 03 : Write a program to check if year is a leap year or not.\n";
    cout << "\tex     : Enter a year: 2023\n\n";
    cout << "\toutput : 2023 is not a leap year.\n";
    cout << "\tex2    : Enter a year: 2024\n\n";
    cout << "\toutput : 2023 is a leap year.\n";
    
    cout << "\n\n-------------------------------------------------\n\n";
    int year = ReadPositiveNumber("Enter a year: ");
    if (IsLeapYear(year))
    {
        cout << year << " is a leap year.\n";
    }
    else
    {
        cout << year << " is not a leap year.\n";
    }
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
