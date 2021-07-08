//dp[자릿수][마지막 자리 숫자][0과 9를 보유했는지 여부] 로 구성합니다.
//0과 9를 모두 보유한다면 0~9가 모두 들어있는 것입니다.
#include <iostream>

#define DIV 1000000000

using namespace std;

int main()
{
    long long dp[110][10][4] = {0}; //0->보유X, 1->0만보유, 2->9만보유, 3->둘다보유
    long long result = 0;
    int n;
    
    cin>>n;

    for (int i=1; i<=8; i++) //n==1일때 세팅
        dp[1][i][0] = 1;
    dp[1][9][2] = 1;

    for (int i=2; i<=n; i++)
    {
        if (i==3)
            int debug = 0;
        dp[i][0][1] = (dp[i-1][1][0]+dp[i-1][1][1])%DIV;
        dp[i][0][3] = (dp[i-1][1][2]+dp[i-1][1][3])%DIV;
        for (int j=1; j<=8; j++)
        {
            for (int k=0; k<=3; k++)
                dp[i][j][k] = (dp[i-1][j-1][k]+dp[i-1][j+1][k])%DIV;
        }
        dp[i][9][2] = (dp[i-1][8][0]+dp[i-1][8][2])%DIV;
        dp[i][9][3] = (dp[i-1][8][1]+dp[i-1][8][3])%DIV;
    }

    for (int i=0; i<10; i++)
        result = (result+dp[n][i][3])%DIV;
    cout<<result;

    return 0;
}
