#include <iostream>

// zmienić program tak, aby jedna zmienna była przechowywana w main, a druga w klasie. wszystkie wywołania mają być poprzez this -> (pierwszym parametrem ma być sama funkcja)
// zrobić drugą klasę, która przechowuje stan
// wywalić zmienną op do main

class State
{
    int state;

public:
    State(int _state = 0)
    {
        this->state = _state;
    };

    void SetState(int _state) { state = _state; };
    int GetState() { return state; };
};

class MyInt
{
    int value;
    float a;
    State state;
    // int state = 0; // 0 - correct, 1 - error (/ 0), 2 - error (incorrect operator)
public:
    void setA(float x) { a = x; }

    int getvalue() { return (value); }

    int Add(int _b)
    {
        return (this->value + _b);
    }

    int Mul(int _b)
    {
        return (this->value * _b);
    }
    int Sub(int _b)
    {
        return (this->value - _b);
    }
    int Div(int _b)
    {
        if (_b != 0)
        {
            return (a / _b);
        }
        else
        {
            this->state.SetState(1);
            return (0);
        }
    }
    int Pow(int _b)
    {
        float c = this->value;
        for (float i = 1; i < _b; i++)
        {
            this->value = this->value * c;
        }
        return (this->value);
    }
    void SetState(int _state)
    {
        this->state.SetState(_state);
    }
    int getState(){
        this->state.GetState();
    }

    MyInt(int v)
    {
        this->value = v;
        state = State(0);
    };
};

using namespace std;

int main()
{
    int b;
    int z;
    char op;
    int result;

    cout << "Podaj a" << endl;
    cin >> z;
    MyInt obj(z);

    cout << "Podaj operator" << endl;
    cin >> op;

    cout << "Podaj b" << endl;
    cin >> b;

    switch (op)
    {
    case '+':
    {
        obj.Add(b);
        break;
    }
    case '-':
    {
        obj.Sub(b);
        break;
    }
    case '*':
    {
        obj.Mul(b);
        break;
    }
    case '/':
    {
        obj.Div(b);
        break;
    }
    case '^':
    {
        obj.Pow(b);
        break;
    }

    default:
        obj.SetState(2);
        break;
    }

    switch (obj.getState())
    {
    case 0:
    {
        cout << "Wynik to: " << result << endl;
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