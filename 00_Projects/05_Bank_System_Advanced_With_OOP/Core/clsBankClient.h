#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "../Helpers/clsString.h"
#include "../Helpers/clsDate.h"
class clsBankClient : public clsPerson
{
private:
    string _PinCode;
    string _AccountNumber;
    float _AccountBalance;

    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;

    bool _MarkForDeleted = false;

    struct stTrnsferLogRecord;
    static stTrnsferLogRecord _ConvertTransferLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord TransferRecord;

        vector<string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
        TransferRecord.DateTime = LoginRegisterDataLine[0];
        TransferRecord.SourceAccountNumber = LoginRegisterDataLine[1];
        TransferRecord.DestinationAccountNumber = LoginRegisterDataLine[2];
        TransferRecord.Amount = stof(LoginRegisterDataLine[3]);
        TransferRecord.SourceAccountBalanceAfter = stof(LoginRegisterDataLine[4]);
        TransferRecord.DestinationAccountBalanceAfter = stof(LoginRegisterDataLine[5]);
        TransferRecord.CurrentUserName = LoginRegisterDataLine[6];
        return TransferRecord;
    }

    static clsBankClient _ConvertLinetoClientObject(string Line, string Separator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Separator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.FirstName + Separator;
        stClientRecord += Client.LastName + Separator;
        stClientRecord += Client.Email + Separator;
        stClientRecord += Client.Phone + Separator;
        stClientRecord += Client.AccountNumber() + Separator;
        stClientRecord += Client.PinCode + Separator;
        stClientRecord += to_string(Client.AccountBalance);
        return stClientRecord;
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::in); // read mode
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient> &vClients)
    {
        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::out); // write mode
        if (MyFile.is_open())
        {
            for (clsBankClient &Client : vClients)
            {
                if (!Client.MarkedForDeleted())
                {
                    string stClientRecord = _ConvertClientObjectToLine(Client);
                    MyFile << stClientRecord << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        for (clsBankClient &C : vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(vClients);
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::out | ios::app); // append mode
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    string _PrepareTransferLogRecord(clsBankClient DestinationClient, float Amount, string UserName,string seperator = "#//#")
    {
        string stTransferLine = "";
        stTransferLine += clsDate::GetSystemDateTimeString() + seperator;
        stTransferLine += _AccountNumber + seperator;
        stTransferLine += DestinationClient.AccountNumber() + seperator;
        stTransferLine += to_string(Amount) + seperator;
        stTransferLine += to_string(_AccountBalance) + seperator;
        stTransferLine += to_string(DestinationClient.AccountBalance) + seperator;
        stTransferLine += UserName;
        return stTransferLine;
    }


    void _RegisterTransferLog(clsBankClient DestinationClient, float Amount,string UserName)
    {
        string stDataLine = _PrepareTransferLogRecord(DestinationClient, Amount,UserName);
        fstream MyFile;
        MyFile.open("Data/TransferLog.txt", ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

public:
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _PinCode = PinCode;
        _AccountNumber = AccountNumber;
        _AccountBalance = AccountBalance;
    }

    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float SourceAccountBalanceAfter;
        float DestinationAccountBalanceAfter;
        string CurrentUserName;
    };
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    bool MarkedForDeleted()
    {
        return _MarkForDeleted;
    }

    static clsBankClient Find(string AccountNumber)
    {

        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }
    static clsBankClient Find(string AccountNumber, string PinCode)
    {

        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    enum enSaveResults
    {
        svFaildEmptyObject = 0,
        svSucceeded = 1,
        svFaildAccountNumberExists = 2
    };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }

        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
        case enMode::AddNewMode:
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;
        }

        return enSaveResults::svFaildEmptyObject;
    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsBankClient &C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDeleted = true;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);

        *this = _GetEmptyClientObject();
        return true;
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static float GetTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;
    }

    void Deposit(float Amount)
    {
        _AccountBalance += Amount;
        Save();
    }
    bool Withdraw(float Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    bool Transfer(float Amount, clsBankClient &DestinationClient,string UserName)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            Withdraw(Amount);
            DestinationClient.Deposit(Amount);
            _RegisterTransferLog(DestinationClient, Amount,UserName);
            return true;
        }
    }

    

    static vector<stTrnsferLogRecord> GetTransfersLogList()
    {
        vector<stTrnsferLogRecord> vTransferRecords;

        fstream MyFile;
        MyFile.open("Data/TransferLog.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTrnsferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLineToRecord(Line);

                vTransferRecords.push_back(TransferRecord);
            }

            MyFile.close();
        }

        return vTransferRecords;
    }
};
