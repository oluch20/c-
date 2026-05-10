#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

class fragment
{
    int A[2];  // dowolna liczba
    char b; // +, -
    char c; // *, /
    int i = 0;
    int i2 =0;

public:
    fragment(string str) // ta funkcja, ma zapisywać string do pozostałych zmiennych, jeżeli po prawej będzie wyrażenie, to ma rekurencyjnie tworzyć nowy obiekt
    {
        for (auto &s : str)
        {
            if (str.length() < 3) {
                if (s == '+' || '-')
            {
                b == s;
            }
            else if (s == '*' || '/')
            {
                c == s;
            }
            else
            {
                A[i] == s;
                i++;
            }
            } else {
                if (str.length() < 3) {
                if (s == '+' || '-')
            {
                b == s;
            }
            else if (s == '*' || '/')
            {
                c == s;
            }
            else
            {
                //A[i] == fragment( // reszta stringa);
            }
            }
            
        }
        cout << A[1] << A[2] << c << b << endl;
    };
}
};

class Node
{
public:
    string val;
    int depth;
    int start;
    int end;

    Node(const string &chunk, int depth, int start, int end)
        : val(chunk), depth(depth), start(start), end(end) {}

    void print()
    {
        cout << "Glebokosc = " << depth << endl;
        cout << "poczatek jest na pozycji: " << start << endl;
        cout << "Koniec jest na pozycji: " << end << endl;
    }
};

int main()
{

    string s;

    vector<Node> chunks;
    stack<int> myStack;

    // cout << "input: " << endl;
    // cin >> s;
    s = "2*(2+2/(3-2))";
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            myStack.push(i);
        }
        else if (s[i] == ')')
        {
            if (!myStack.empty())
            {
                int start = myStack.top();
                myStack.pop();
                int depth = (int)myStack.size();
                chunks.push_back(Node(s.substr(start + 1, i - start - 1), depth, start, i));
            }
        }
    }
    cout << "Wyrazenie: " << s << endl;
    for (int k = 0; k < (int)chunks.size(); k++)
    {
        cout << "[" << k << "] " << chunks[k].val << endl;
    }

    for (auto &n : chunks)
    {
        n.print();
    }
    return 0;
}