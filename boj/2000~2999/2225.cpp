/*
n이 주어졌을 때, a+b=n이 되는 경우의 수를 구한다고 하면
a값에 따라 b의 값은 정해지므로 a의 경우의 수만 구하면 됩니다.
예를들어서 a+b=20이 되는 경우의 수를 구한다면 가능한 a의 경우의 수는 0~20이므로 21이고, a+b=20의 경우의 수도 21입니다.
위 규칙에 따라 dp를 구성합니다.

k개의 수를 더해서 n을 만드는 경우의 수 = dp[k][n] 이라 하면
dp[k][n] = (dp[k-1][0]~dp[k-1][n]까지의 합) 입니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, k, dp[201][201] = {0};

    cin>>n>>k;
    for(int i=0; i<=n; i++)  //k=1일때를 base case로 세팅
        dp[1][i] = 1;
    for(int i=2; i<=k; i++)
    {
        int sum = 0;
        for(int j=0; j<=n; j++)
        {
            sum = (sum+dp[i-1][j])%1000000000;
            dp[i][j] = sum;
        }
    }
    cout<<dp[k][n];

    return 0;
}
