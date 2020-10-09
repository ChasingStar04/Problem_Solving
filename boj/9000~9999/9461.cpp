/*
n번째 파도반 수를 구하는 규칙은
(n-2번째 수 + n-3번째 수)
(n-1번째 수 + n-5번째 수) 두개의 규칙이 있습니다.

이 코드는 첫번째 규칙을 이용했습니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int t;
    long long dp[101] = {0, 1, 1};  //n=1~n=2까지 base case로 세팅
    
    cin>>t;
    for(int i=3; i<=100; i++)
        dp[i] = dp[i-2]+dp[i-3];  //dp테이블 작성
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<'\n';
    }

    return 0;
}
