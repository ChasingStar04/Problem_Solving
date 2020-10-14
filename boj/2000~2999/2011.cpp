/*
dp[n] = (n번째 자리까지의 경우의 수) 입니다.
경우의 수는 n번째 자리를 앞의 숫자와 합쳐 읽는 경우, 따로 읽는 경우 2가지 이므로
dp[n] = dp[n-1]+dp[n-2] 이라는 식을 구해 낼 수 있습니다. (dp[n-1]: 따로 읽는 경우, dp[n-2]: 합쳐 읽는 경우)

여기에 예외 처리를 추가합니다.
n번째 자리가 0일때는 따로 읽을 수 없으므로 dp[n-1]을 더할 수 없고,
n-1번째 자리가 0이거나 n-1번째 자리와 n번째 자리를 합쳐 읽은 숫자가 26보다 작은 경우 dp[n-2]를 더할 수 없습니다.

첫번째 자리가 0이거나 dp[n]이 0이라면 암호가 잘못되었으므로 0을 출력합니다.
*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[5050] = {0};
    int dp[5001] = {1, 1};  //글자수가 0일때, 1일때를 base case로 세팅
    bool true_crypto = true;  //암호가 잘못되었는지 아닌지를 나타내는 변수

    cin>>str;
    if(str[0]=='0')
        true_crypto = false;
 
    int len = strlen(str);
    for(int i=2; i<=len; i++)
    {
        if(str[i-1]!='0')
            dp[i] = dp[i-1];
        if(str[i-2]!='0' && strncmp(str+i-2, "26", 2)<=0)
            dp[i] = (dp[i]+dp[i-2])%1000000;
        
        if(!dp[i])
        {
            true_crypto = false;
            break;
        }
    }
    if(true_crypto)
        cout<<dp[len];
    else
        cout<<'0';

    return 0;
}
