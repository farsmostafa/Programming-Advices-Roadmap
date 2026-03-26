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
float GetFractionPart(float number)
{
    return number - int(number);
}
int MyFloor(float number)
{
    float fractionPart = abs(GetFractionPart(number));
    if (fractionPart > 0)
        return (number > 0 ? int(number) : (int(number) - 1));
    else
        return number;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #48 : Write a program to print floor of numbers , don't use built in floor function\n ";
    cout << "\tex  : Enter a number : 5.5\n\t=>\tFloor of 5.5 is : 5\n\n";
    cout << "\tex  : Enter a number : -5.2\n\t=>\tFloor of -5.2 is : -5\n\n";
    cout << "------------------------\n\n";
    float number = ReadNumber("Enter a number : ");
    cout << "\nFloor of " << number << " is : " << MyFloor(number);
    cout << "\n\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
