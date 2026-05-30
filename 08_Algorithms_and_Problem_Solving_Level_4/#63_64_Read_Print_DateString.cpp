#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string ReadString(string Message)
{
    string sInput;
    cout << Message;
    getline(cin >> ws, sInput);
    return sInput;
}

struct sDate
{
    short Year;
    short Month;
    short Day;
};

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
        return vString;
    }
}
string DateToString(sDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) +
           "/" + to_string(Date.Year);
}
sDate StringToDate(string DateString)
{
    sDate Date;
    vector<string> vDate;
    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}
string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #63 & #64 :Write a program to\n\n";
    cout << "\t1- Read Date String.\n";
    cout << "\t2- Convert it to date structure.\n";
    cout << "\t3- Print Day, Month, Year separately.\n";
    cout << "\t4- Then convert Date Structure to string and print it on the screen.";
    cout << "\tex     : Please Enter Date dd/mm/yyyy? 31/3/2022\n";
    cout << "\toutput : Day: 31\n";
    cout << "\t\t\tMonth: 3\n";
    cout << "\t\t\tYear: 2022\n";
    cout << "\t\t\tDate: 31/3/2022\n";
    cout << "\n\n-------------------------------------------------\n\n";

    string dateString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");
    sDate date = StringToDate(dateString);
    cout << "\nDay: " << date.Day;
    cout << "\nMonth: " << date.Month;  
    cout << "\nYear: " << date.Year;
    cout << "\nDate: " << DateToString(date);

    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
