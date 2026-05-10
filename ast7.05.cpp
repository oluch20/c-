#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    string chunk;
    Node *left;
    Node *right;

    Node(const string &frag, Node *left, Node *right) : chunk(frag), left(left), right(right) {}

    bool is_leaf()
    {
        if (right == nullptr && left == nullptr)
            return true;
        return false;
    }

    string print()
    {
        return is_leaf() ? chunk : left->print() + chunk + right->print();
    }
};

/**
 * expr_as = e +,- e
 * expr_md = e *,/ e
 */
class Parser
{
public:
    string eq;
    int pos = 0;
    Node *ast;
    // zaznaczenie miejsc nawiasów
    stack<int> stackStart;
    stack<int> stackEnd;

    int Nawiasy()
    // funkcja sprawdza, czy liczba otawrtych nawiasów jest równa liczbie zamkniętych
    {
        string temp = eq;

        for (int i = 0; i < (int)temp.size(); i++)
        {
            if (temp[i] == '(')
            {
                stackStart.push(i);
            }
            else if (temp[i] == ')')
            {
                stackEnd.push(i);
            }
        }

        if (stackStart.size() != stackEnd.size())
        {
            // cout << "blad nawiasow" << endl;
            return (1);
        }
        else
        {
            // cout << "jest git" << endl;
            return (0);
        }
        // cout << "test" << endl;
    }

    Parser(const string &s) : eq(s)
    {
    }

    void print_ast()
    {
        cout << ast->print() << endl;
    }

    char current()
    {
        return eq[pos];
    }
    /**
     * Liczby wielocyfrowe
     */
    string consumeAll()
    {
        int tmp = pos;
        while ((pos < eq.size() && isdigit(eq[pos]) || eq[pos] == '.') && pos < eq.size())
            pos++;
        return eq.substr(tmp, pos - tmp);
    }

    string consumeUntil(string symbols)
    {
        int tmp = pos;
        // cout << eq[pos] << endl;
        while (pos < eq.size() && (symbols.find(eq[pos]) != string::npos))
            pos++;
        return eq.substr(tmp, pos - tmp);
    }

    /**
     * Parsowanie symbolu terminalnego
     */
    Node *terminal()
    {
        if (pos < eq.size() && eq[pos] == '(')
        {
            pos++;
            Node *sub = expr_as();
            if (pos < eq.size() && eq[pos] == ')')
                pos++;
            return sub;
        }
        return new Node(consumeAll(), nullptr, nullptr);
    }

    /**
     * Parsowanie dodawania i odejmowania
     */
    Node *expr_as()
    {
        Node *left = expr_md();
        string n;
        while (!(n = consumeUntil("-+")).empty())
        {
            Node *right = expr_md();
            left = new Node(n, left, right);
        }
        return left;
    }

    Node *expr_md()
    {
        Node *left = terminal();
        string n;
        while (!(n = consumeUntil("*/")).empty())
        {
            Node *right = terminal();
            left = new Node(n, left, right);
        }
        return left;
    }

    void parse()
    {
        ast = expr_as();

        cout << (Nawiasy() ? "Blad nawiasow\n" : "Liczba nawiasow sie zgadza\n") << endl;
    }
};

int main()
{
    string s = "(2+3)*(4-1)+2*(2+2/(3-2))";
    // string s = "2-32*18+3/2";
    cout << "Wyrazenie: " << s << "\n\n";

    Parser p = Parser(s);

    p.parse();
    p.print_ast();

    return 0;
}