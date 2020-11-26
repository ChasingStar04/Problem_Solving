/*
카드 n개를 살 때 금액의 최댓값은
카드 n-1개를 살 때 금액의 최댓값 + p[1]
카드 n-2개를 살 때 금액의 최댓값 + p[2]
.
.
카드 0개를 살 때 금액의 최댓값 + p[n] 일 것입니다.

따라서 dp[n] = (카드 n개를 살 때 금액의 최댓값) 으로 정의해주고
dp[n] = max(dp[n], dp[n-m]+p[m])을 모든 p에 대해 수행하면 됩니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int dp[1001] = {0}, p[1001] = {0};
    int n;

    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>p[i];
    
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
            dp[j] = max(dp[j], dp[j-i]+p[i]);
    }
    cout<<dp[n];

    return 0;
}