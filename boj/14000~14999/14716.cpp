/*
플러드 필 알고리즘을 활용해 풀 수 있습니다.
banner에서 1을 발견하면 카운트를 +1 하고
상하좌우대각선으로 연결되어있는 모든 1들을 dfs를 이용하여 0으로 바꿔줍니다.
*/
#include <iostream>

using namespace std;

int banner[250][250];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int m, n;

void Fill(int y, int x)
{
    if(y<0 || y>=m || x<0 || x>=n || banner[y][x]==0)
        return;
    
    banner[y][x] = 0;
    for(int i=0; i<8; i++)
        Fill(y+dy[i], x+dx[i]);
    return;
}

int main()
{
    int cnt = 0;

    cin>>m>>n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cin>>banner[i][j];
    }
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(banner[i][j])
            {
                Fill(i, j);
                cnt++;
            }
        }
    }

    cout<<cnt;

    return 0;
}
