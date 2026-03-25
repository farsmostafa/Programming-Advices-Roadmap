#include <iostream>
#include <string> 
using namespace std;

void PrintAllFromAAAtoZZZ(){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    string word = "";
    for (short i = 65; i <= 90; i++)
    {
        for (short j = 65; j <= 90; j++)
        {
            for (short k = 65; k <= 90; k++)
            {
                word.append(1,char(i));
                word.append(1,char(j));
                word.append(1,char(k));
                cout << word << endl;
                word="";
            }
            
        }
        cout << "\n-------------------------------------------------\n";
        
    }
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    
}

int main()
{
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to print all words from AAA to ZZZ\n";
    cout <<"\tex  : \n\t\tAAA \n\t\tAAB \n\t\tAAC \n\t\t. \n\t\t. \n\t\t. \n\t\tZZZ\n\n";
    PrintAllFromAAAtoZZZ();
    return 0;
}
