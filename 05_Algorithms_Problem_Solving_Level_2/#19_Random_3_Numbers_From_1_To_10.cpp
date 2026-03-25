#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>  
using namespace std;


int ReadPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 0);
    
    return number;
}

string ReadString(string message)
{
    string word;
    cout << message;
    cin >> word;
    return word;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum; 
}

void printResult(){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "1-RandomNumber : " << RandomNumber(1,10)<<endl;
    cout << "2-RandomNumber : " << RandomNumber(1,10)<<endl;
    cout << "3-RandomNumber : " << RandomNumber(1,10)<<endl;
    cout << "\n-------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to print 3 random numbers from 1 to 10\n";
    printResult();
    return 0;
}
