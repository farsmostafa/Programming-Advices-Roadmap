#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

float ReadNumber(string message)
{
    float number;
    cout << message;
    cin >> number;
    return number;
}

float MySqrt(float number)
{
    return pow(number, 0.5);
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #50 : Write a program to print Sqrt of numbers , don't use built in Sqrt function\n ";
    cout << "\tex  : Enter a number : 25\n\t=>\tSqrt of 25 is : 5\n\n";
    cout << "------------------------\n\n";
    float number = ReadNumber("Enter a number : ");
    cout << "\nSqrt of " << number << " is : " << MySqrt(number);
    cout << "\n\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
