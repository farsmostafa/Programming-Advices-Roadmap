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
    bool MarkForDelete = false;
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

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
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

vector<stClient> SaveCleintsDataToFile(vector<stClient> &vClients, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stClient Client : vClients)
        {
            if (!Client.MarkForDelete)
            {
                MyFile << ConvertRecordToLine(Client) << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient> &vClients)
{
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

bool DeleteClientByAccountNumber(vector<stClient> &vClients, string AccountNumber)
{
    stClient Client;
    if (FindClientByAccountNumber(vClients, AccountNumber, Client))
    {
        cout << "\n\nThe following is the extracted client record:\n";
        PrintClientCard(Client);
        char Answer = 'n';
        cout << "\n\nAre you sure you want to delete this client? (y/n) : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Client.MarkForDelete = true;
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(vClients, ClientsFileName);
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nClient with Account Number [" << AccountNumber << "] is deleted successfully\n";
            return true;
        }
        else
        {
            cout << "\n\nClient with Account Number [" << AccountNumber << "] is not deleted\n";
            return false;
        }
    }
    else
    {
        cout << "\n\nClient with Account Number [" << AccountNumber << "] is not found\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #50 : Write a program to delete client by AccountNumber\n";
    cout << "\n\n-------------------------------------------------\n\n";
    vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadString("Please Enter Account Number of Client to Delete: ");
    DeleteClientByAccountNumber(vClients, AccountNumber);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
