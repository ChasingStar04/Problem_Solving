/*
//https://chasingstar.tistory.com/20
위 문제 코드를 3차원으로 바꿔 줍니다.
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Data{
    int x;
    int y;
    int z;
    int dist;
};

int map[110][110][110];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<Data> que;

int main()
{
    int m, n, h;
    int cnt = 0;

    memset(map, -1, sizeof(map));
    cin>>m>>n>>h;
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=m; k++)
            {
                cin>>map[i][j][k];
                if(map[i][j][k]!=-1)
                {
                    cnt++;
                    if(map[i][j][k])
                        que.push({k, j, i, 0});
                }
            }
        }
    }
    
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        cnt--;
        if(cnt<=0)
        {
            cout<<tmp.dist;
            return 0;
        }

        for(int i=0; i<6; i++)
        {
            if(map[tmp.z+dz[i]][tmp.y+dy[i]][tmp.x+dx[i]]==0)
            {
                map[tmp.z+dz[i]][tmp.y+dy[i]][tmp.x+dx[i]] = 1;
                que.push({tmp.x+dx[i], tmp.y+dy[i], tmp.z+dz[i], tmp.dist+1});
            }
        }
    }
    cout<<-1;

    return 0;
}
