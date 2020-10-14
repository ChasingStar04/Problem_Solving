/*
n은 (어떤 제곱수) + (어떤 수) 로 나타낼 수 있습니다.
따라서 n을 만들 수 있는 제곱수의 최소 개수를 dp[n]이라 하면
dp[n] = min(dp[n], dp[n-1]+1)
.
.
.
dp[n] = min(dp[n], dp[n-(n보다 작은 제곱수중 가장 큰 수)]+1)
로 구할 수 있습니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, dp[100001] = {0};

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        dp[i] = i;  //가장 작은 제곱수인 1만 더해서 만드는 경우
        for(int j=1; j*j<=i; j++)
            dp[i] = min(dp[i], dp[i-j*j]+1);
    }
    cout<<dp[n];

    return 0;
}
