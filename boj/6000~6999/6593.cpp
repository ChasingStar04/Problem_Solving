//3차원 BFS
#include <iostream>
#include <queue>

using namespace std;

struct zyxt
{
    int z;
    int y;
    int x;
    int t;
};

char board[31][31][31];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void Func(int l, int r, int c, zyxt s)
{
    queue<zyxt> que;

    que.push(s);
    while (!que.empty())
    {
        int nz = que.front().z;
        int ny = que.front().y;
        int nx = que.front().x;
        int nt = que.front().t;
        que.pop();

        if (board[nz][ny][nx]=='E')
        {
            cout<<"Escaped in "<<nt<<" minute(s).\n";
            return;
        }

        for (int i=0; i<6; i++)
        {
            if (nz+dz[i]<0 || nz+dz[i]>=l) continue;
            if (ny+dy[i]<0 || ny+dy[i]>=r) continue;
            if (nx+dx[i]<0 || nx+dx[i]>=c) continue;
            if (board[nz+dz[i]][ny+dy[i]][nx+dx[i]]=='S' || board[nz+dz[i]][ny+dy[i]][nx+dx[i]]=='#') continue;
            que.push({nz+dz[i], ny+dy[i], nx+dx[i], nt+1});
            if (board[nz+dz[i]][ny+dy[i]][nx+dx[i]]=='.') board[nz+dz[i]][ny+dy[i]][nx+dx[i]] = 'S';
        }
    }

    cout<<"Trapped!\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, c;

    cin>>l>>r>>c;
    while (l+r+c>0)
    {
        zyxt start;
        for (int i=0; i<l; i++)
        {
            for (int j=0; j<r; j++)
            {
                cin>>board[i][j];
                for (int k=0; k<c; k++)
                {
                    if (board[i][j][k]=='S')
                    {
                        start.z = i;
                        start.y = j;
                        start.x = k;
                        start.t = 0;
                    }
                }
            }
        }
        Func(l, r, c, start);

        cin>>l>>r>>c;
    }

    return 0;
}
