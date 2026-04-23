#include <iostream>
#include <string>

using namespace std;

class bracketCollector
{
    
    int bracketcouter;
    int openBracket;

    public:
    string bracket(int openBracketAt, string string, int endOfString)
    {
        std::string output;
        for (int i = 0; i < endOfString; i++)
        {
            output[i] = string[openBracketAt];
            openBracketAt++;
        }
        return (output);
    }

};

int main()
{

    string s;
    string ts[200];

    int counter = 0;
    int stringCounter = 0;
    int tsCounter = 0;

    cout << "input: " << endl;
    cin >> s;

    for (char &c : s)
    {
        stringCounter++;
    }

    for (int i = 0; i < stringCounter; i++)
    {
        cout << s[i] << endl;

        if (s[i] == '(')
        {
            for (counter = stringCounter; counter < stringCounter; counter++)
            {
                if (s[counter] == ')')
                {
                    ts[tsCounter] = s[counter];
                    tsCounter++;
                    
                }
                else
                {
                    ts[tsCounter] = s[counter];
                    tsCounter++;
                }
            }
        }
    }
    
    cout << "stringCounter:" << stringCounter << endl;
    cout << "Counter:" << counter << endl;

    cout << "nawiasy" << endl;
    for (int i = 0; i < counter; i++)
    {
        cout << ts[i] << endl;
    }
    return 0;
}