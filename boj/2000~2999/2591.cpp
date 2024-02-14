//한자리카드와 두자리카드로 케이스를 나눠 dp를 짠다.
//0은 두자리카드의 두 번째 자리로만 있을 수 있다. 이에 유의하자.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int dp[41] = {1, };
    
    cin>>s;
    
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]!='0')
            dp[i+1] += dp[i];
        if (i>0 && (s[i-1]=='1' || s[i-1]=='2' || (s[i-1]=='3' && s[i]>='0' && s[i]<='4')))
            dp[i+1] += dp[i-1];
        //cout<<dp[i+1]<<' ';
    }
    
    cout<<dp[s.length()];
    
    return 0;
}
