//두 개의 스택을 사용한 풀이입니다.
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
    char input[55] = {0};
    stack<char> stk1;
    stack<int> stk2;
    int result = 0;

    cin>>input;
    
    for (int i=0; i<strlen(input); i++)
    {
        if (input[i]!=')')
            stk1.push(input[i]);
        else
        {
            int cnt = 0;
            while (true)
            {
                char tmp = stk1.top();
                stk1.pop();

                if (tmp>='0' && tmp<='9')
                    cnt++;
                else if (tmp=='A')
                {
                    cnt += stk2.top();
                    stk2.pop();
                }
                else if (tmp=='(')
                    break;
            }
            stk2.push(cnt*(stk1.top()-'0'));
            stk1.pop();
            stk1.push('A');
        }
    }

    while (!stk1.empty())
    {
        char tmp = stk1.top();
        stk1.pop();

        if (tmp>='0' && tmp<='9')
            result++;
        else if (tmp=='A')
        {
            result += stk2.top();
            stk2.pop();
        }
    }

    cout<<result;

    return 0;
}
