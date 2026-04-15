#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

void PrintEachWordInString(string S1)
{
    string delim = " ";
    cout << "\nYour string wrords are: \n";
    short pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            cout << "\t" << sWord << endl;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        cout << "\t" << S1 << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #35 : Write a program to read a string then print each word in that string\n";
    cout << "\tex  : please enter your string : Fars Alaa Mostafa\n\n";
    cout << "\toutput : your string words :\n\t\tFars\n\t\tAlaa\n\t\tMostafa \n";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter your String : ");
    PrintEachWordInString(str);
    cout << "\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
