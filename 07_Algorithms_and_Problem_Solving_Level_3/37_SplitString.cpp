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

vector<string> SplitString(string S1, string delim = " ")
{
    short counter = 0;
    vector<string> vWords;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vWords.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vWords.push_back(S1);
    }
    return vWords;
}

void PrintWords(vector<string> &vWords)
{
    cout << "\nYour string wrords are: \n";
    for (string &word : vWords)
    {
        cout << "\t" << word << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #37 : Write a program to read a string then make a function to split each word in vector.\n";
    cout << "\tex  : please enter your string : Fars Alaa Mostafa\n\n";
    cout << "\toutput : your string words: \n\t\tTokens : 3\n\t\tFars\n\t\tAlaa\n\t\tMostafa \n";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter your String : ");
    vector<string> vWords = SplitString(str);
    cout << "\nYour string Tokens : " << vWords.size() << endl;
    PrintWords(vWords);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
