/*
먼저 각각의 섬들을 각기 다른 색으로 칠해줍니다.
그후 각 섬에서 bfs를 돌려 가장 가까운 섬까지의 거리의 최솟값을 구합니다.
*/
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Data
{
    int x;
    int y;
    int distance;
};

int map[110][110];
int visit[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

void FloodFill(int x, int y, int color)
{
    if(map[y][x]!=1)
        return;
    
    map[y][x] = color;
    for(int i=0; i<4; i++)
        FloodFill(x+dx[i], y+dy[i], color);
    return;
}

int bfs(int x, int y)
{
    int color = map[y][x];
    int minlen = 999999;
    queue<Data> que;

    que.push({x, y, 0});
    visit[y][x] = 0;
    while(!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if(map[tmp.y][tmp.x]!=color && map[tmp.y][tmp.x]>1)  //다른 섬에 도착한 경우 최솟값을 갱신합니다
        {
            if(tmp.distance<minlen)
                minlen = tmp.distance;
            continue;
        }

        for(int i=0; i<4; i++)
        {
            int newx = tmp.x+dx[i], newy = tmp.y+dy[i];
            int newd = (map[newy][newx]==color ? 0 : tmp.distance+1);
            if(map[newy][newx]!=-1 && newd<visit[newy][newx])  //-1이 아니고, 원래 거리보다 더 짧다면
            {
                que.push({newx, newy, newd});
                visit[newy][newx] = newd;
            }
        }
    }

    return minlen;
}

int main()
{
    int color = 2;
    int minlen = 999999;
    vector<pair<int, int>> island;  //x, y

    cin>>n;
    memset(map, -1, sizeof(map));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cin>>map[i][j];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(map[i][j]==1)
            {
                island.push_back({j, i});
                FloodFill(j, i, color++);  //각각의 섬마다 다른 숫자로 채워줍니다
            }
        }
    }

    for(int i=0; i<island.size(); i++)
    {
        memset(visit, 0x3f, sizeof(visit));
        minlen = min(minlen, bfs(island[i].first, island[i].second));
    }
    cout<<minlen-1;

    return 0;
}