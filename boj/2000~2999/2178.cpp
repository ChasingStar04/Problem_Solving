/*
bfs를 이용하여 (n, m)까지의 최단거리를 구합니다.
중복을 막기위해 visit[y][x]가 0이거나 현재거리<visit[y][x] 인 경우에만 큐에 넣습니다.
*/
#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct Data
{
    int y;
    int x;
    int dist;
};

int map[110][110];
int visit[110][110];  //(y, x)까지 가는 최단거리 저장. 더 짧을 경우에만 갱신
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
queue<Data> que;

void Push(int y, int x, int dist)  //예외처리, visit갱신 등등 + push
{
    if(map[y][x]==0 || (visit[y][x]!=0 && dist>=visit[y][x]))  //map의 가장자리가 0으로 채워져있어 y, x의 범위에 대한 체크는 필요 없습니다.
        return;
    
    visit[y][x] = dist;
    que.push({y, x, dist});
    return;
}

int bfs()
{
    Push(1, 1, 1);
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if(tmp.y==n && tmp.x==m)
            return tmp.dist;
        for(int i=0; i<4; i++)
            Push(tmp.y+dy[i], tmp.x+dx[i], tmp.dist+1);
    }
    return -1;  //warning 뜨는거 불편해서 넣었습니다. 필요 없습니다.
}

int main()
{
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for(int j=1; j<=m; j++)
            map[i][j] = s[j-1]-'0';
    }

    cout<<bfs();

    return 0;
}
