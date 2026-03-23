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
void PrintPerfectNumbersFrom_1_To_N(int number) {
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
    cout << "Perfect numbers form 1 to " <<  number << " are : ";
    for (int i = 2; i <= number; i++)
    {
        if (IsPerfectNumber(i) == enPerfectNumber::PerfectNumber)
        {
            cout << i << " ";
        }
        
    }
    cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";
}


int main()
{
    PrintPerfectNumbersFrom_1_To_N(ReadPositiveNumber("Please enter a positive number : "));

    return 0;
}
