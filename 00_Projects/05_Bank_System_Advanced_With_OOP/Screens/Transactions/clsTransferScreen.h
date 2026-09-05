#pragma once
#include "../clsScreen.h"
#include "../../Core/clsBankClient.h"
#include "../../Helpers/clsInputValidate.h"
#include "../../Global/Global.h"
class clsTransferScreen : protected clsScreen
{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber = "";
        cout << "\n"
             << Message;
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient)
    {
        cout << "\nEnter Amount: ";
        float Amount = clsInputValidate::ReadFloatNumber();
        while (SourceClient.AccountBalance < Amount)
        {
            cout << "\nAccount Exceeded the available balance, please enter another amount: ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\tTransfer Screen");
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number to Transfer From: "));
        _PrintClient(SourceClient);
        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number to Transfer To: "));
        _PrintClient(DestinationClient);

        float Amount = _ReadAmount(SourceClient);

        cout << "\nAre you sure you want to perform this operation [y/n] ? ";
        char Answer = 'n';
        cin >> Answer;
        while (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n')
        {
            cout << "\nAre you sure you want to perform this transaction [y/n] ? ";
            cin >> Answer;
        }

        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))

            {
                cout << "\nTransfer Operation Done Successfully.\n";
            }
            else
            {
                cout << "\nTransfer Operation Failed.\n";
            }
        }
        else
        {
            cout << "\nTransfer Operation Canceled.\n";
        }
        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);
    }
};