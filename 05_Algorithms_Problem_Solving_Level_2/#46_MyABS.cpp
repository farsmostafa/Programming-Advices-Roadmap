#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

float ReadNumber(string message)
{
    float number;
    cout << message;
    cin >> number;
    return number;
}

float MyABS(float number)
{
    if (number < 0)
    {
        return -number;
    }
    else
    {
        return number;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #46 : WWrite a program to print abs of numbers , don't use built in abs function\n ";
    cout << "\tex  : Enter a number : 5\n\t=>\tAbs of 5 is : 5\n\n";
    cout << "\tex  : Enter a number : -5\n\t=>\tAbs of -5 is : 5\n\n";
    cout << "------------------------\n\n";
    float number = ReadNumber("Enter a number : ");
    cout << "\nAbs of " << number << " is : " << MyABS(number);
    cout << "\n\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
