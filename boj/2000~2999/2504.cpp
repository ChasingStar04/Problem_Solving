#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    stack<int> stk;
    bool bad_input = false;

    cin>>str;
    for (char &c : str)
    {
        if (c=='(')
            stk.push(-1);
        else if (c=='[')
            stk.push(-2);
        else if (c==')')
        {
            int sum = 0;
            while (!stk.empty() && stk.top()>0)
            {
                sum += stk.top();
                stk.pop();
            }

            if (stk.empty() || stk.top()==-2)
            {
                bad_input = true;
                break;
            }
            else
            {
                stk.pop();
                stk.push(2*(sum==0 ? 1 : sum));
            }
        }
        else if (c==']')
        {
            int sum = 0;
            while (!stk.empty() && stk.top()>0)
            {
                sum += stk.top();
                stk.pop();
            }

            if (stk.empty() || stk.top()==-1)
            {
                bad_input = true;
                break;
            }
            else
            {
                stk.pop();
                stk.push(3*(sum==0 ? 1 : sum));
            }
        }
    }

    if (bad_input) cout<<0;
    else
    {
        int sum = 0;
        while (!stk.empty())
        {
            if (stk.top()<0)
            {
                sum = 0;
                break;
            }
            sum += stk.top();
            stk.pop();
        }
        cout<<sum;
    }

    return 0;
}
