//dfs로 문제를 해결하고, 시간을 줄이기 위해 dp테이블을 이용합니다.
#include <iostream>

using namespace std;

int n, m;
bool dont[110];
int dp[110][110];

int dfs(int day, int coupon)
{
    if (day>n) return 0;
    if (dp[day][coupon]) return dp[day][coupon];
    if (dont[day]) return dfs(day+1, coupon);

    int ans = 0x3f3f3f3f;
    ans = min(ans, dfs(day+1, coupon)+10000);
    ans = min(ans, dfs(day+3, coupon+1)+25000);
    ans = min(ans, dfs(day+5, coupon+2)+37000);
    if (coupon>=3) ans = min(ans, dfs(day+1, coupon-3));

    dp[day][coupon] = ans;
    return dp[day][coupon];
}

int main()
{
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int tmp;
        cin>>tmp;
        dont[tmp] = true;
    }

    cout<<dfs(1, 0);

    return 0;
}
