#include <iostream>
#include <string>

using namespace std;

class ClsCalculator
{
private:
    float _Result = 0;
    string _LastOperation = "None";
    float _PreviousValue = 0;

    bool _IsZero(float n) const
    {
        return (n == 0);
    }

public:
    void Add(float number)
    {
        _LastOperation = "Adding";
        _PreviousValue = _Result;
        _Result += number;
    }

    void Subtract(float number)
    {
        _LastOperation = "Subtracting";
        _PreviousValue = _Result;
        _Result -= number;
    }

    void Divide(float number)
    {
        if (_IsZero(number))
        {
            cout << "Error: Division by zero is not allowed. Operation skipped." << endl;
            return;
        }
        _LastOperation = "Dividing";
        _PreviousValue = _Result;
        _Result /= number;
    }

    void Multiply(float number)
    {
        _LastOperation = "Multiplying";
        _PreviousValue = _Result;
        _Result *= number;
    }
    void Undo()
    {
        _Result = _PreviousValue;
        _LastOperation = "Undo";
    }

    void Clear()
    {
        _Result = 0;
        _LastOperation = "Clear";
        _PreviousValue = 0;
    }

    void PrintResult() const
    {
        cout << "------------------------" << endl;
        cout << "Current Result: " << _Result << endl;
        cout << "Last Operation: " << _LastOperation << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    ClsCalculator cal1;

    cal1.Add(10);
    cal1.Multiply(5);
    cal1.Divide(0); // Testing the zero check
    cal1.PrintResult();

    cal1.Undo();
    cout << "After Undo:" << endl;
    cal1.PrintResult();

    return 0;
}
