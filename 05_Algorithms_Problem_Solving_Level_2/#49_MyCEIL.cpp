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
int MyCeil(float number)
{
    if (abs(GetFractionPart(number)) > 0)
    {
        if (number > 0)
            return int(number) + 1;
        else
            return int(number);
    }
    else
        return number;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #49 : Write a program to print Ceil of numbers , don't use built in Ceil function\n ";
    cout << "\tex  : Enter a number : 5.5\n\t=>\tCeil of 5.5 is : 5\n\n";
    cout << "\tex  : Enter a number : -5.2\n\t=>\tCeil of -5.2 is : -5\n\n";
    cout << "------------------------\n\n";
    float number = ReadNumber("Enter a number : ");
    cout << "\nCeil of " << number << " is : " << MyCeil(number);
    cout << "\n\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
