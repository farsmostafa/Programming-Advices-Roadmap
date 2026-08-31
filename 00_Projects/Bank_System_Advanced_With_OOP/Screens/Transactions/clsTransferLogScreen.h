#pragma once

#include <iostream>
#include "../clsScreen.h"
#include <iomanip>
#include <fstream>
#include "../../Core/clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

private:
    static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountBalanceAfter;
        cout << "| " << setw(8) << left << TransferLogRecord.CurrentUserName;
    }

    static void _PrintTransferLogScreenHeader()
    {
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
    static void _PrintTransferLogScreenBody(vector<clsBankClient::stTrnsferLogRecord> vTransferLogRecord)
    {
        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTrnsferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }
    }
    static void _PrintTransferLogScreenFooter()
    {
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

public:
    static void ShowTransferLogScreen()
    {

        vector<clsBankClient::stTrnsferLogRecord> vTransferLogRecord = clsBankClient::GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        _PrintTransferLogScreenHeader();
        _PrintTransferLogScreenBody(vTransferLogRecord);
        _PrintTransferLogScreenFooter();
    }
};