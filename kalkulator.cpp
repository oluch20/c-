#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif
#include "parser.h"

using namespace std;

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

    return (0);
}