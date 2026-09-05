#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "../Core/clsUser.h"
#include "clsMainScreen.h"
#include "../Global/Global.h"

class clsLoginScreen : protected clsScreen
{
private:
    static bool _Login()
    {
        bool LoginFailed = false;
        short FailedLoginCount = 0;
        string Username, Password;

        do
        {
            if (LoginFailed)
            {
                cout << "\nInvlaid Username/Password!\n\n";
                FailedLoginCount++;
                cout << "You have " << 3- FailedLoginCount << " Trail(s) left!\n\n";
            }

            if (FailedLoginCount == 3)
            {
                cout << "\nYou are locked after 3 failed Trails, Contact your Admin!\n\n";
                return false;
            }


            cout << "Enter Username: ";
            cin >> Username;

            cout << "Enter Password: ";
            cin >> Password;
            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t    Login Screen");
        return _Login();
    }
};