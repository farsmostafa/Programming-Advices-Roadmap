#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const string ClientsFileName = "Clients.txt";

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
void PrintClientRecord(stClient &Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintAllClientsData(vector<stClient> &vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s) .";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n\n\n";
    for (stClient &Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #48 : Write a program to read clients file and show them on the screen as follwows\n";
    cout << "\n\n-------------------------------------------------\n\n";
    vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    PrintAllClientsData(vClients);
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
