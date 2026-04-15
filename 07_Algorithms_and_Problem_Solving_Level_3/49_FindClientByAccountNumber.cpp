#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const string ClientsFileName = "Clients.txt";

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

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

stClient ConvertLinetoRecord(string str, string delim = "#//#")
{
    vector<string> vClientData = SplitString(str, delim);
    stClient Client;
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}

vector<stClient> LoadCleintsDataFromFile(string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            vClients.push_back(ConvertLinetoRecord(Line));
        }
        MyFile.close();
    }
    return vClients;
}
void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(vector<stClient> &vClients, string AccountNumber, stClient &c)
{
    for (stClient &Client : vClients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            c = Client;
            return true;
        }
    }
    return false;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #49 : Write a program to find client by AccountNumber and print it to the screen:\n";
    cout << "\n\n-------------------------------------------------\n\n";
    vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    stClient Client;
    string AccountNumber = ReadString("Please Enter Account Number to Find Client : ");
    if (FindClientByAccountNumber(vClients, AccountNumber, Client))
    {
        cout << "\n\nThe following is the extracted client record:\n";
        PrintClientCard(Client);
    }
    else
    {
        cout << "\n\nClient with Account Number [" << AccountNumber << "] is not found\n";
    }

    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
