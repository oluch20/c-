#include <iostream>
using namespace std;

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

class MyVariable
{
    int a;
    int b;
    char myOperator;
    float result;

public:
    // ------ a ------
    void setA(int x) { a = x; }
    int getA() { return (a); }

    // ------ b ------
    void setB(int x) { b = x; }
    int getB() { return (b); }

    // ------ myOperator ------
    void setOperator(char x) { myOperator = x; }
    char getOperator() { return (myOperator); }

    // ------ result ------
    void setResult(float x) { result = x; }
    int getResult() { return (result); }

    // ------ constructor ------

    // MyVariable(int _a, int _b)
    // {
    //     this->a = _a;
    //     this->b = _b;
    // };
    MyVariable() {};
};

class Calc
{
    MyVariable variable;

    // 0 - correct, 1 - error (/ 0), 2 - error (incorrect operator)
    State state;

public:
    Calc()
    {
        variable = MyVariable();
        state = State(0);
    }

    // ------------- variable -------------

    //set
    void setA(int _a) { this->variable.setA(_a); }
    void setB(int _b) { this->variable.setB(_b); }
    void setOperator(char _myOperator) { this->variable.setOperator(_myOperator); }
    //get
    char getOperator () {return (this->variable.getOperator()); }
    float getResult() { return (this->variable.getResult()); }

    // ------------- State -------------

    int getState()
    {
        return (this->state.GetState());
    }
    void SetState(int _state)
    {
        this->state.SetState(_state);
    }

    // ------------- operations -------------

    void Add()
    {
        this->variable.setResult(this->variable.getA() + this->variable.getB());
    }

    void Mul()
    {
        this->variable.setResult(this->variable.getA() * this->variable.getB());
    }
    void Sub()
    {
        this->variable.setResult(this->variable.getA() + this->variable.getB());
    }
    void Div()
    {
        if (this->variable.getB() != 0)
        {
            this->variable.setResult(this->variable.getA() / this->variable.getB());
        }
        else
        {
            this->state.SetState(1);
        }
    }
    void Pow()
    {
        int temp = this->variable.getA();
        for (float i = 1; i < this->variable.getB(); i++)
        {
            temp = temp * this->variable.getB();
        }
        this->variable.setResult(temp);
    }
};

int main()
{

    int z;
    char _myOperator;
    Calc obj;

    cout << "Podaj a" << endl;
    cin >> z;
    obj.setA(z);

    cout << "Podaj operator" << endl;
    cin >> _myOperator;
    obj.setOperator(_myOperator);

    cout << "Podaj b" << endl;
    cin >> z;
    obj.setB(z);

    switch (obj.getOperator()) // decide what operation to use
    {
    case '+':
    {
        obj.Add();
        break;
    }
    case '-':
    {
        obj.Sub();
        break;
    }
    case '*':
    {
        obj.Mul();
        break;
    }
    case '/':
    {
        obj.Div();
        break;
    }
    case '^':
    {
        obj.Pow();
        break;
    }

    default:
        obj.SetState(2);
        break;
    }

    switch (obj.getState()) // decite to print reult or error
    {
    case 0:
    {
        cout << "Wynik to: " << obj.getResult() << endl;
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
        break;
    }

    default:
        cout << "nieznany status";
        break;
    }

    return (0);
}