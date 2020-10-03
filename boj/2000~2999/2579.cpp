/*
n번째 계단을 무조건 밟을 경우, 점수의 최댓값은 max(첫번째 계단으로 밟을 경우, 두번째 계단으로 밟을 경우) 입니다.
첫번째 계단으로 밟을 경우 = 전전계단까지의 최댓값 + 현재 계단의 점수
두번째 계단으로 밟을 경우 = 전전전계단까지의 최댓값 + 전 계단의 점수 + 현재 계단의 점수
이렇게 점화식을 세울 수 있습니다.

0~2번째 계단까지는 base case로 미리 세팅합니다.
피보나치 수열에서 0번째, 1번째를 0, 1로 미리 세팅해주는 것과 비슷합니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, dp[301] = {0}, stairs[301] = {0};

    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>stairs[i];
    
    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = stairs[1]+stairs[2];  //0~2번까지는 base case
    for(int i=3; i<=n; i++)
        dp[i] = max(dp[i-2]+stairs[i], dp[i-3]+stairs[i-1]+stairs[i]);
    cout<<dp[n];

    return 0;
}
