#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
void BankSystem();
const string ClientsFileName = "Clients.txt";
const string Separator = "#//#";
enum enMainMenuOptions
{
    eShowClientsList = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClientInformation = 4,
    eFindClient = 5,
    eTransactions = 6,
    eExit = 7
};
enum enTransactionsMenuOptions
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eMainMenu = 4
};

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin >> ws, word);
    return word;
}

int ReadPositiveNumberInRange(int From, int To, string message)
{

    int number;
    cout << message;
    cin >> number;

    while (cin.fail() || number < From || number > To)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Please enter a valid number: ";
        cin >> number;
    }
    return number;
}

void ClearScreen()
{
    system("cls");
}

vector<string> SplitString(string S1, string Separator)
{
    short counter = 0;
    vector<string> vWords;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Separator)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vWords.push_back(sWord);
        }
        S1.erase(0, pos + Separator.length());
    }
    if (S1 != "")
    {
        vWords.push_back(S1);
    }
    return vWords;
}

string ConvertRecordToLine(stClient Client, string Separator)
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

stClient ConvertLinetoRecord(string str, string Separator)
{
    vector<string> vClientData = SplitString(str, Separator);
    stClient Client;
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}

vector<stClient> LoadClientsDataFromFile(string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            vClients.push_back(ConvertLinetoRecord(Line, Separator));
        }
        MyFile.close();
    }
    return vClients;
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

stClient ReadNewClient(vector<stClient> &vClients)
{
    stClient Client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);
    while (FindClientByAccountNumber(vClients, Client.AccountNumber, Client))
    {
        cout << "Account Number already exists, please enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }
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

// Show Clients List Screen
void ShowClientsListScreen(vector<stClient> &vClients)
{
    cout << "========================================================================================================\n";
    cout << "                                        Bank System Clients List            \n";
    cout << "========================================================================================================\n\n";
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        PrintAllClientsData(vClients);
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

void AddNewClient(vector<stClient> &vClients)
{
    stClient Client = ReadNewClient(vClients);
    string stClientRecord = ConvertRecordToLine(Client, Separator);
    AddDataLineToFile(ClientsFileName, stClientRecord);
    vClients.push_back(Client);
}

void AddClients(vector<stClient> &vClients)
{
    char AddAnotherClient = 'y';
    do
    {
        system("cls");
        cout << "Adding New Client:\n\n";
        AddNewClient(vClients);
        cout << "\nClient data saved to file successfully, do you want to enter another client? (y/n) : ";
        cin >> AddAnotherClient;
    } while (tolower(AddAnotherClient) == 'y');
}

// Add New Clients Screen
void ShowAddNewClientScreen(vector<stClient> &vClients)
{
    cout << "========================================================================================================\n";
    cout << "                                   Bank System Add New Client          \n";
    cout << "========================================================================================================\n\n";
    AddClients(vClients);
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

// Find Client Screen
void ShowFindClientScreen(vector<stClient> &vClients)
{
    cout << "========================================================================================================\n";
    cout << "                                       Bank System Find Client             \n";
    cout << "========================================================================================================\n\n";
    string AccountNumber = ReadString("Please enter the Account Number of the client you want to find? ");
    stClient Client;
    if (FindClientByAccountNumber(vClients, AccountNumber, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\n\nClient with Account Number [" << AccountNumber << "] is not found\n";
    }
}

vector<stClient> SaveClientsDataToFile(vector<stClient> &vClients, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stClient Client : vClients)
        {
            if (!Client.MarkForDelete)
            {
                MyFile << ConvertRecordToLine(Client, Separator) << endl;
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
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(vClients, ClientsFileName);
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "\nClient with Account Number [" << AccountNumber << "] is deleted successfully\n";
            return true;
        }
        else
        {
            cout << "\nClient with Account Number [" << AccountNumber << "] is not deleted\n";
            return false;
        }
    }
    else
    {
        cout << "\n\nClient with Account Number [" << AccountNumber << "] is not found\n";
    }
}

// Delete Client Screen
void ShowDeleteClientScreen(vector<stClient> &vClients)
{
    cout << "========================================================================================================\n";
    cout << "                                    Bank System Delete Client           \n";
    cout << "========================================================================================================\n\n";
    string AccountNumber = ReadString("Please enter the Account Number of the client you want to delete? ");
    DeleteClientByAccountNumber(vClients, AccountNumber);
}

stClient ChangeClientRecord(string AccountNumber)
{
    stClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

bool UpdateClientByAccountNumber(vector<stClient> &vClients, string AccountNumber)
{
    stClient Client;
    if (FindClientByAccountNumber(vClients, AccountNumber, Client))
    {
        cout << "\n\nThe following is the extracted client record:\n";
        PrintClientCard(Client);
        char Answer = 'n';
        cout << "\n\nAre you sure you want to update this client? (y/n) : ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClient &C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveClientsDataToFile(vClients, ClientsFileName);
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "\n\nClient with Account Number [" << AccountNumber << "] is Updated successfully\n";
            return true;
        }
        else
        {
            cout << "\n\nClient with Account Number [" << AccountNumber << "] is not Updated\n";
            return false;
        }
    }
    else
    {
        cout << "\n\nClient with Account Number [" << AccountNumber << "] is not found\n";
    }
}

// Update Client Screen
void ShowUpdateClientInformationScreen(vector<stClient> &vClients)
{
    cout << "========================================================================================================\n";
    cout << "                              Bank System Update Client Info      \n";
    cout << "========================================================================================================\n\n";
    string AccountNumber = ReadString("Please enter the Account Number of the client you want to update? ");
    UpdateClientByAccountNumber(vClients, AccountNumber);
}

// Exit Screen
void ShowExitScreen()
{
    cout << "========================================================================================================\n";
    cout << "                                         Bank System Exit                   \n";
    cout << "========================================================================================================\n\n";
    cout << "Thank you for using our Bank System. Goodbye!\n";
    system("pause>0");
}

void ChangeClientAccountBalanceByAccountNumber(vector<stClient> &vClients, string AccountNumber, double Amount)
{
    bool ClientFound = false;
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            ClientFound = true;
            if (C.AccountBalance + Amount < 0)
            {
                cout << "\n\nSorry, you don't have enough balance to withdraw this amount, your current balance is [" << C.AccountBalance << "]\n";
                return;
            }
            C.AccountBalance += Amount;
            break;
        }
    }
    if (!ClientFound)
    {
        cout << "\n\nClient with Account Number [" << AccountNumber << "] is not found\n";
        return;
    }
    SaveClientsDataToFile(vClients, ClientsFileName);
    // reload the data from file to update the data in the file as well
}

// Deposit Screen
void ShowDepositScreen(vector<stClient> &vClients)
{
    cout << "========================================================================================================\n";
    cout << "                                         Bank System Deposit                   \n";
    cout << "========================================================================================================\n\n";
    int Amount = ReadPositiveNumberInRange(1, INT_MAX, "Please enter the amount you want to deposit? ");
    string AccountNumber = ReadString("Please enter the Account Number of the client you want to deposit to? ");
    ChangeClientAccountBalanceByAccountNumber(vClients, AccountNumber, Amount);
}

// Withdraw Screen
void ShowWithdrawScreen(vector<stClient> &vClients)
{
    cout << "========================================================================================================\n";
    cout << "                                         Bank System Withdraw                   \n";
    cout << "========================================================================================================\n\n";
    int Amount = ReadPositiveNumberInRange(1, INT_MAX, "Please enter the amount you want to withdraw? ");
    string AccountNumber = ReadString("Please enter the Account Number of the client you want to withdraw from? ");
    ChangeClientAccountBalanceByAccountNumber(vClients, AccountNumber, -Amount);
}

void PrintClientRecordBalanceLine(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void ShowTotalBalances(vector<stClient> &vClients)
{
    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    double TotalBalances = 0;
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (stClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;
            cout << endl;
        }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "\t\t\t\t\t Total Balances = " << TotalBalances;
}

// Total Balance Screen
void ShowTotalBalanceScreen(vector<stClient> &vClients)
{
    cout << "========================================================================================================\n";
    cout << "                                         Bank System Total Balance                   \n";
    cout << "========================================================================================================\n\n";
    ShowTotalBalances(vClients);
}

// Transactions Client Screen
void ShowTransactionsMenuScreen()
{
    cout << "========================================================================================================\n";
    cout << "                                 Bank System Transactions Menu               \n";
    cout << "========================================================================================================\n";
    cout << "[1] Deposit.\n";
    cout << "[2] Withdraw.\n";
    cout << "[3] Total Balance.\n";
    cout << "[4] Main Menu.\n";
    cout << "====================================================\n";
}

void ShowMainMenuScreen()
{
    cout << "========================================================================================================\n";
    cout << "                                      Bank System Main Menu               \n";
    cout << "========================================================================================================\n";
    cout << "[1] Show Clients List.\n";
    cout << "[2] Add New Client.\n";
    cout << "[3] Delete Client.\n";
    cout << "[4] Update Client Information.\n";
    cout << "[5] Find Client.\n";
    cout << "[6] Transactions.\n";
    cout << "[7] Exit.\n";
    cout << "====================================================\n";
}

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to return to the main menu... ";
    system("pause>0");
    ClearScreen();
    ShowMainMenuScreen();
}

void GoBackToTransactionsMenu()
{
    cout << "\n\nPress any key to return to the transactions menu... ";
    system("pause>0");
    ClearScreen();
    ShowTransactionsMenuScreen();
}

enum enMainMenuOptions ReadMainMenuOption()
{
    return (enMainMenuOptions)ReadPositiveNumberInRange(eShowClientsList, eExit, "Please choose what do you want to do? ");
}

enum enTransactionsMenuOptions ReadTransactionsMenuOption()
{
    return (enTransactionsMenuOptions)ReadPositiveNumberInRange(eDeposit, eMainMenu, "Please choose what do you want to do? ");
}

void PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption, vector<stClient> &vClients)
{
    ClearScreen();
    switch (TransactionsMenuOption)
    {
    case eDeposit:
        ShowDepositScreen(vClients);
        GoBackToTransactionsMenu();
        break;
    case eWithdraw:
        ShowWithdrawScreen(vClients);
        GoBackToTransactionsMenu();
        break;
    case eTotalBalance:
        ShowTotalBalanceScreen(vClients);
        GoBackToTransactionsMenu();
        break;

    default:
        break;
    }
}

void TransactionsMenu(vector<stClient> &vClients)
{
    ShowTransactionsMenuScreen();
    while (true)
    {
        enTransactionsMenuOptions TransactionsMenuOption = ReadTransactionsMenuOption();
        if (TransactionsMenuOption == enTransactionsMenuOptions::eMainMenu)
        {
            return;
        }
        PerformTransactionsMenuOption(TransactionsMenuOption, vClients);
    }
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOption, vector<stClient> &vClients)
{
    ClearScreen();
    switch (MainMenuOption)
    {
    case eShowClientsList:
        ShowClientsListScreen(vClients);
        GoBackToMainMenu();
        break;
    case eAddNewClient:
        ShowAddNewClientScreen(vClients);
        GoBackToMainMenu();
        break;
    case eDeleteClient:
        ShowDeleteClientScreen(vClients);
        GoBackToMainMenu();
        break;
    case eUpdateClientInformation:
        ShowUpdateClientInformationScreen(vClients);
        GoBackToMainMenu();
        break;
    case eFindClient:
        ShowFindClientScreen(vClients);
        GoBackToMainMenu();
        break;
    case eTransactions:
        TransactionsMenu(vClients);
        GoBackToMainMenu();
        break;
    case eExit:
        ShowExitScreen();
        exit(0);
        break;
    default:
        break;
    }
}

void BankSystem()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    ClearScreen();
    ShowMainMenuScreen();
    while (true)
    {
        enMainMenuOptions MainMenuOption = ReadMainMenuOption();
        PerformMainMenuOption(MainMenuOption, vClients);
    }
}

int main()
{
    BankSystem();
    return 0;
}
