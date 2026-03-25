#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>  
using namespace std;


int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum; 
}
enum enCharType { 
    SamallLetter = 1,    
    CapitalLetter = 2,   
    SpecialCharacter = 3,
    Digit = 4            
};
char GetRandomCharacter(enCharType CharType)
{
    char character;
    switch (CharType)
    {
    case SamallLetter:
        character = RandomNumber('a', 'z');
        break;
    case CapitalLetter:
        character = RandomNumber('A', 'Z');
        break;
    case SpecialCharacter:
        character = RandomNumber(33, 47);
        break;
    case Digit:
        character = RandomNumber('0', '9');
        break;
    default:
        character = '?';
        break;
    }
    return character;
}



void printResult(){
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Small Letter : " << GetRandomCharacter(SamallLetter) << endl;
    cout << "Capital Letter : " << GetRandomCharacter(CapitalLetter) << endl;
    cout << "Special Character : " << GetRandomCharacter(SpecialCharacter) << endl;
    cout << "Digit : " << GetRandomCharacter(Digit) << endl;
    cout << "\n-------------------------------------------------------------------------------------------------\n\n";
}


int main()
{
    srand((unsigned)time(NULL));
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Problem #05 : Write a program to print random Small Letter, Capital Letter, Special Character, and Digit in order.\n";
    cout <<"\tex  :    a    A    $    7\n\n";
    printResult();


    return 0;
}
