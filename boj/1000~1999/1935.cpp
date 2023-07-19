#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double alpha[26] = {0};
    string command;
    stack<double> stk;

    cin>>n;
    cin>>command;
    for (int i=0; i<n; i++)
    {
        int num;
        cin>>num;
        alpha[i] = num;
    }

    for (char &c : command)
    {
        if (c>='A' && c<='Z')
            stk.push(alpha[c-'A']);
        else
        {
            double b = stk.top();
            stk.pop();
            double a = stk.top();
            stk.pop();

            if (c=='+')
                stk.push(a+b);
            else if (c=='-')
                stk.push(a-b);
            else if (c=='*')
                stk.push(a*b);
            else if (c=='/')
                stk.push(a/b);
        }
    }

    cout<<fixed;
    cout.precision(2);
    cout<<floor(stk.top()*100)/100;

    return 0;
}
