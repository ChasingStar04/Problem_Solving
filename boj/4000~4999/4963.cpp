//1이 발견되면 카운트해주고 dfs를 이용하여 상하좌우대각선으로 갈 수 있는 모든 1을 0으로 바꿔줍니다.
#include <iostream>

using namespace std;

int map[55][55];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dfs(int y, int x)
{
    if(map[y][x]==0)
        return;

    map[y][x] = 0;
    for(int i=0; i<8; i++)
        dfs(y+dy[i], x+dx[i]);
    return;
}

int main()
{
    int w, h;
    int cnt = 0;

    while (true)
    {
        cin>>w>>h;

        if(w==0 && h==0)
            break;
        
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
                cin>>map[i][j];
        }
        cnt = 0;

        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                if(map[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    
    return 0;
}
