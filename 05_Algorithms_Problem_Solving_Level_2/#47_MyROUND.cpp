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

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyRound(float Number)
{
    int IntPart = int(Number);

    float FractionsPart = GetFractionPart(Number);

    if (abs(FractionsPart) >= 0.5)
    {
        if (Number > 0)
            return ++IntPart;
        else
            return --IntPart;
    }
    else
    {
        return IntPart;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #47 : Write a program to print Round of numbers , don't use built in round function\n ";
    cout << "\tex  : Enter a number : 5.5\n\t=>\tRound of 5.5 is : 6\n\n";
    cout << "\tex  : Enter a number : -5.2\n\t=>\tRound of -5.2 is : -5\n\n";
    cout << "------------------------\n\n";
    float number = ReadNumber("Enter a number : ");
    cout << "\nRound of " << number << " is : " << MyRound(number);
    cout << "\n\n------------------------";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

    return 0;
}
