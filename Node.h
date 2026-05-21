// #ifdef NODE_H
// #define NODE_H

#include <iostream>
#include <string>
#include <stdexcept>


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

    float compute()
    {
        if (is_leaf())
            return (stof(chunk));

        float a = left->compute();
        float b = right->compute();

        if (chunk.compare("+") == 0)
            return (a + b);
        else if (chunk.compare("-") == 0)
            return (a - b);
        else if (chunk.compare("*") == 0)
            return (a * b);
        else if (chunk.compare("/") == 0) // obsługa / przez 0
        {
            if (b != 0)
                return (a / b);
            else
                throw runtime_error("1"); // dzielenie przez zero
        }
        else
            throw runtime_error("2"); // błędny operator
    }
};
// #endif // node_h