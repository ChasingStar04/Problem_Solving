/*
n개의 잔이 있을 때, 최대로 먹을 수 있는 포도주의 양 = max(n번째 잔을 안 먹었을 때, n번째 잔을 첫번째로 먹었을 때, n번째 잔을 두번째로 먹었을 때)

n번째 잔을 두번째로 먹었을 때 = n-3번째 잔까지의 최대 양 + n-1번째 잔의 양 + n번째 잔의 양
n번째 잔을 첫번째로 먹었을 때 = n-2번째 잔까지의 최대 양 + n번째 잔의 양
n번째 잔을 안 먹었을 때 = n-1번째 잔까지의 최대 양
*/
#include <iostream>

using namespace std;

int main()
{
    int n, dp[10003] = {0}, array[10003] = {0};

    cin>>n;
    for(int i=3; i<=n+2; i++)
    {
        cin>>array[i];
        
        dp[i] = max(dp[i-3]+array[i-1]+array[i], dp[i-2]+array[i]);  //max(두번째로 마신 경우, 첫번째로 마신 경우)
        dp[i] = max(dp[i-1], dp[i]);  //안 마신 경우
    }
    cout<<dp[n+2];

    return 0;
}