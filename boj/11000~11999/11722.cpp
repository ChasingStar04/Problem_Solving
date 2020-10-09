/*
dp[n] = n번째 수로 끝나는 규칙에 맞는 수열의 최대 길이

dp[n]을 구하는 방법은, 이전 인덱스들과 비교를 진행하면서 다음 두 조건이 맞다면 dp[n]을 비교하는 수의 dp로 갱신해줍니다.
조건 1. 비교하는 수가 n번째 수보다 작은가?
조건 2. 비교하는 수의 dp가 dp[n]보다 큰가?

그뒤 dp[n]++ 합니다. (수열에 끝에 n번째 수가 추가되므로 수열의 길이도 1 증가합니다.)

마지막에 dp의 최댓값을 찾아 출력합니다.
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
        for(int j=0; j<i; j++)
        {
            if(num[j]>num[i])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
        result = max(result, dp[i]);
    }
    cout<<result;

    return 0;
}
