/*
dp배열 두 개를 돌려가면서 풀었습니다.
dp보다는 bfs를 이용하는 것이 더 효율적이니 bfs를 이용하세요.
*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int dp[2][100001] = {0};
    int a, b, n, m;
    int cnt = 0;

    cin>>a>>b>>n>>m;

    dp[0][n] = 1;
    while (dp[cnt%2][m]==0)
    {
        for(int i=1; i<=100000; i++)
        {
            if(dp[cnt%2][i])
            {
                if(i-1>0)  dp[(cnt+1)%2][i-1] = 1;  //좌우로 1칸
                if(i+1<=100000)  dp[(cnt+1)%2][i+1] = 1;
                if(i-a>0)  dp[(cnt+1)%2][i-a] = 1;  //좌우로 a칸
                if(i+a<=100000)  dp[(cnt+1)%2][i+a] = 1;
                if(i-b>0)  dp[(cnt+1)%2][i-b] = 1;  //좌우로 b칸
                if(i+b<=100000)  dp[(cnt+1)%2][i+b] = 1;
                if(i*a<=100000)  dp[(cnt+1)%2][i*a] = 1;  //a배, b배
                if(i*b<=100000)  dp[(cnt+1)%2][i*b] = 1;
            }
        }
        cnt++;
    }
    
    cout<<cnt;

    return 0;
}
