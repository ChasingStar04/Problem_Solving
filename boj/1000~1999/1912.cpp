/*
n번째 수를 포함하는 n번째 수 까지의 최대 부분합을 dp[n]이라고 하면
dp[n] = max(계속 이어나가는 경우, 새로 시작하는 경우) = max(dp[n-1]+현재수, 현재수)
dp[n-1]가 0보다 크다면 계속 이어나가는 것이 이득이고, 0보다 작다면 새로 시작하는 것이 이득이다.

부분합들 중 최댓값 찾아서 출력한다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, dp[100001] = {0}, num[100001] = {0};
    int result = -9999;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>num[i];
    for(int i=1; i<=n; i++)
    {
        dp[i] = max(dp[i-1]+num[i], num[i]);
        result = max(result, dp[i]);
    }
    cout<<result;

    return 0;
}
