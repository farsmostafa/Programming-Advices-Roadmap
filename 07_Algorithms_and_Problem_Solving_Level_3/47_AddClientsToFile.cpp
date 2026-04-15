#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin, word);
    return word;
}

stClient ReadNewClient()
{
    stClient Client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
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
void AddDataLineToFile(string FileName, string DataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;
        MyFile.close();
    }
}

void AddNewClient()
{
    stClient Client = ReadNewClient();
    string stClientRecord = ConvertRecordToLine(Client);
    AddDataLineToFile(ClientsFileName, stClientRecord);
}

void AddClients()
{
    char AddAnotherClient = 'y';
    do
    {
        system("cls");
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nClient data saved to file successfully, do you want to enter another client? (y/n) : ";
        cin >> AddAnotherClient;
    } while (tolower(AddAnotherClient) == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #47 : Write program to ask user to enter clients and save them to file\n";
    cout << "\tex  : \n\t\tinput :\n";
    cout << "\t\tEnter Accoutn Number? 12345\n";
    cout << "\t\tEnter PinCode? 54321\n";
    cout << "\t\tEnter Name? Ahmed Alaa\n";
    cout << "\t\tEnter Phone? 01000000000\n";
    cout << "\t\tEnter AccountBalance? 1000\n";
    cout << "\t\toutput : \n\t\tClient data saved to file successfully, do you want to enter another client? (y/n) : y\n";
    cout << "\t\tEnter Accoutn Number? 06789\n";
    cout << "\t\tEnter PinCode? 98765\n";
    cout << "\t\tEnter Name? Fawzy Alaa\n";
    cout << "\t\tEnter Phone? 01100000000\n";
    cout << "\t\tEnter AccountBalance? 2000\n";
    cout << "\t\toutput : \n\t\tClient data saved to file successfully, do you want to enter another client? (y/n) : n\n";
    cout << "\n\n-------------------------------------------------\n\n";
    AddClients();
    cout << "\n\n-------------------------------------------------\n\n";
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return 0;
}
