#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";
const string Separator = "#//#";
string ReadString(string message)
{
    string word;
    cout << message;
    getline(cin >> ws, word);
    return word;
}
char ReadChar(string message)
{
    char letter;
    cout << message;
    cin >> letter;
    return letter;
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

void AmountExceededBalanceMessage()
{
    cout << "\nThe amount exceeded your balance, make another choice.\n";
    cout << "Press any key to continue... ";
    system("pause>0");
    ClearScreen();
}

char CheckInvalidAnswer_Yes_No(char Answer)
{
    while (tolower(Answer) != 'y' && tolower(Answer) != 'n')
    {
        cout << "Invalid input! Please enter (y for yes, n for no): ";
        cin >> Answer;
    }
    return Answer;
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

enum en_ATM_MainMenuOptions
{
    eQuickWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5
};
enum en_ATM_QuickWithdrawOptions
{
    e20 = 1,
    e50 = 2,
    e100 = 3,
    e200 = 4,
    e400 = 5,
    e600 = 6,
    e800 = 7,
    e1000 = 8,
    eExit = 9
};

en_ATM_MainMenuOptions Read_ATM_MainMenuOption()
{
    return (en_ATM_MainMenuOptions)ReadPositiveNumberInRange(eQuickWithdraw, eLogout, "Choose what do you want to do? [1 to 5]: ");
}

en_ATM_QuickWithdrawOptions Read_ATM_QuickWithdrawOption()
{
    return (en_ATM_QuickWithdrawOptions)ReadPositiveNumberInRange(e20, eExit, "Choose what to withdraw from [1 to 9]: ");
}

stClient ReadLoginInfo()
{
    stClient Client;
    Client.AccountNumber = ReadString("Enter Account Number : ");
    Client.PinCode = ReadString("Enter Pin code        : ");
    return Client;
}

bool CheckLoginInfo(vector<stClient> &vClients, stClient &Client)
{
    for (stClient &C : vClients)
    {
        if (C.AccountNumber == Client.AccountNumber && C.PinCode == Client.PinCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
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
    if (vClientData.size() < 5)
    {
        return stClient(); // Return an empty client if the data is incomplete
    }
    stClient Client;
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    // to check that the balance is a valid number, we can use stod and catch any exceptions
    try
    {
        Client.AccountBalance = stod(vClientData[4]);
    }
    catch (const std::exception &e)
    {
        cout << "Error converting balance to double: " << e.what() << endl;
        Client.AccountBalance = 0.0; // Set a default value or handle the error as needed
    }
    return Client;
}

vector<stClient> LoadClientsDataFromFile(string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (!MyFile.is_open())
    {
        cout << "\nUnable to open clients file: [" << FileName << "]\n";
        return vClients;
    }

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            stClient Client = ConvertLinetoRecord(Line, Separator);
            if (!Client.AccountNumber.empty()) // Check if the client record is valid
            {
                vClients.push_back(Client);
            }
        }
        MyFile.close();
    }
    return vClients;
}

vector<stClient> SaveClientsDataToFile(vector<stClient> &vClients, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stClient &Client : vClients)
        {
            MyFile << ConvertRecordToLine(Client, Separator) << endl;
        }
        MyFile.close();
    }
    return vClients;
}

void ChangeClientAccountBalanceByAccountNumber(vector<stClient> &vClients, stClient &Client, double Amount)
{
    char Answer = ReadChar("Are you sure you want to proceed with this transaction? (y/n): ");
    Answer = CheckInvalidAnswer_Yes_No(Answer);
    if (tolower(Answer) == 'y')
    {

        for (stClient &C : vClients)
        {
            if (C.AccountNumber == Client.AccountNumber)
            {
                C.AccountBalance += Amount;
                Client.AccountBalance = C.AccountBalance; // Update the current client's balance
                cout << "\n\nDone Successfully, your new balance is [" << Client.AccountBalance << "]\n";
                SaveClientsDataToFile(vClients, ClientsFileName);
                break;
            }
        }
    }
    else
    {
        cout << "\n\nTransaction cancelled. Your balance remains [" << Client.AccountBalance << "]\n";
    }
}

bool PerformQuickWithdraw(vector<stClient> &vClients, stClient &Client, en_ATM_QuickWithdrawOptions ATM_QuickWithdrawOption)
{
    double Amount = 0;
    switch (ATM_QuickWithdrawOption)
    {
    case e20:
        Amount = 20;
        break;
    case e50:
        Amount = 50;
        break;
    case e100:
        Amount = 100;
        break;
    case e200:
        Amount = 200;
        break;
    case e400:
        Amount = 400;
        break;
    case e600:
        Amount = 600;
        break;
    case e800:
        Amount = 800;
        break;
    case e1000:
        Amount = 1000;
        break;
    default:
        return false;
    }

    if (Client.AccountBalance >= Amount)
    {
        ChangeClientAccountBalanceByAccountNumber(vClients, Client, -Amount);
        return true;
    }
    else
    {
        AmountExceededBalanceMessage();

        return false;
    }
}

void PrintQuickWithdrawOptions(stClient &Client)
{
    cout << "========================================================================================================\n";
    cout << "                                       ATM System Quick Withdraw             \n";
    cout << "========================================================================================================\n";
    cout << "                              [1] 20                               [2] 50                               \n";
    cout << "                              [3] 100                              [4] 200                              \n";
    cout << "                              [5] 400                              [6] 600                              \n";
    cout << "                              [7] 800                              [8] 1000                             \n";
    cout << "                              [9] Exit\n";
    cout << "========================================================================================================\n";
    cout << "Your Current Balance is: " << Client.AccountBalance << "\n\n";
}

// Quick Withdraw Screen
void ShowQuickWithdrawScreen(vector<stClient> &vClients, stClient &Client)
{
    PrintQuickWithdrawOptions(Client);
    en_ATM_QuickWithdrawOptions ATM_QuickWithdrawOption = Read_ATM_QuickWithdrawOption();
    if (ATM_QuickWithdrawOption != eExit)
    {
        while (!PerformQuickWithdraw(vClients, Client, ATM_QuickWithdrawOption))
        {
            PrintQuickWithdrawOptions(Client);
            ATM_QuickWithdrawOption = Read_ATM_QuickWithdrawOption();
            if (ATM_QuickWithdrawOption == eExit)
            {
                return;
            }
        }
    }
}

void PrintNormalWithdrawScreen(stClient &Client)
{
    cout << "========================================================================================================\n";
    cout << "                                       ATM System Normal Withdraw             \n";
    cout << "========================================================================================================\n";
    cout << "Your Current Balance is: " << Client.AccountBalance << "\n\n";
}

int ReadNormalWithdrawAmount()
{
    int amount = ReadPositiveNumberInRange(5, 1000000, "Enter an amount multiple of 5's : ");
    while (amount % 5 != 0)
    {
        amount = ReadPositiveNumberInRange(5, 1000000, "Enter an amount multiple of 5's : ");
    }
    return amount;
}


// Normal Withdraw Screen
void ShowNormalWithdrawScreen(vector<stClient> &vClients, stClient &Client)
{
    PrintNormalWithdrawScreen(Client);
    int Amount = ReadNormalWithdrawAmount();

    while (Amount > Client.AccountBalance)
    {
        AmountExceededBalanceMessage();
        PrintNormalWithdrawScreen(Client);
        Amount = ReadNormalWithdrawAmount();
    }
    ChangeClientAccountBalanceByAccountNumber(vClients, Client, -Amount);
}

void PrintDepositScreen(stClient &Client)
{
    cout << "========================================================================================================\n";
    cout << "                                       ATM System Deposit             \n";
    cout << "========================================================================================================\n";
    cout << "Your Current Balance is: " << Client.AccountBalance << "\n\n";
}

// Deposit Screen
void ShowDepositScreen(vector<stClient> &vClients, stClient &Client)
{
    PrintDepositScreen(Client);
    int Amount = ReadPositiveNumberInRange(1, 1000000, "Enter an positive deposit amount: ");
    ChangeClientAccountBalanceByAccountNumber(vClients, Client, Amount);
}

// Check Balance Screen
void ShowCheckBalanceScreen(stClient &Client)
{
    cout << "========================================================================================================\n";
    cout << "                                       ATM System Check Balance             \n";
    cout << "========================================================================================================\n\n";
    cout << "\nYour Current Balance is: " << Client.AccountBalance;
}

// Logout Screen
void ShowLogoutScreen()
{
    cout << "========================================================================================================\n";
    cout << "                                       ATM System Logout             \n";
    cout << "========================================================================================================\n\n";
    cout << "Thank you for using our ATM System. Goodbye!\n";
    system("pause>0");
}
void Show_ATM_MenuScreen()
{
    cout << "========================================================================================================\n";
    cout << "                                          ATM Main Menu Screen               \n";
    cout << "========================================================================================================\n";
    cout << "[1] Quick Withdraw.\n";
    cout << "[2] Normal Withdraw.\n";
    cout << "[3] Deposit.\n";
    cout << "[4] Check Balance.\n";
    cout << "[5] Logout.\n";
    cout << "====================================================\n";
}

void ShowLoginScreen()
{
    cout << "----------------------------------------\n";
    cout << "              Login Screen               \n";
    cout << "----------------------------------------\n";
}

void GoBackTo_ATM_MainMenu()
{
    cout << "\n\nPress any key to return to the ATM main menu... ";
    system("pause>0");
    ClearScreen();
    Show_ATM_MenuScreen();
}

bool Perform_ATM_MainMenuOption(en_ATM_MainMenuOptions ATM_MainMenuOption, vector<stClient> &vClients, stClient &CurrentClient)
{
    ClearScreen();
    switch (ATM_MainMenuOption)
    {
    case eQuickWithdraw:
        ShowQuickWithdrawScreen(vClients, CurrentClient);
        GoBackTo_ATM_MainMenu();
        return true;
    case eNormalWithdraw:
        ShowNormalWithdrawScreen(vClients, CurrentClient);
        GoBackTo_ATM_MainMenu();
        return true;
    case eDeposit:
        ShowDepositScreen(vClients, CurrentClient);
        GoBackTo_ATM_MainMenu();
        return true;
    case eCheckBalance:
        ShowCheckBalanceScreen(CurrentClient);
        GoBackTo_ATM_MainMenu();
        return true;
    case eLogout:
        ShowLogoutScreen();
        return false;
    default:
        return true;
    }
}

void ATM_System(vector<stClient> &vClients, stClient &CurrentClient)
{
    ClearScreen();
    Show_ATM_MenuScreen();
    while (true)
    {
        en_ATM_MainMenuOptions ATM_MainMenuOption = Read_ATM_MainMenuOption();
        if (!Perform_ATM_MainMenuOption(ATM_MainMenuOption, vClients, CurrentClient))
        {
            return;
        }
    }
}

bool ClientLogin()
{
    ClearScreen();
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    if (vClients.empty())
    {
        cout << "\nNo clients were loaded from the file. Please check the clients data file and its path.\n";
        system("pause>0");
        return false;
    }
    stClient client;
    ShowLoginScreen();
    while (true)
    {
        client = ReadLoginInfo();
        if (!CheckLoginInfo(vClients, client))
        {
            ClearScreen();
            ShowLoginScreen();
            cout << "\nInvalid Account Number/Pin Code!\n\n";
        }
        else
        {
            break;
        }
    }
    ATM_System(vClients, client);
    return true;
}

int main()
{
    while (true)
    {
        bool LoginSuccess = ClientLogin();
        if (!LoginSuccess)
        {
            cout << "\nLogin failed. Exiting the program.\n";
            break;
        }
    }
    return 0;
}