/*
n자리의 a로 끝나는 규칙에 맞는 수의 개수를 dp[n][a]라고 하면
dp[n][0] = dp[n-1][0]
dp[n][a] = dp[n-1][a] + dp[n][a-1]  (a!=0)
입니다.

더할때마다 10007로 나머지연산 해주는거 잊지 맙시다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, dp[1000][10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  //n=1일때를 base case로 세팅
    int result = 0;

    cin>>n;
    for(int i=1; i<n; i++)
    {
        dp[i][0] = dp[i-1][0];
        for(int j=1; j<=9; j++)
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%10007;
    }
    for(int i=0; i<=9; i++)
        result = (result+dp[n-1][i])%10007;
    cout<<result;

    return 0;
}
