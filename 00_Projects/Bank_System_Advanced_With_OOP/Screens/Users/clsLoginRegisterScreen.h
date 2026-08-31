#pragma once

class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void _PrintLoginRegisterTableHeader()
    {
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n"
             << endl;
    }
    
    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
    }

    static void _PrintLoginRegisterTableBody(vector<clsUser::stLoginRegisterRecord> &vLoginRegisterRecord )
    {

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }
    }

    static void _PrintLoginRegisterTableFooter()
    {
        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n"
             << endl;
    }

public:
    static void ShowLoginRegisterListScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
        {
            return;
        }
        vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        _PrintLoginRegisterTableHeader();
        _PrintLoginRegisterTableBody(vLoginRegisterRecord);
        _PrintLoginRegisterTableFooter();
    }
};