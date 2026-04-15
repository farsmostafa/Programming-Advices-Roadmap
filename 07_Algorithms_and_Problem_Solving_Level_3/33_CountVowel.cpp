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

short CountVowels(string str)
{
    short count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #33 : Write a program to read a string then count all vowels in that strin (Vowels are: a, e ,i ,u ,o).\n\n";
    cout << "\tex1  : please enter a string: Hello World\n";
    cout << "\t\tNumber of Vowels in string \"Hello World\" is: 3";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter a String: ");
    cout << "\nNumber of Vowels in string is: " << CountVowels(str);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
