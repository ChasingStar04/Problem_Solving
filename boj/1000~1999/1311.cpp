//탑다운 dp로 풀 수 있습니다. 일을 표현하기 위해 비트마스크를 이용합니다.
#include <iostream>

using namespace std;

int cost[20][20];
int dp[1050000];
int n;

int Solve(int check, int p)
{
    if (dp[check])
        return dp[check];
    
    if (p==0)
    {
        for (int i=0; i<n; i++)
        {
            if ((check&(1<<i)))
                return cost[p][i];
        }
    }

    int res = 0x3f3f3f3f;
    for (int i=0; i<n; i++)
    {
        if ((check&(1<<i)))
            res = min(res, Solve(check&~(1<<i), p-1)+cost[p][i]);
    }
    dp[check] = res;
    return dp[check];
}

int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin>>cost[i][j];
    }

    cout<<Solve((1<<n)-1, n-1);

    return 0;
}
