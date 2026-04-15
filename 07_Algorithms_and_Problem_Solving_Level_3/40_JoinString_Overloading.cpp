#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

string JoinString(vector<string> &vWords, string delim = " ")
{
    string sResult;
    for (string &word : vWords)
    {
        sResult += word + delim;
    }
    if (sResult.length() > 0)
    {
        sResult.erase(sResult.length() - delim.length());
    }
    return sResult;
}

string JoinString(string words[], short length, string delim = " ")
{
    string sResult;
    for (short i = 0; i < length; i++)
    {
        sResult += words[i] + delim;
    }
    if (sResult.length() > 0)
    {
        sResult.erase(sResult.length() - delim.length());
    }
    return sResult;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #40 : Write a program to join array of strings into a one string with separators\n";
    cout << "\tex  : vector of strings : Fars, Alaa, Mostafa\n";
    cout << "\toutput : your string is: Fars Alaa Mostafa\n";
    cout << "\n\n-------------------------------------------------\n\n";
    string words[5] = {"Fars", "Alaa", "Mostafa", "Ahmed", "Ali"};
    cout << "\nYour string is: " << JoinString(words, 5);

    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
