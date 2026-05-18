#include <iostream>

using namespace std;

float Add(float a, float b)
{
    return (a + b);
}

float Mul(float a, float b)
{
    return (a * b);
}

float Sub(float a, float b)
{
    return (a - b);
}

float Div(float a, float b, int *state)
{
    if (b != 0)
    {
        return (a / b);
    }
    else
    {
        *state = 1;
        return (1);
    }
}

float Pow(float a, float b)
{
    float c = a;
    for (float i = 1; i < b; i++)
    {
        a * c;
    }
    return (a);
}

int main()
{
    int state = 0; // 0 - correct, 1 - error (/ 0), 2 - error (incorrect operator)
    float a;
    float b;
    char op;
    float c;

    cout << "to jest kalkulator, podaj a" << endl;
    cin >> a;

    cout << "to jest kalkulator, podaj operator" << endl;
    cin >> op;

    cout << "to jest kalkulator, podaj b" << endl;
    cin >> b;

    switch (op)
    {
    case '+':
    {
        a = Add(a, b);
        break;
    }
    case '-':
    {
        a = Sub(a, b);
        break;
    }
    case '*':
    {
        a = Mul(a, b);
        break;
    }
    case '/':
    {
        a = Div(a, b, &state);
    }
    case '^':
    {
        a = Pow(a, b);
    }

    break;

    default:
        state = 2;
        break;
    }

    switch (state)
    {
    case 0:
    {
        cout << "Wynik to: " << a << endl;
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