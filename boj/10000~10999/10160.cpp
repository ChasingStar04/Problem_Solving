/*
단순한 실버 정도 난이도의 문제인 줄 알았으나, 생각보다 훨씬 까다로웠습니다.
특히 위험한 암호의 개수를 중복 없이 정확히 세는 것이 어려웠습니다.

danger[i] = (앞 i-1자리가 이미 위험한 암호인 경우) + (i번째 글자 때문에 위험한 암호가 된 경우)
(i번째 글자 때문에 위험한 암호가 된 경우)는 마지막 다섯 글자가 ABCBC인 경우와 ABABC인 경우 2가지
ABABC인 경우 (마지막이 ABAB인 i-1자리 안전한 암호 수) = (i-5자리 안전한 암호 수)
ABCBC인 경우 (마지막이 ABCB인 i-1자리 안전한 암호 수) = (i-5자리 안전한 암호 수) - (마지막이 AB인 i-5자리 안전한 암호 수(ABABCB가 되어 위험한 암호가 되므로))
 = (i-5자리 안전한 암호 수) - (i-7자리 안전한 암호 수)
*/
#include <iostream>
#define INF 1000000009

using namespace std;

long long all[1000010], danger[1000010], secure[1000010];

int main()
{
    int n, k;
    
    cin>>n>>k;
    
    all[0] = 1;
    for (int i=1; i<=n; i++)
        all[i] = (all[i-1]*k)%INF;
    

    danger[5] = 2;
    danger[6] = k*4;
    for (int i=0; i<=n; i++)
    {
        if (i>=7)
        {
            danger[i] += danger[i-1]*k;
            danger[i] += secure[i-5]*2-secure[i-7];
            danger[i] %= INF;
        }
        secure[i] = (all[i]-danger[i]+INF)%INF;
    }

    cout<<secure[n];

    return 0;
}
