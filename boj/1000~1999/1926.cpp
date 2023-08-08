#include <iostream>

using namespace std;

int n, m, cnt = 0, maxsize = 0;
int board[510][510] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(int y, int x)
{
    if (y<0 || y>=n || x<0 || x>=m)
        return 0;
    if (board[y][x]==0)
        return 0;
    
    board[y][x] = 0;
    int ans = 1;
    for (int i=0; i<4; i++)
        ans += BFS(y+dy[i], x+dx[i]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cin>>board[i][j];
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (board[i][j]==1)
            {
                maxsize = max(maxsize, BFS(i, j));
                cnt++;
            }
        }
    }

    cout<<cnt<<'\n';
    cout<<maxsize<<'\n';

    return 0;
}
