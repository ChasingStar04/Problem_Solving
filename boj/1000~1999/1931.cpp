//종료시점을 기준으로 오름차순 정렬하여 매 선택에서 끝나는 시간이 가장 빠른 회의를 선택합니다.
#include <iostream>
#include <algorithm>

using namespace std;

struct Data
{
    int start;
    int last;
} conf[100010];

bool cmp(Data a, Data b)
{
    if (a.last!=b.last)
        return a.last<b.last;
    else
        return a.start<b.start;
}

int main()
{
    int n;
    int cnt, now;

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>conf[i].start>>conf[i].last;
    
    sort(conf, conf+n, cmp);
    cnt = 1, now = 0;
    for (int i=1; i<n; i++)
    {
        if (conf[i].start>=conf[now].last)
        {
            cnt++;
            now = i;
        }
    }
    cout<<cnt;

    return 0;
}
