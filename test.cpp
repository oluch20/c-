#include <iostream>

class MyInt
{
    float a;
    float b;
    char op;
    int state = 0; // 0 - correct, 1 - error (/ 0), 2 - error (incorrect operator)
    float result;
public:
    void setA(float x) { a = x; }
    void setB(float x) { b = x; }
    void setOp(char x) { op = x; }
    void SetState(int x) { state = x; }


    char getOp() { return (op); }
    int getState() {return (state);}
    float getResult() { return (result); }

    void Add()
    {
        result = (a + b);
    }

    void Mul()
{
    result = (a * b);
}
void Sub()
{
    result = (a - b);
}
void Div()
{
    if (b != 0)
    {
        result = (a / b);
    }
    else
    {
        state = 1;
    }
}
void Pow()
{
    float c = a;
    for (float i = 1; i < b; i++)
    {
        a = a * c;
    }
    result = (a);
}
};

using namespace std;

int main()
{
    float z;
    char op;
    MyInt f;

    cout << "to jest kalkulator, podaj a" << endl;
    cin >> z;
    f.setA(z);

    cout << "to jest kalkulator, podaj operator" << endl;
    cin >> op;
    f.setOp(op);

    cout << "to jest kalkulator, podaj b" << endl;
    cin >> z;
    f.setB(z);

    switch (f.getOp())
    {
    case '+':
    {
        f.Add();
         break;
    }
    case '-':
    {
        f.Sub();
        break;
    }
    case '*':
    {
        f.Mul();
        break;
    }
    case '/':
    {
        f.Div();
        break;
    }
    case '^':
    {
        f.Pow();
        break;
    }

    default:
        f.SetState(2);
        break;
    }

    switch (f.getState())
    {
    case 0:
    {
        cout << "Wynik to: " << f.getResult() << endl;
        break;
    }
    break;
    case 1:
    {
        cout << "błąd, nie dziel przez 0 !" << endl;
        break;
    }
    case 2:
    {
        cout << "błąd, nie znany operator!" << endl;
    }

    default:
        break;
    }

    return (0);
}