/*
피연산자는 바로 후위 표기식에 추가하고, 연산자는 일단 스택에 넣어두었다가 때에 맞게 추가합니다.
+, -가 들어오면, (가 나오기 전까지 스택 안에 있는 연산자들을 빼 후위 표기식에 추가합니다. 이후 스택에 넣습니다.
*, /가 들어오면, (+-가 나오기 전까지 스택 안에 있는 연산자들을 빼 후위 표기식에 추가합니다. 이후 스택에 넣습니다.
(는 그냥 스택에 넣습니다.
)가 들어오면, (가 나오기 전까지 스택 안에 있는 연산자들을 빼 후위 표기식에 추가합니다. 이후 (를 뺍니다.
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str, ans;
    stack<char> stk;

    cin>>str;
    for (char &c : str)
    {
        if (c>='A' && c<='Z')
            ans += c;
        else if (c=='+' || c=='-')
        {
            while (!stk.empty() && stk.top()!='(')
            {
                ans += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
        else if (c=='*' || c=='/')
        {
            while (!stk.empty() && (stk.top()=='*' || stk.top()=='/'))
            {
                ans += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
        else if (c=='(')
            stk.push(c);
        else //c==')'
        {
            while (!stk.empty() && stk.top()!='(')
            {
                ans += stk.top();
                stk.pop();
            }
            stk.pop(); //'(' 비우기
        }
    }

    while (!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }

    cout<<ans;

    return 0;
}
