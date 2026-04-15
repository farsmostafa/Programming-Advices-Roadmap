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

string TrimLeft(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            return str.substr(i);
        }
    }
    return str;
}
string TrimRight(string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            return str.substr(0, i + 1);
        }
    }
    return str;
}
string TrimAll(string str)
{
    return TrimLeft(TrimRight(str));
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #38 : Write a program to read a string then Trim Left, Right All.\n\n";
    cout << "\tex1  : please enter a string: Hello World\n";
    cout << "\toutput : Trim Left : Hello World\n";
    cout << "\t         Trim Right:     Hello World\n";
    cout << "\t         Trim All  : Hello World\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter a String: ");
    cout << "\nTrim Left : " << TrimLeft(str);
    cout << "\nTrim Right: " << TrimRight(str);
    cout << "\nTrim All  : " << TrimAll(str);
    cout << "\n\n-------------------------------------------------\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
