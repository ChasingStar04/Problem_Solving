/*
길이가 n이고 a로 끝나는 규칙에 맞는 수의 개수를 dp[n][a] 라고 하면
dp[n][a] = dp[n-1][a-1] + dp[n-1][a+1] 입니다.
여기서 a=0일때는 a-1이, a=9일때는 a+1이 존재하지 않으므로 예외 처리 해줍니다.
*/
#include <iostream>

using namespace std;

int main()
{
    int n, dp[100][10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};  //n=1일 경우를 base case로 세팅
    int result = 0;

    cin>>n;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j-1>=0)  dp[i][j] = (dp[i][j]+dp[i-1][j-1])%1000000000;
            if(j+1<10)  dp[i][j] = (dp[i][j]+dp[i-1][j+1])%1000000000;
        }
    }
    for(int i=0; i<10; i++)
        result = (result+dp[n-1][i])%1000000000;
    cout<<result;

    return 0;
}
