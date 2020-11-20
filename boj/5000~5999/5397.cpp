/*
커서 왼쪽과 오른쪽을 나타내는 스택을 만들어 풀었습니다.

<가 들어올 때: 왼쪽 스택에서 pop하여 오른쪽 스택에 넣습니다.
>가 들어올 때: 오른쪽 스택에서 pop하여 왼쪽 스택에 넣습니다.
-가 들어올 때: 왼쪽 스택에서 pop합니다.
나머지 문자가 들어올 때: 왼쪽 스택에 넣습니다.

출력할때는 왼쪽 스택을 모두 오른쪽 스택에 넣은 후, 오른쪽 스택에서 나오는 순서대로 출력합니다.
*/
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

char str[1000010];

int main()
{
    stack<char> left_cursor, right_cursor;
    int t;

    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>str;
        int len = strlen(str);
        for(int i=0; i<len; i++)
        {
            switch (str[i])
            {
            case '<':
                if(!left_cursor.empty())
                {
                    right_cursor.push(left_cursor.top());
                    left_cursor.pop();
                }
                break;
            case '>':
                if(!right_cursor.empty())
                {
                    left_cursor.push(right_cursor.top());
                    right_cursor.pop();
                }
                break;
            case '-':
                if(!left_cursor.empty())
                    left_cursor.pop();
                break;
            default:
                left_cursor.push(str[i]);
                break;
            }
        }

        while (!left_cursor.empty())
        {
            right_cursor.push(left_cursor.top());
            left_cursor.pop();
        }
        while (!right_cursor.empty())
        {
            cout<<right_cursor.top();
            right_cursor.pop();
        }
        cout<<'\n';
    }

    return 0;
}
