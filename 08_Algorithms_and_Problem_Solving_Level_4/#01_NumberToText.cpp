#include <iostream>
#include <string>
using namespace std;

long long ReadPositiveNumber(string message)
{
    long long number;
    cout << message;
    cin >> number;

    while (cin.fail() || number < 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Please enter a positive number: ";
        cin >> number;
    }
    return number;
}

string NumberToText(long long Number)
{
    if (Number == 0)
    {
        return "";
    }

    if (Number >= 1 && Number <= 19)
    {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 999999999999)
    {
        return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
    }

    return "";
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #01 : Write a program to read a number and print the text of that number.\n ";
    cout << "\tex     : Enter a Number? 5843\n";
    cout << "\toutput : Five Thousands Eight Hundreds Forty Three \n\n ";
    cout << "\n\n-------------------------------------------------\n\n";
    long long number = ReadPositiveNumber("Enter a Number? ");
    cout << "Output : " << NumberToText(number) << endl;
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
