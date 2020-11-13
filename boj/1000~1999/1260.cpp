/*
c++로 dfs와 bfs를 구현해봅시다.
dfs와 bfs를 쉽게 설명하자면 dfs는 1번길 끝까지 -> 2번길 끝까지 -> 3번길 끝까지 이고
bfs는 1번길 한걸음 -> 2번길 한걸음 -> 3번길 한걸음 -> 1번길 한걸음 더 -> ... 이런 느낌입니다.
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int edge[1001][1001], visit[1001];

void dfs(int n, int node)
{
    if(visit[node])
        return;

    visit[node] = 1;
    cout<<node<<' ';

    for(int i=1; i<=n; i++)
    {
        if(edge[node][i])
            dfs(n, i);
    }
    return;
}

void bfs(int n, int v)
{
    queue<int> que;

    que.push(v);
    while (!que.empty())
    {
        int tmp = que.front();
        que.pop();

        if(visit[tmp]==0)
        {
            cout<<tmp<<' ';
            visit[tmp] = 1;

            for(int i=1; i<=n; i++)
            {
                if(edge[tmp][i])
                    que.push(i);
            }
        }
    }
    return;
}

int main()
{
    int n, m, v;

    cin>>n>>m>>v;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    dfs(n, v);
    puts("");
    memset(visit, 0, sizeof(visit));
    bfs(n, v);

    return 0;
}
