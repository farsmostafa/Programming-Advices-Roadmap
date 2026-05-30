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
string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
                        sRepalceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
    return FormattedDateString;
}
int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #65 :Write a program to read Date and write a function to format that date.\n\n";
    cout << "\tex     : Please Enter Date dd/mm/yyyy? 31/3/2022\n";
    cout << "\t       : Please Enter New Format? yyyy/dd-mm\n";
    cout << "\toutput : 2022/31-3\n";
    cout << "\t       : Day: 31, Month: 3, Year: 2022\n";
    cout << "\n\n-------------------------------------------------\n\n";

    string dateString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");
    string formatString = ReadString("Please Enter New Format? ");
    sDate date = StringToDate(dateString);
    string FormattedDate = FormateDate(date, formatString);
    cout << "Formatted Date: " << FormattedDate;
    cout << "\nDay: " << date.Day << ", Month: " << date.Month << ", Year: " << date.Year;
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
