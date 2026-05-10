#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
class Nawiasy
{
    string s;
    stack<int> stackStart;
    stack<int> stackEnd;

public:
    Nawiasy(string stri)
    {
        s = stri;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '(')
            {
                stackStart.push(i);
            }
            else if (s[i] == ')')
            {
                stackEnd.push(i);
            }
        }
    }
    int blad() {
        if (stackStart.size() != stackEnd.size())
    {
        cout << "blad nawiasow" << endl;
        return (1);
    } else {
        return(0);
    }
    }
};

int main()
{
    string s;

    s = "2*(2+2/(3-2))";
    //s = "2+4*5";
    Nawiasy a(s);
    if ( a.blad() == 1) {
        return(1);
    }
    
    cout << "Jest git" << endl;
    return (0);
}
