//2531번 문제에서 n의 크기만 커짐.
#include <iostream>

using namespace std;

int sushi[3000010], num[3010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k, c;
    int cnt = 0, maxcnt = 0;

    cin>>n>>d>>k>>c;
    for (int i=0; i<n; i++)
        cin>>sushi[i];

    for (int i=0; i<k; i++) //1~k번 접시를 고르는 경우
        num[sushi[i]]++;
    num[c]++;
    for (int i=1; i<=d; i++)
    {
        if (num[i]>0)
            cnt++;
    }
    maxcnt = cnt;

    for (int i=0; i<n-1; i++)
    {
        int next = (i+k)%n;
        if (num[sushi[next]]==0) cnt++;
        num[sushi[next]]++;

        num[sushi[i]]--;
        if (num[sushi[i]]==0) cnt--;
        maxcnt = max(maxcnt, cnt);
    }

    cout<<maxcnt;

    return 0;
}
