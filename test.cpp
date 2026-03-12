#include <iostream>

using namespace std;

int main()
{
    int state = 0; // 0 - correct, 1 - error (/ 0), 2 - error (incorrect operator)
    float a;
    float b;
    char op;

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
        a = a + b;
        break;
    }
    case '-':
    {
        a = a - b;
        break;
    }
    case '*':
    {
        a = a + b;
        break;
    }
    case '/':
    {
        if (b != 0)
        {
            a = a / b;
        }
        else
        {
            state = 1;
        }
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