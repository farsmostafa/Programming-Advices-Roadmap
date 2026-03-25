#include <iostream>
using namespace std;


string ReadString(string message)
{
    string word;
    cout << message;
    cin >> word;
    return word;
}

bool GuessPassword(string OriginalPassword){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    string word = "";
    int counter = 0;
    for (short i = 65; i <= 90; i++)
    {
        for (short j = 65; j <= 90; j++)
        {
            for (short k = 65; k <= 90; k++)
            {
                word.append(1,char(i));
                word.append(1,char(j));
                word.append(1,char(k));
                counter++;
                cout << "Trial [" << counter << "] : " << word << endl;
                if (word == OriginalPassword)
                {
                    cout << "\n\n-------------------------------------------------\n\n";
                    cout << "Password is " << word << "\n";
                    cout << "Found after " << counter << " Trial(s)";
                    cout << "\n\n-------------------------------------------------\n\n";
                    return true;  
                }
                word="";
            }
            
        }
        
    }
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    return false;

}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to guess a 3-Letter Password (all capital)\n";
    cout <<"\tex  : AAF => \n\tTrail [1]: AAA \n\tTrail [2]: AAB \n\tTrail [3]: AAC \n\tTrail [4]: AAD \n\tTrail [5]: AAE \n\tTrail [6]: AAF \n\n\tPassword is AAF \n\tFound after 6 Trail(s)\n\n";
    GuessPassword(ReadString("Please enter a 3-Letter Password (all capital) : "));
    return 0;
}
