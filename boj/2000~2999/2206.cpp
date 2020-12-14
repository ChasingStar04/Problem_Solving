/*
bfs에서 활용할 큐에 x좌표, y좌표, 벽을 통과한 횟수, 거리를 저장하게 하고
1인 칸을 가려면 벽을 통과한 횟수가 0일 때만 갈 수 있도록 합니다.
*/
#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

struct Data
{
    int x;
    int y;
    int wall;
    int dist;
};

int map[1010][1010];
bool visit[1010][1010][2];  //[][][0] = 벽뚫 O, [][][1] = 벽뚫 X
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
queue<Data> que;

void Push(int x, int y, int wall, int dist)
{
    if(y>=1 && y<=n && x>=1 && x<=m && !visit[x][y][wall])  //배열 범위를 벗어나지 않고, 방문한 적이 없다면
    {
        if(map[y][x] && wall==0)
        {
            visit[x][y][wall] = true;
            que.push({x, y, 1, dist});
        }
        else if(map[y][x]==0)
        {
            visit[x][y][wall] = true;
            que.push({x, y, wall, dist});
        }
    }
    return;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            scanf("%1d", &map[i][j]);
    }

    Push(1, 1, 0, 1);
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if(tmp.y==n && tmp.x==m)
        {
            cout<<tmp.dist;
            return 0;
        }

        for(int i=0; i<4; i++)
            Push(tmp.x+dx[i], tmp.y+dy[i], tmp.wall, tmp.dist+1);
    }
    cout<<-1;

    return 0;
}
