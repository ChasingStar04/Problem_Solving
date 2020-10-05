/*
증가 수열 dp(plus_dp)와 바이토닉 수열 dp(bito_dp)를 만듭니다.
plus_dp[n] = (n보다 작은 수들 중 가장 큰 plus_dp[])+1
bito_dp[n] = (n보다 작은 수들 중 가장 큰 plus_dp[] or bito_dp[])+1

bito_dp의 최댓값을 찾아서 출력합니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, plus_dp[1000] = {0}, bito_dp[1000] = {0}, num[1000] = {0};
    int result = 0;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>num[i];
        for(int j=0; j<i; j++)
        {
            if(num[j]<num[i])
                plus_dp[i] = max(plus_dp[i], plus_dp[j]);
        }
        plus_dp[i]++;
        for(int j=0; j<i; j++)
        {
            if(num[j]>num[i] && (plus_dp[j] || bito_dp[j]))
                bito_dp[i] = max(bito_dp[i], max(plus_dp[j], bito_dp[j]));
        }
        bito_dp[i]++;
        result = max(result, bito_dp[i]);
    }
    cout<<result;

    return 0;
}
