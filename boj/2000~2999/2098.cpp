//https://chasingstar.tistory.com/27
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

int w[20][20];
int dp[65536][16];
int n;

int Solve(int check, int last)
{
    if (dp[check][last])
        return dp[check][last];
    
    int nc = check&(~(1<<last));
    if (nc==0) //last가 첫 번째 노드라면
    {
        dp[check][last] = (w[0][last] ? w[0][last] : INF);
        return dp[check][last]; //0->last로 갈 수 있으면 해당 비용, 없으면 INF 반환
    }

    int ans = INF;
    for (int i=0; i<n; i++)
    {
        if ((check&(1<<i)) && i!=last && w[i][last]) //check안에 존재하고, last가 아니고, last로 갈 수 있으면
            ans = min(ans, Solve(nc, i)+w[i][last]);
    }

    dp[check][last] = ans;
    return dp[check][last];
}

int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin>>w[i][j];
    }

    cout<<Solve((1<<n)-1, 0); //모든 도시를 방문하여 0으로 갈 때의 값

    return 0;
}
