//DFS를 이용하고, 주운 보석을 비트마스크로 표현합니다.
#include <iostream>
#include <vector>

using namespace std;

struct Data
{
    int dst;
    int str;
};

int n, m, k;
int jewel[101]; //보석이 없는 섬은 0, 있는 섬은 1~k까지 번호 지정
vector<Data> edge[101];
bool visit[101][17000];
int result;

int CountJewel(int jwl)
{
    int cnt = 0;
    while (jwl>0)
    {
        cnt += jwl%2;
        jwl /= 2;
    }
    return cnt;
}

void DFS(int node, int jwl)
{
    if (visit[node][jwl])
        return;
    visit[node][jwl] = true;

    for (Data &i : edge[node]) //보석을 줍지 않은 경우
    {
        if (CountJewel(jwl)<=i.str)
            DFS(i.dst, jwl);
    }
    if (jewel[node]) //보석을 주운 경우
    {
        jwl |= (1<<(jewel[node]-1));
        for (Data &i : edge[node])
        {
            if (CountJewel(jwl)<=i.str)
                DFS(i.dst, jwl);
        }
    }
    
    if (node==1)
        result = max(result, CountJewel(jwl));
    
    return;
}

int main()
{
    cin>>n>>m>>k;

    for (int i=1; i<=k; i++)
    {
        int tmp;
        cin>>tmp;
        jewel[tmp] = i;
    }
    for (int i=0; i<m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    DFS(1, 0);
    cout<<result;

    return 0;
}
