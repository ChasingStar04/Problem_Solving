//백트래킹 + visit 테이블을 위한 비트마스크로 해결할 수 있습니다.
#include <iostream>
#include <cstring>

using namespace std;

int n, p;
int c[16][16];
int visit[66000];
int result = 0x3f3f3f3f;

void Solve(int check, int cnt, int cost)
{
    if (visit[check]<=cost)
        return;
    if (cnt>=p)
    {
        if (result>cost)
            result = cost;
        return;
    }
    visit[check] = cost;

    for (int i=0; i<n; i++)
    {
        if ((check&(1<<i))==0)
            continue;
        for (int j=0; j<n; j++)
        {
            if ((check&(1<<j))==0)
                Solve(check|(1<<j), cnt+1, cost+c[i][j]);
        }
    }
    return;
}

int main()
{
    int check = 0, cnt = 0;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin>>c[i][j];
    }
    for (int i=0; i<n; i++)
    {
        char tmp;
        scanf(" %c", &tmp);
        if (tmp=='Y')
        {
            check |= (1<<i);
            cnt++;
        }
    }
    cin>>p;

    memset(visit, 0x3f, sizeof(visit));
    Solve(check, cnt, 0);
    cout<<(result!=0x3f3f3f3f ? result : -1);
    
    return 0;
}
