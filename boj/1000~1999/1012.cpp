//1을 발견하면 카운트해주고 주위에 갈수있는 모든 1들을 0으로 바꿔줍니다.
#include <iostream>
#include <cstring>
using namespace std;

int map[52][52];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n, k;

void dfs(int y, int x)
{
    if(map[y][x]==0 || y<0 || y>=n || x<0 || x>=m)
        return;
    map[y][x] = 0;
    for(int i=0; i<4; i++)
        dfs(y+dy[i], x+dx[i]);
    return;
}

int main()
{
    int t;

    cin>>t;
    for(int i=0; i<t; i++)
    {
        int cnt = 0;

        cin>>m>>n>>k;
        for(int i=0; i<k; i++)
        {
            int x, y;
            cin>>x>>y;
            map[y][x] = 1;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout<<cnt<<'\n';
    }

    return 0;
}
