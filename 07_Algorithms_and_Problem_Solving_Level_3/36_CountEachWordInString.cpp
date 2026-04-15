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

short CountWords(string S1)
{
    short counter = 0;
    string delim = " ";
    short pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            counter++;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        counter++;
    }
    return counter;
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #36 : Write a program to read a string then count each word in that string\n";
    cout << "\tex  : please enter your string : Fars Alaa Mostafa\n\n";
    cout << "\toutput : your string words count : 3";
    cout << "\n\n-------------------------------------------------\n\n";
    string str = ReadString("Please Enter your String : ");
    cout << "\nYour string words count : " << CountWords(str);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
