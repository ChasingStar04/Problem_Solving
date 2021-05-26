/*
bfs를 이용하여 풀 수 있습니다.
visit 테이블에 현재 위치까지 가기위해 부순 벽의 최소 갯수를 저장하고
visit 테이블에 있는 값보다 더 작은 경우에만 탐색을 진행합니다.
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Data
{
    int x;
    int y;
    int b;
};

int visit[110][110];
int maze[110][110];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int n, int m)
{
    int ans = 0x3f3f3f3f;
    queue<Data> que;

    que.push({1, 1, 0});
    visit[1][1] = 0;
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if (tmp.y==n && tmp.x==m)
            ans = min(ans, tmp.b);
        
        for (int i=0; i<4; i++)
        {
            int nx = tmp.x+dx[i];
            int ny = tmp.y+dy[i];
            int nb = maze[ny][nx]==1 ? tmp.b+1 : tmp.b;
            if (nx>=1 && nx<=m && ny>=1 && ny<=n && nb<visit[ny][nx])
            {
                que.push({nx, ny, nb});
                visit[ny][nx] = nb;
            }
        }
    }

    return ans;
}

int main()
{
    int m, n;

    cin>>m>>n;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            scanf("%1d", &maze[i][j]);
    }

    memset(visit, 0x3f, sizeof(visit));
    cout<<bfs(n, m);

    return 0;
}
