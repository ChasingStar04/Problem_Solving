//풀이: https://chasingstar.tistory.com/15
#include <iostream>

using namespace std;

int main()
{
    int n, dp[31] = {1};

    cin>>n;
    for(int i=2; i<=n; i+=2)
    {
        dp[i] += dp[i-2]*3;
        for(int j=0; j<=i-4; j++)
            dp[i] += dp[j]*2;
    }
    cout<<dp[n];

    return 0;
}
