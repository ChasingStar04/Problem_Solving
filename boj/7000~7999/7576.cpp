//https://chasingstar.tistory.com/20
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Data
{
    int y;
    int x;
    int date;
};

int map[1010][1010];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    int m, n;  //m=>y, n=>x
    int cnt = 0;  //안익은 토마토의 개수
    queue<Data> que;

    cin>>m>>n;
    memset(map, -1, sizeof(map));  //가장자리를 -1로 채워줌
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>map[i][j];
            if(map[i][j]!=-1)
            {
                cnt++;
                if(map[i][j])
                    que.push({i, j, 0});
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
            cout<<tmp.date;
            return 0;
        }

        for(int i=0; i<4; i++)
        {
            if(map[tmp.y+dy[i]][tmp.x+dx[i]]==0)
            {
                que.push({tmp.y+dy[i], tmp.x+dx[i], tmp.date+1});
                map[tmp.y+dy[i]][tmp.x+dx[i]] = 1;
            }
        }
    }
    cout<<-1;

    return 0;
}
