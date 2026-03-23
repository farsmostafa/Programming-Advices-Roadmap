#include <iostream>
#include <math.h>
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

enum enPrimeNumber {Prime = 1 , NotPrime = 2};

enPrimeNumber CheckPrime(int number){
    int newNumber = sqrt(number); // sqrt better than number/2 because it is the biggest possible factor for a number
    for (int i = 2; i <= newNumber; i++)
    {
        if (number % i == 0)
        {
            return enPrimeNumber::NotPrime;
        }
        
    }
    return enPrimeNumber::Prime;
}

void PrintPrimeNumbersFrom_1_To_N(int number) {
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Prime numbers form 1 to " <<  number << " are : ";
    for (int i = 2; i <= number; i++)
    {
        if (CheckPrime(i) == enPrimeNumber::Prime)
        {
            cout << i << " ";
        }
        
    }
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}


int main()
{
    PrintPrimeNumbersFrom_1_To_N(ReadPositiveNumber("Please enter a positive number : "));
    return 0;
}
