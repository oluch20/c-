#include <iostream>

using namespace std;

enum State
{
    CORRECT,
    DIV0,
    OUT_OF_BOUNDS
};

class myReal
{
public:
    float Real;
    myReal(float v)
    {
        this->Real = v;
    }

    myReal add(myReal a, State &s)
    {
        s = CORRECT;
        return myReal(this->Real + a.Real);
    }

    myReal div(myReal a, State &s)
    {
        if (a.Real == 0)
        {
            s = DIV0;
        }
        else
        {
            s = CORRECT;
        }
        return myReal(a.Real == 0 ? 0 : this->Real / a.Real);
    }
};

class MyInt
{
public:
    int Intiger;
    MyInt(int i)
    {
        this->Intiger = i;
    }

    MyInt add(MyInt a, State &s)
    {
        s = CORRECT;
        return MyInt(this->Intiger + a.Intiger);
    }
    MyInt add(myReal a, State &s)
    {
        // s =CORRECT;
        // return myReal(this->Intiger + a.Real);
    }
    MyInt div(MyInt a, State &s)
    {
        if (a.Intiger == 0)
        {
            s = DIV0;
        }
        else
        {
            s = CORRECT;
        }
        return MyInt(a.Intiger == 0 ? 0 : this->Intiger / a.Intiger);
    }
};

class calc
{
    State state = CORRECT;

public:
    void setState(State s)
    {
        this->state = s;
    }
    State getState()
    {
        return this->state;
    }
    string getRedableState()
    {
        switch (this->state)
        {
        case CORRECT:
            return "CORRECT";
        case DIV0:
            return "division by 0 error";
        case OUT_OF_BOUNDS:
            return "działanie poza zakresem";
        default:
            return "nieznany stan";
        }
    }
};

main()
{
    State s;
    calc c = calc();
    MyInt a = MyInt(5);
    myReal b = myReal(0);

    cout << "result:" << (a.add(b, s)).Intiger << endl;
    c.setState(s);
    cout << "state: " << c.getRedableState() << endl;
    return c.getState();
}