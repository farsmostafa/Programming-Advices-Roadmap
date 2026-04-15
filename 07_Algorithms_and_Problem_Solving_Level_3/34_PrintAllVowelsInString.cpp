#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string ReadString(string message)
{
    string l;
    cout << message;
    getline(cin, l);
    return l;
}

bool IsVowel(char l)
{
    char lowerL = tolower(l);
    return (lowerL == 'a' || lowerL == 'e' || lowerL == 'i' || lowerL == 'o' || lowerL == 'u');
}

void PrintVowels(string str)
{
    for (short i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
        {
            cout << str[i] << " ";
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #34 : Write a program to read a string then Print all vowels in that strin (Vowels are: a, e ,i ,u ,o).\n\n";
    cout << "\tex1  : please enter a string: Hello World\n";
    cout << "\t\tVowels in string : e o o\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter a String: ");
    cout << "\nVowels in string : ";
    PrintVowels(str);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
