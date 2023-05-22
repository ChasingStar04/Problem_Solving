//전체길이 - (1씩 증가하는 LIS)
#include <iostream>

using namespace std;

int n;
int child[1000010], cnt[1000010];
int maxc;

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>child[i];
    
    for (int i=1; i<=n; i++)
    {
        int nown = child[i];
        cnt[nown] = cnt[nown-1]+1;
        maxc = max(maxc, cnt[nown]);
    }

    cout<<n-maxc;

    return 0;
}
