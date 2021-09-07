/*
입력을 받으면서 밖으로 구멍이 뚫려있는 칸의 {x좌표, y좌표, 높이}를 우선순위 큐에 넣습니다.
pq는 높이가 낮은 칸부터 먼저 나오도록 설정합니다.

이후 pq가 빌 때까지 위 과정을 반복합니다.
1. 칸 하나를 뽑고, 그 칸의 높이가 설정되어 있지 않다면 높이를 큐에서 나온 높이로 설정해줍니다.
2. 현재 칸의 높이가 설정되어 있지 않았다면, 현재 칸 상하좌우에 있는 칸들을 탐색합니다.
만약 구멍으로 연결된 칸이 있다면 {연결된 큐의 x좌표, 연결된 큐의 y좌표, max(구멍의 높이, 현재 칸의 높이)}를 우선순위 큐에 넣습니다.
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Data
{
    int x;
    int y;
    int h;
};

bool operator<(Data a, Data b)
{
    return a.h>b.h;
}

int n, m, h;
int spot[1010][1010][4];  //동 서 남 북
int high[1010][1010];
priority_queue<Data> pq;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    long long cnt = 0;

    cin>>n>>m>>h;

    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<m; j++)
        {
            int input;
            cin>>input;
            if (i<n) spot[i][j][3] = input;
            if (i>0) spot[i-1][j][2] = input;

            if (i==0 && input!=-1) pq.push({j, i, input});
            if (i==n && input!=-1) pq.push({j, i-1, input});
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m+1; j++)
        {
            int input;
            cin>>input;
            if (j<m) spot[i][j][1] = input;
            if (j>0) spot[i][j-1][0] = input;

            if (j==0 && input!=-1) pq.push({j, i, input});
            if (j==m && input!=-1) pq.push({j-1, i, input});
        }
    }

    memset(high, 0x3f, sizeof(high));
    while (!pq.empty())
    {
        Data tmp = pq.top();
        pq.pop();

        if (high[tmp.y][tmp.x]!=0x3f3f3f3f)
            continue;
        
        high[tmp.y][tmp.x] = tmp.h;

        for (int i=0; i<4; i++)
        {
            int nx = tmp.x+dx[i];
            int ny = tmp.y+dy[i];
            if (spot[tmp.y][tmp.x][i]!=-1 && nx>=0 && nx<m && ny>=0 && ny<n)
            {
                pq.push({nx, ny, max(spot[tmp.y][tmp.x][i], tmp.h)});
            }
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        cnt += (long long)(high[i][j]==0x3f3f3f3f ? h : high[i][j]);
    }
    cout<<cnt;

    return 0;
}
