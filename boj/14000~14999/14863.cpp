/*
dp[i][0] = 마지막 구간을 도보로 이동했을 때, i시간 이내에 얻을 수 있는 최대 금액
dp[i][1] = 마지막 구간을 자전거로 이동했을 때, i시간 이내에 얻을 수 있는 최대 금액

점화식은 dp[i+도보시간][0] = max(dp[i][0], dp[i][1])+도보금액
자전거도 위 형식입니다.

모든 구간을 통과해야하므로, 이번 구간에서 갱신되지 않은 인덱스를 -1로 채워주고
점화식에서 dp[i][0], dp[i][1]중 하나라도 -1이 아니어야 갱신할 수 있도록 합니다.

p.s. last1, last2의 초기값을 k+1이 아니라 k로 둬서 고칠 때 굉장히 고생했습니다.
*/
#include <iostream>

using namespace std;

long long dp[100010][2] = {0};

int main()
{
    int n, k;
    
    cin>>n>>k;
    for (int i=0; i<n; i++)
    {
        int t1, m1, t2, m2;
        int last1 = k+1, last2 = k+1;
        cin>>t1>>m1>>t2>>m2;

        for (int j=k; j>=0; j--)
        {
            if (j+t1<=k && (dp[j][0]!=-1 || dp[j][1]!=-1))
            {
                dp[j+t1][0] = max(dp[j][0], dp[j][1])+m1;
                last1 = j+t1;
            }
            if (j+t2<=k && (dp[j][0]!=-1 || dp[j][1]!=-1))
            {
                dp[j+t2][1] = max(dp[j][0], dp[j][1])+m2;
                last2 = j+t2;
            }
        }
        
        for (int j=last1-1; j>=0; j--)
            dp[j][0] = -1;
        for (int j=last2-1; j>=0; j--)
            dp[j][1] = -1;
        //cout<<dp[k][0]<<' '<<dp[k][1]<<'\n';
    }
    cout<<max(dp[k][0], dp[k][1]);

    return 0;
}
