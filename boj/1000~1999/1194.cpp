//BFS를 이용합니다. 가지고 있는 열쇠는 비트마스크로 표현합니다.
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

struct Data
{
    int x;
    int y;
    int key;
    int cost;
};

char map[55][55];
int n, m;
pair<int, int> start; //x, y
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS()
{
    queue<Data> que;
    bool visit[55][55][64] = {0};

    que.push({start.first, start.second, 0, 0});
    visit[start.second][start.first][0] = true;
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if (map[tmp.y][tmp.x]=='1')
            return tmp.cost;
        
        if (map[tmp.y][tmp.x]>='a' && map[tmp.y][tmp.x]<='f')
            tmp.key |= (1<<(map[tmp.y][tmp.x]-'a'));
        
        for (int i=0; i<4; i++)
        {
            int nx = tmp.x+dx[i], ny = tmp.y+dy[i];
            if (nx<0 || nx>=m || ny<0 || ny>=n) continue; //범위를 벗어났다면
            if (map[ny][nx]=='#' || visit[ny][nx][tmp.key]) continue; //벽이라면, 이미 방문했다면
            if (map[ny][nx]>='A' && map[ny][nx]<='F' && (tmp.key&(1<<(map[ny][nx]-'A')))==0) continue; //문인데 열쇠가 없다면

            que.push({nx, ny, tmp.key, tmp.cost+1});
            visit[ny][nx][tmp.key] = true;
        }
    }
    
    return -1;
}

int main()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            scanf(" %c", &map[i][j]);
            if (map[i][j]=='0')
            {
                start.first = j;
                start.second = i;
            }
        }
    }

    cout<<BFS();

    return 0;
}
