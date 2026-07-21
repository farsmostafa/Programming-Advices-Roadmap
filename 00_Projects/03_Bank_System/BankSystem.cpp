#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
void BankSystem();
bool UserLogin();
const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";
const string Separator = "#//#";

enum enMainMenuOptions
{
    eShowClientsList = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClientInformation = 4,
    eFindClient = 5,
    eTransactions = 6,
    eManageUsers = 7,
    eLogout = 8
};
enum enTransactionsMenuOptions
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eMainMenuFromTransactionsMenu = 4
};
enum enManageUsersMenuOptions
{
    eListUsers = 1,
    eAddNewUser = 2,
    eDeleteUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    eMainMenuFromManageUsersMenu = 6
};

enum enUsersPermissions
{
    ShowClientsListPermission = 1,
    AddNewClientPermission = 2,
    DeleteClientPermission = 4,
    UpdateClientInfoPermission = 8,
    FindClientPermission = 16,
    TransactionsPermission = 32,
    ManageUsersPermission = 64,
    AllPermission = -1
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

struct stUser
{
    string Username;
    string Password;
    short Permissions;
    bool MarkForDelete = false;
};

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

char CheckInvalidAnswer_Yes_No(char Answer)
{
    while (tolower(Answer) != 'y' && tolower(Answer) != 'n')
    {
        cout << "Invalid input! Please enter (y for yes, n for no): ";
        cin >> Answer;
    }
    return Answer;
}

void ShowAccessDeniedMessage()
{
    cout << "-----------------------------------\n";
    cout << "Access Denied!\n";
    cout << "You don't have permission to access this feature.\n";
    cout << "Please contact Your Admin.\n";
    cout << "-----------------------------------\n";
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
string ConvertUserRecordToLine(stUser User, string Separator)
{
    string stUserRecord = "";
    stUserRecord += User.Username + Separator;
    stUserRecord += User.Password + Separator;
    stUserRecord += to_string(User.Permissions);
    return stUserRecord;
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
    Client.AccountBalance = stod(vClientData[4]);
    return Client;
}
stUser ConvertUserLinetoRecord(string str, string Separator)
{
    vector<string> vUserData = SplitString(str, Separator);
    if (vUserData.size() < 3)
    {
        return stUser(); // Return an empty user if the data is incomplete
    }
    stUser User;
    User.Username = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);
    return User;
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
vector<stUser> LoadUsersDataFromFile(string FileName)
{
    vector<stUser> vUsers;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (!MyFile.is_open())
    {
        cout << "\nUnable to open users file: [" << FileName << "]\n";
        return vUsers;
    }

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            stUser User = ConvertUserLinetoRecord(Line, Separator);
            if (!User.Username.empty()) // Check if the user record is valid
            {
                vUsers.push_back(User);
            }
        }
        MyFile.close();
    }
    return vUsers;
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

bool UserExistByUsername(vector<stUser> &vUsers, string Username, stUser &user)
{
    for (stUser &U : vUsers)
    {
        if (U.Username == Username)
        {
            user = U;
            return true;
        }
    }
    return false;
}

bool FindUserByUsernameAndPassword(vector<stUser> &vUsers, stUser &user)
{
    for (stUser &U : vUsers)
    {
        if (U.Username == user.Username && user.Password == U.Password)
        {
            user = U;
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

stUser ReadLoginInfo()
{
    stUser user;
    user.Username = ReadString("Enter Username: ");
    user.Password = ReadString("Enter Password: ");
    return user;
}

short ReadUserPermission()
{
    short permissions = 0;
    char addThisPermission = ReadChar("Do you want to give full access? (y/n) :");
    addThisPermission = CheckInvalidAnswer_Yes_No(addThisPermission);
    if (tolower(addThisPermission) == 'y')
    {
        permissions = -1;
    }
    else
    {
        cout << "Do you want to give access to :\n";
        addThisPermission = ReadChar("Show Client List? (y/n) :");
        addThisPermission = CheckInvalidAnswer_Yes_No(addThisPermission);
        if (tolower(addThisPermission) == 'y')
        {
            permissions += 1;
        }
        addThisPermission = ReadChar("Add New Client? (y/n) :");
        addThisPermission = CheckInvalidAnswer_Yes_No(addThisPermission);
        if (tolower(addThisPermission) == 'y')
        {
            permissions += 2;
        }
        addThisPermission = ReadChar("Delete Client? (y/n) :");
        addThisPermission = CheckInvalidAnswer_Yes_No(addThisPermission);
        if (tolower(addThisPermission) == 'y')
        {
            permissions += 4;
        }
        addThisPermission = ReadChar("Update Client? (y/n) :");
        addThisPermission = CheckInvalidAnswer_Yes_No(addThisPermission);
        if (tolower(addThisPermission) == 'y')
        {
            permissions += 8;
        }
        addThisPermission = ReadChar("Find Client? (y/n) :");
        addThisPermission = CheckInvalidAnswer_Yes_No(addThisPermission);
        if (tolower(addThisPermission) == 'y')
        {
            permissions += 16;
        }
        addThisPermission = ReadChar("Transactions? (y/n) :");
        addThisPermission = CheckInvalidAnswer_Yes_No(addThisPermission);
        if (tolower(addThisPermission) == 'y')
        {
            permissions += 32;
        }
        addThisPermission = ReadChar("Manage Users? (y/n) :");
        addThisPermission = CheckInvalidAnswer_Yes_No(addThisPermission);
        if (tolower(addThisPermission) == 'y')
        {
            permissions += 64;
        }

        if (permissions == 127)
            permissions = -1;
    }
    return permissions;
}

stUser ReadNewUser(vector<stUser> vUsers)
{
    stUser newUser;
    newUser.Username = ReadString("Enter Username: ");
    while (UserExistByUsername(vUsers, newUser.Username, newUser))
    {
        newUser.Username = ReadString("This Username already exists, please enter another Username: ");
    }
    newUser.Password = ReadString("Enter Password: ");
    newUser.Permissions = ReadUserPermission();
    return newUser;
}

void PrintClientRecord(stClient &Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(25) << left << Client.Name;
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
    cout << "| " << left << setw(25) << "Client Name";
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
void ShowClientsListScreen(vector<stClient> &vClients, stUser &UserAccount)
{
    cout << "========================================================================================================\n";
    cout << "                                        Bank System Clients List            \n";
    cout << "========================================================================================================\n\n";

    if (UserAccount.Permissions & enUsersPermissions::ShowClientsListPermission || UserAccount.Permissions & enUsersPermissions::AllPermission)
    {

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
            PrintAllClientsData(vClients);
    }
    else
    {
        ShowAccessDeniedMessage();
    }
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
        // system("cls");
        cout << "Adding New Client:\n\n";
        AddNewClient(vClients);
        cout << "\nClient data saved to file successfully, do you want to enter another client? (y/n) : ";
        cin >> AddAnotherClient;
        AddAnotherClient = CheckInvalidAnswer_Yes_No(AddAnotherClient);
    } while (tolower(AddAnotherClient) == 'y');
}

// Add New Clients Screen
void ShowAddNewClientScreen(vector<stClient> &vClients, stUser &UserAccount)
{
    cout << "========================================================================================================\n";
    cout << "                                   Bank System Add New Clients          \n";
    cout << "========================================================================================================\n\n";
    if (UserAccount.Permissions & enUsersPermissions::AddNewClientPermission || UserAccount.Permissions & enUsersPermissions::AllPermission)
    {
        AddClients(vClients);
    }
    else
    {
        ShowAccessDeniedMessage();
    }
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\n------------------------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n------------------------------------------------\n\n";
}
void PrintUserCard(stUser User)
{
    cout << "\nThe following are the User details:";
    cout << "\n------------------------------------------------";
    cout << "\nUsername    : " << User.Username;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << "\n------------------------------------------------\n\n";
}

// Find Client Screen
void ShowFindClientScreen(vector<stClient> &vClients, stUser &UserAccount)
{
    cout << "========================================================================================================\n";
    cout << "                                       Bank System Find Client             \n";
    cout << "========================================================================================================\n\n";

    if (UserAccount.Permissions & enUsersPermissions::FindClientPermission || UserAccount.Permissions & enUsersPermissions::AllPermission)
    {
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
    else
    {
        ShowAccessDeniedMessage();
    }
}

vector<stClient> SaveClientsDataToFile(vector<stClient> &vClients, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stClient &Client : vClients)
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
        while (tolower(Answer) != 'y' && tolower(Answer) != 'n')
        {
            cout << "Invalid input! Please enter (y for yes, n for no): ";
            cin >> Answer;
        }
        if (Answer == tolower('y'))
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
        return false;
    }
    return false;
}

// Delete Client Screen
void ShowDeleteClientScreen(vector<stClient> &vClients, stUser &UserAccount)
{
    cout << "========================================================================================================\n";
    cout << "                                    Bank System Delete Client           \n";
    cout << "========================================================================================================\n\n";
    if (UserAccount.Permissions & enUsersPermissions::DeleteClientPermission || UserAccount.Permissions & enUsersPermissions::AllPermission)
    {
        string AccountNumber = ReadString("Please enter the Account Number of the client you want to delete? ");
        DeleteClientByAccountNumber(vClients, AccountNumber);
    }
    else
    {
        ShowAccessDeniedMessage();
    }
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
        while (tolower(Answer) != 'y' && tolower(Answer) != 'n')
        {
            cout << "Invalid input! Please enter (y for yes, n for no): ";
            cin >> Answer;
        }
        if (Answer == tolower('y'))
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
        return false;
    }
    return false;
}

// Update Client Screen
void ShowUpdateClientInformationScreen(vector<stClient> &vClients, stUser &UserAccount)
{
    cout << "========================================================================================================\n";
    cout << "                              Bank System Update Client Info      \n";
    cout << "========================================================================================================\n\n";
    if (UserAccount.Permissions & enUsersPermissions::UpdateClientInfoPermission || UserAccount.Permissions & enUsersPermissions::AllPermission)
    {
        string AccountNumber = ReadString("Please enter the Account Number of the client you want to update? ");
        UpdateClientByAccountNumber(vClients, AccountNumber);
    }
    else
    {
        ShowAccessDeniedMessage();
    }
}

// Exit Screen
void ShowLogoutScreen()
{
    cout << "========================================================================================================\n";
    cout << "                                         Bank System Logout                   \n";
    cout << "========================================================================================================\n\n";
    cout << "Thank you for using our Bank System. Goodbye!\n";
    system("pause>0");
}

void ChangeClientAccountBalanceByAccountNumber(vector<stClient> &vClients, string AccountNumber, double Amount)
{
    bool ClientFound = false;
    while (!ClientFound)
    {
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
                cout << "\n\nHello " << C.Name << "Your balance has been updated successfully, your new balance is [" << C.AccountBalance << "]\n";
                break;
            }
        }
        if (!ClientFound)
        {
            cout << "\n\nClient with Account Number [" << AccountNumber << "] is not found\n";
            AccountNumber = ReadString("Please enter the Account Number of the client you want to deposit/withdraw to/from? ");
        }
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
        for (stClient &Client : vClients)
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

// Login Screen
void ShowLoginScreen()
{
    cout << "----------------------------------------\n";
    cout << "              Login Screen               \n";
    cout << "----------------------------------------\n";
}

// Main Menu Screen
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
    cout << "[7] Manage Users.\n";
    cout << "[8] Logout.\n";
    cout << "====================================================\n";
}

void ShowManageUsersScreen()
{
    cout << "========================================================================================================\n";
    cout << "                                          Manage Users Main Menu               \n";
    cout << "========================================================================================================\n";
    cout << "[1] List Users\n";
    cout << "[2] Add New User.\n";
    cout << "[3] Delete User.\n";
    cout << "[4] Update User.\n";
    cout << "[5] Find User.\n";
    cout << "[6] Main Menue.\n";
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

void GoBackToManageUsersMenu()
{
    cout << "\n\nPress any key to return to the manage users menu... ";
    system("pause>0");
    ClearScreen();
    ShowManageUsersScreen();
}

enum enMainMenuOptions ReadMainMenuOption()
{
    return (enMainMenuOptions)ReadPositiveNumberInRange(eShowClientsList, eLogout, "Please choose what do you want to do? ");
}

enum enTransactionsMenuOptions ReadTransactionsMenuOption()
{
    return (enTransactionsMenuOptions)ReadPositiveNumberInRange(eDeposit, eMainMenuFromTransactionsMenu, "Please choose what do you want to do? ");
}

enum enManageUsersMenuOptions ReadManageUsersMenuOption()
{
    return (enManageUsersMenuOptions)ReadPositiveNumberInRange(eListUsers, eMainMenuFromManageUsersMenu, "Please choose what do you want to do? ");
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

void TransactionsMenu(vector<stClient> &vClients, stUser &UserAccount)
{
    if (UserAccount.Permissions & enUsersPermissions::TransactionsPermission || UserAccount.Permissions & enUsersPermissions::AllPermission)
    {
        ShowTransactionsMenuScreen();
        while (true)
        {
            enTransactionsMenuOptions TransactionsMenuOption = ReadTransactionsMenuOption();
            if (TransactionsMenuOption == eMainMenuFromTransactionsMenu)
            {
                return;
            }
            PerformTransactionsMenuOption(TransactionsMenuOption, vClients);
        }
    }
    else
    {
        cout << "========================================================================================================\n";
        cout << "                                 Bank System Transactions Menu               \n";
        cout << "========================================================================================================\n\n";
        ShowAccessDeniedMessage();
    }
}

void PrintUserRecord(stUser &User)
{
    cout << "| " << setw(25) << left << User.Username;
    cout << "| " << setw(10) << left << User.Password;
    cout << "| " << setw(15) << left << User.Permissions;
}

void PrintAllUsersData(vector<stUser> &vUsers)
{
    cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
    cout << "\n________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(25) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(15) << "Permissions";
    cout << "\n________________________________________________________________________________________________\n\n";
    for (stUser &User : vUsers)
    {
        PrintUserRecord(User);
        cout << endl;
    }
    cout << "\n________________________________________________________________________________________________\n\n";
}

// List Users Screen
void ListUsersScreen(vector<stUser> &vUsers)
{
    PrintAllUsersData(vUsers);
}

void AddNewUser(vector<stUser> &vUsers)
{
    stUser User = ReadNewUser(vUsers);
    string stUserRecord = ConvertUserRecordToLine(User, Separator);
    AddDataLineToFile(UsersFileName, stUserRecord);
    vUsers.push_back(User);
}

void AddUsers(vector<stUser> &vUsers)
{
    char AddAnotherUser = 'y';
    do
    {
        cout << "Adding New User:\n\n";
        AddNewUser(vUsers);
        cout << "\nUser Added successfully, do you want to enter another User? (y/n) : ";
        cin >> AddAnotherUser;
        AddAnotherUser = CheckInvalidAnswer_Yes_No(AddAnotherUser);
    } while (tolower(AddAnotherUser) == 'y');
}

// Add New User Screen
void AddNewUsersScreen(vector<stUser> &vUsers)
{
    cout << "========================================================================================================\n";
    cout << "                                   Bank System Add New Users          \n";
    cout << "========================================================================================================\n\n";
    AddUsers(vUsers);
}

vector<stUser> SaveUsersDataToFile(vector<stUser> &vUsers, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stUser &User : vUsers)
        {
            if (!User.MarkForDelete)
            {
                MyFile << ConvertUserRecordToLine(User, Separator) << endl;
            }
        }
        MyFile.close();
    }
    return vUsers;
}

bool MarkUserForDeleteByUsername(string Username, vector<stUser> &vUsers)
{
    for (stUser &U : vUsers)
    {
        if (U.Username == Username)
        {
            U.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

bool DeleteUserByUsername(vector<stUser> &vUsers, string Username)
{
    stUser User;
    if (UserExistByUsername(vUsers, Username, User))
    {
        cout << "\n\nThe following is the extracted User record:\n";
        PrintUserCard(User);
        char Answer = 'n';
        cout << "\n\nAre you sure you want to delete this User? (y/n) : ";
        cin >> Answer;
        Answer = CheckInvalidAnswer_Yes_No(Answer);
        if (Answer == tolower('y'))
        {
            MarkUserForDeleteByUsername(Username, vUsers);
            SaveUsersDataToFile(vUsers, UsersFileName);
            vUsers = LoadUsersDataFromFile(UsersFileName);
            cout << "\nUser with Username [" << Username << "] is deleted successfully\n";
            return true;
        }
        else
        {
            cout << "\nUser with Username [" << Username << "] is not deleted\n";
            return false;
        }
    }
    else
    {
        cout << "\n\nUser with Username [" << Username << "] is not found\n";
        return false;
    }
    return false;
}

// Delete User Screen
void DeleteUserScreen(vector<stUser> &vUsers)
{
    cout << "========================================================================================================\n";
    cout << "                                   Bank System Delete User          \n";
    cout << "========================================================================================================\n\n";
    string Username = ReadString("Please enter the Username of the User you want to delete? ");
    if (Username == "Admin")
    {
        cout << "\n\nYou can't delete the Admin user!\n";
        return;
    }
    else
    {
        DeleteUserByUsername(vUsers, Username);
    }
}

stUser ChangeUserRecord(string Username)
{
    stUser User;
    User.Username = Username;
    User.Password = ReadString("Enter Password: ");
    User.Permissions = ReadUserPermission();
    return User;
}

bool UpdateUserByUsername(vector<stUser> &vUsers, string Username)
{
    stUser User;
    if (UserExistByUsername(vUsers, Username, User))
    {
        cout << "\n\nThe following is the extracted User record:\n";
        PrintUserCard(User);
        char Answer = 'n';
        cout << "\n\nAre you sure you want to update this User? (y/n) : ";
        cin >> Answer;
        Answer = CheckInvalidAnswer_Yes_No(Answer);
        if (Answer == tolower('y'))
        {
            for (stUser &U : vUsers)
            {
                if (U.Username == Username)
                {
                    U = ChangeUserRecord(Username);
                    break;
                }
            }
            SaveUsersDataToFile(vUsers, UsersFileName);
            cout << "\n\nUser with Username [" << Username << "] is Updated successfully\n";
            return true;
        }
        else
        {
            cout << "\n\nClient with Username [" << Username << "] is not Updated\n";
            return false;
        }
    }
    else
    {
        cout << "\n\nClient with Username [" << Username << "] is not found\n";
        return false;
    }
    return false;
}

// Update User Screen
void UpdateUserScreen(vector<stUser> &vUsers)
{
    cout << "========================================================================================================\n";
    cout << "                                   Bank System Update User          \n";
    cout << "========================================================================================================\n\n";
    string Username = ReadString("Please enter the Username of the User you want to update? ");
    if (Username == "Admin")
    {
        cout << "\n\nYou can't update the Admin user!\n";
        return;
    }
    else
    {
        UpdateUserByUsername(vUsers, Username);
    }
}

// Find User Screen
void FindUserScreen(vector<stUser> &vUsers)
{
    cout << "========================================================================================================\n";
    cout << "                                   Bank System Find User          \n";
    cout << "========================================================================================================\n\n";

    string Username = ReadString("Please enter the Username of the User you want to find? ");
    stUser User;
    if (UserExistByUsername(vUsers, Username, User))
    {
        PrintUserCard(User);
    }
    else
    {
        cout << "\n\nUser with Username [" << Username << "] is not found\n";
    }
}

void PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOption, vector<stUser> &vUsers)
{
    ClearScreen();
    switch (ManageUsersMenuOption)
    {
    case eListUsers:
        ListUsersScreen(vUsers);
        GoBackToManageUsersMenu();
        break;
    case eAddNewUser:
        AddNewUsersScreen(vUsers);
        GoBackToManageUsersMenu();
        break;
    case eDeleteUser:
        DeleteUserScreen(vUsers);
        GoBackToManageUsersMenu();
        break;
    case eUpdateUser:
        UpdateUserScreen(vUsers);
        GoBackToManageUsersMenu();
        break;
    case eFindUser:
        FindUserScreen(vUsers);
        GoBackToManageUsersMenu();
        break;
    default:
        break;
    }
}

void ManageUsersMenu(vector<stUser> &vUsers, stUser &UserAccount)
{
    if (UserAccount.Permissions & enUsersPermissions::ManageUsersPermission || UserAccount.Permissions & enUsersPermissions::AllPermission)
    {
        ShowManageUsersScreen();
        while (true)
        {
            enManageUsersMenuOptions ManageUsersMenuOption = ReadManageUsersMenuOption();
            if (ManageUsersMenuOption == eMainMenuFromManageUsersMenu)
            {
                return;
            }
            PerformManageUsersMenuOption(ManageUsersMenuOption, vUsers);
        }
    }
    else
    {
        cout << "========================================================================================================\n";
        cout << "                                          Manage Users Main Menu               \n";
        cout << "========================================================================================================\n\n";
        ShowAccessDeniedMessage();
    }
}

bool PerformMainMenuOption(enMainMenuOptions MainMenuOption, vector<stClient> &vClients, vector<stUser> &Users, stUser &UserAccount)
{
    ClearScreen();
    switch (MainMenuOption)
    {
    case eShowClientsList:
        ShowClientsListScreen(vClients, UserAccount);
        GoBackToMainMenu();
        return true;
    case eAddNewClient:
        ShowAddNewClientScreen(vClients, UserAccount);
        GoBackToMainMenu();
        return true;
    case eDeleteClient:
        ShowDeleteClientScreen(vClients, UserAccount);
        GoBackToMainMenu();
        return true;
    case eUpdateClientInformation:
        ShowUpdateClientInformationScreen(vClients, UserAccount);
        GoBackToMainMenu();
        return true;
    case eFindClient:
        ShowFindClientScreen(vClients, UserAccount);
        GoBackToMainMenu();
        return true;
    case eTransactions:
        TransactionsMenu(vClients, UserAccount);
        GoBackToMainMenu();
        return true;
    case eManageUsers:
        ManageUsersMenu(Users, UserAccount);
        GoBackToMainMenu();
        return true;
    case eLogout:
        ShowLogoutScreen();
        return false;
    default:
        return true;
    }
}

void BankSystem(stUser &UserAccount, vector<stUser> &vUsers)
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

    ClearScreen();
    ShowMainMenuScreen();
    while (true)
    {
        enMainMenuOptions MainMenuOption = ReadMainMenuOption();
        if (!PerformMainMenuOption(MainMenuOption, vClients, vUsers, UserAccount))
        {
            return;
        }
    }
}

bool UserLogin()
{
    ClearScreen();
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    if (vUsers.empty())
    {
        cout << "\nNo users were loaded from the file. Please check the users data file and its path.\n";
        system("pause>0");
        return false;
    }
    stUser user;
    ShowLoginScreen();
    while (true)
    {
        user = ReadLoginInfo();
        if (!FindUserByUsernameAndPassword(vUsers, user))
        {
            ClearScreen();
            ShowLoginScreen();
            cout << "\nInvalid Username/Password!\n\n";
        }
        else
        {
            break;
        }
    }
    BankSystem(user, vUsers);
    return true;
}

int main()
{
    while (true)
    {
        bool loginSuccess = UserLogin();
        if (!loginSuccess)
        {
            cout << "\nLogin failed. Exiting the program.\n";
            break;
        }
    }
    return 0;
}
