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

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #39 : Write a program to join vector of strings into a one string with separators\n";
    cout << "\tex  : vector of strings : Fars, Alaa, Mostafa\n";
    cout << "\toutput : your string is: Fars Alaa Mostafa\n";
    cout << "\n\n-------------------------------------------------\n\n";
    vector<string> vWords = {"Fars", "Alaa", "Mostafa"};
    cout << "\nYour string is: " << JoinString(vWords);

    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
