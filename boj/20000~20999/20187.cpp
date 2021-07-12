//다 접은 상태에서 구멍을 뚫고, 펼쳐가면서 펼친 칸에 좌우반전, 상하반전을 고려하여 구멍을 뚫습니다.
//1과 xor하여 좌우대칭, 2와 xor하여 상하대칭을 할 수 있습니다.
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int arr[256][256];
    int k, h;
    int x1, x2, y1, y2, n;
    stack<char> stk;

    cin>>k;
    x1 = y1 = 0;
    x2 = y2 = n = (1<<k);
    for (int i=0; i<k*2; i++)
    {
        char input;

        cin>>input;
        stk.push(input);
        if (input=='D')
            y1 = (y1+y2)/2;
        else if (input=='U')
            y2 = (y1+y2)/2;
        else if (input=='R')
            x1 = (x1+x2)/2;
        else if (input=='L')
            x2 = (x1+x2)/2;
    }
    cin>>h;

    arr[y1][x1] = h;
    while (!stk.empty())
    {
        char c = stk.top();
        stk.pop();

        if (c=='D')
        {
            for (int i=0; i<y2-y1; i++)
            {
                for (int j=x1; j<x2; j++)
                    arr[y1-i-1][j] = arr[y1+i][j]^2;
            }
            y1 -= y2-y1;
        }
        else if (c=='U')
        {
            for (int i=0; i<y2-y1; i++)
            {
                for (int j=x1; j<x2; j++)
                    arr[y2+i][j] = arr[y2-i-1][j]^2;
            }
            y2 += y2-y1;
        }
        else if (c=='R')
        {
            for (int i=y1; i<y2; i++)
            {
                for (int j=0; j<x2-x1; j++)
                    arr[i][x1-j-1] = arr[i][x1+j]^1;
            }
            x1 -= x2-x1;
        }
        else if (c=='L')
        {
            for (int i=y1; i<y2; i++)
            {
                for (int j=0; j<x2-x1; j++)
                    arr[i][x2+j] = arr[i][x2-j-1]^1;
            }
            x2 += x2-x1;
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<<arr[i][j]<<' ';
        cout<<'\n';
    }

    return 0;
}
