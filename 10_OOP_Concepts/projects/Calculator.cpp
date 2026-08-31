#include <iostream>

using namespace std;

class clsCalculator
{
private:
    float _PreviousResult = 0;
    float _Result = 0;
    string _LastOperation;
    float _LastNumber = 0;
    bool _IsZero(float value)
    {
        return (value == 0);
    }

public:
    void Add(float Value)
    {
        _PreviousResult = _Result;
        _Result += Value;
        _LastOperation = "Adding";
        _LastNumber = Value;
    }
    void Subtract(float Value)
    {
        _PreviousResult = _Result;
        _Result -= Value;
        _LastOperation = "Subtracting";
        _LastNumber = Value;
    }

    void Multiply(float Value)
    {
        _PreviousResult = _Result;
        _Result *= Value;
        _LastOperation = "Multiplying";
        _LastNumber = Value;
    }

    void Divide(float Value)
    {
        if (_IsZero(Value))
        {
            Value = 1;
        }
        _PreviousResult = _Result;
        _Result /= Value;
        _LastOperation = "Dividing";
        _LastNumber = Value;
    }

    void CancelLastOperation()
    {
        _LastNumber = 0;
        _LastOperation = "Cancelling Last Operation";
        _Result = _PreviousResult;
    }

    void Clear()
    {
        _PreviousResult = 0;
        _Result = 0;
        _LastOperation = "Clear";
        _LastNumber = 0;
    }

    void PrintResult()
    {
        cout << "Result After " << _LastOperation << " " << _LastNumber << " is: " << _Result << endl;
    }

    float GetFinalResult()
    {
        return _Result;
    }
};

int main()
{

    system("cls");
    clsCalculator Calculator1;
    Calculator1.Clear();
    Calculator1.Add(10);
    Calculator1.PrintResult();
    Calculator1.Add(100);
    Calculator1.PrintResult();
    Calculator1.Subtract(20);
    Calculator1.PrintResult();
    Calculator1.Divide(0);
    Calculator1.PrintResult();
    Calculator1.Divide(2);
    Calculator1.PrintResult();
    Calculator1.Multiply(3);
    Calculator1.PrintResult();
    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();
    Calculator1.Clear();
    Calculator1.PrintResult();
    system("pause>0");
    return 0;
}
