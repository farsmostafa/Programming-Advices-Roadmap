#include <iostream>
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

enum enPerfectNumber{PerfectNumber = 1 , NotPerfectNumber = 2};

enPerfectNumber IsPerfectNumber(int number){
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }

    return (sum == number ? enPerfectNumber::PerfectNumber : enPerfectNumber::NotPerfectNumber);
    
}
void PrintResults(int number)
{
     cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    switch (IsPerfectNumber(number))
    {
    case enPerfectNumber::PerfectNumber:
    
    cout << number << " Is Perfect number.";  
    break;
    case enPerfectNumber::NotPerfectNumber:
    cout << number << " Is NOT Perfect number."; 
    break;
    };
     cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}

int main()
{
    PrintResults(ReadPositiveNumber("Please enter a positive number: "));
    return 0;
}
