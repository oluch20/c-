#include <iostream>
#include <string>
#include <vector>
#include <stack>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class Node
{
public:
    string chunk;
    Node *left;
    Node *right;
    int error_code = 0;
    // 0 - OK,
    // 1 - dzielenie przez zero,
    // 2 - w chunku znalazł się niewłaściwy symbol,
    // 3 - dzielenie przez zero i w chunku znalazł się niepoprawny symbol

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

    float compute()
    {
        if (is_leaf())
        {
            return (stof(chunk));
        }
        else
        {
            if (chunk.compare("+") == 0)
            {
                if (error_code == 0)
                {
                    return (left->compute() + right->compute());
                }
                else
                {
                    error_code = error();
                };
            }
            else if (chunk.compare("-") == 0)
            {
                if (error_code == 0)
                {
                    return (left->compute() - right->compute());
                }
                else
                {
                    error_code = error();
                };
            }
            else if (chunk.compare("*") == 0)
            {
                if (error_code == 0)
                {
                    return (left->compute() * right->compute());
                }
                else
                {
                    error_code = error();
                };
            }
            else if (chunk.compare("/") == 0) // obsługa / przez 0
            {
                if (right->compute() == 0)
                {
                    error_code = 11;
                    cout << "dzielenie przez zero!" << endl;
                }
                else
                {
                    if (error_code == 0)
                {
                    return (left->compute() / right->compute());
                }
                else
                {
                    error_code = error();
                };
                }
            }
            else
            {
                error_code = 10;
            }
        }
    }

    int error()
    {
       if (left->error_code && right->error_code == 0)
       {
        return (left->error_code + right->error_code);
       } else if (left->error_code || right->error_code == 1) {
        return (1);
       } else if (left->error_code || right->error_code == 2)
       {
        return(2);
       } else 
       {
        return (3);
       }
    }
};

void print_ascii(Node *node, const string &prefix = "", bool isRight = true)
{
    if (!node) // sprawdzenie, czy jako node zostało przekazane nullptr
        return;
    if (node->right) // sprawdzenie, czy right != nullptr
        print_ascii(node->right, prefix + (isRight ? "    " : "│   "), true);
    cout << prefix << (isRight ? "┌── " : "└── ") << node->chunk << "\n";
    if (node->left) // sprawdzenie, czy left != nullptr
        print_ascii(node->left, prefix + (isRight ? "│   " : "    "), false);
}

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

        cout << (Nawiasy() ? "Błąd nawiasów\n" : "Liczba nawiasów się zgadza\n") << endl;
    }
};

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    // string s = "(22+3)*(4-1)+2*(2+2/(3-2))";
    // string s = "2-32*18+3/2";
    string s = "2+2*2/0";
    cout << "Wyrażenie: " << s << "\n\n";

    Parser p = Parser(s);
    p.parse();
    cout << p.ast->error_code;
    if (p.ast->error_code != 0)
    {
        cout << "błąd: " << p.ast->error_code;
    }
    p.print_ast();
    cout << "\n";
    print_ascii(p.ast);

    cout << "Wynik: " << p.ast->compute();

    return 0;
}