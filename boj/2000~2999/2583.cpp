#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
int board[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> v;

int BFS(int x, int y)
{
    if (x<0 || x>=n || y<0 || y>=m)
        return 0;
    if (board[x][y]==1)
        return 0;
    board[x][y] = 1;

    int cnt = 1;
    for (int i=0; i<4; i++)
        cnt += BFS(x+dx[i], y+dy[i]);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n>>k;
    for (int i=0; i<k; i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        for (int j=x1; j<x2; j++)
        {
            for (int k=y1; k<y2; k++)
                board[j][k] = 1;
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (board[i][j]==0)
                v.push_back(BFS(i, j));
        }
    }
    sort(v.begin(), v.end());

    cout<<v.size()<<'\n';
    for (int &i : v)
        cout<<i<<' ';

    return 0;
}
