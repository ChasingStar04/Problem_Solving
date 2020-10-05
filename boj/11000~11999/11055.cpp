/*
dp로 풀 수 있습니다.
n번째 수로 끝나는 수열의 최대합을 dp[n] 이라고 할 때
dp[n] = (n보다 작은 수들 중 가장 큰 dp[]) + (n번째 수) 입니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, dp[1000] = {0}, num[1000] = {0};
    int result = 0;

    cin>>n;
    for(int i=0; i<n; i++)
        cin>>num[i];
    for(int i=0; i<n; i++)
    {
        int before_max = 0;
        for(int j=0; j<i; j++)
        {
            if(num[j]<num[i])
                before_max = max(before_max, dp[j]);  //이을 수 있는 dp의 최댓값
        }
        dp[i] = before_max+num[i];
        result = max(result, dp[i]);
    }
    cout<<result;

    return 0;
}
