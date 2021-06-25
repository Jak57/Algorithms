#include <bits/stdc++.h>

using namespace std;

string infixToPostfix(string infix);
int prece(char ch);

int main(void)
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i", postfix;
    postfix = infixToPostfix(infix);

    cout<< postfix << "\n";

    return 0;
}

string infixToPostfix(string infix)
{
    int n, i;
    string postfix = "";
    stack<char> s;
    char ch, top;
    n = infix.size();


    for (i = 0; i < n; i++)
    {
        ch = infix[i];
        cout<< "hi " << ch << "\n";
        cout<< postfix << "\n";

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.top() != '(')
            {
                top = s.top();
                s.pop();
                postfix += top;
            }
            s.pop();
        }
        else
        {
            while ((s.size() != 0) && (prece(s.top()) >= prece(ch)))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }

    }

    cout<< "Hello" << "\n";

    while (s.size() != 0)
    {
        top = s.top();
        s.pop();
        postfix += top;
    }


    return postfix;
}

int prece(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '/')
        return 3;
    else if (ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
// a+b*(c^d-e)^(f+g*h)-i

//abcd^e-fgh*+^*+i-
