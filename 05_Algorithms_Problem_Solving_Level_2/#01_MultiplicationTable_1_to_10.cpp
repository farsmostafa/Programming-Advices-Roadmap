#include <iostream>
using namespace std;

void ColumnSeparator(int number)
{
    if(number < 10)
    {
        cout << number << "    |  ";
    }
    else
    {
        cout << number << "   |  ";
    }
}
void PrintMultiplicationTableHeader()
{

    cout << "\n\n                           Multiplication Table" << endl;
    cout << "        1     2     3     4     5     6     7     8     9     10" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
}
void PrintMultiplicationTable()
{
    PrintMultiplicationTableHeader();
    for (int i = 1; i <= 10; i++)
    {
        PrintMultiplicationOfNumber(i);
    }
}
void PrintMultiplicationOfNumber(int number)
{
    ColumnSeparator(number);
    
    for (int i = 1; i <= 10; i++)
    {
        cout << number * i << "\t";
    }
    cout << endl;
}


int main()
{
    PrintMultiplicationTable();
    return 0;
}
