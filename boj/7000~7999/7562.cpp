#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct xyt
{
    int x;
    int y;
    int t;
};

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
bool visit[310][310];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin>>t;
    for (int i=0; i<t; i++)
    {
        int l, sx, sy, ex, ey;
        queue<xyt> que;
        cin>>l;
        cin>>sx>>sy;
        cin>>ex>>ey;

        memset(visit, false, sizeof(visit));
        que.push({sx, sy, 0});
        visit[sx][sy] = true;
        while (!que.empty())
        {
            xyt f = que.front();
            que.pop();
            
            if (f.x==ex && f.y==ey)
            {
                cout<<f.t<<'\n';
                break;
            }

            for (int j=0; j<8; j++)
            {
                int nx = f.x+dx[j];
                int ny = f.y+dy[j];
                int nt = f.t+1;
                if (nx<0 || nx>=l || ny<0 || ny>=l) continue;
                if (visit[nx][ny]) continue;
                que.push({nx, ny, nt});
                visit[nx][ny] = true;
            }
        }
    }

    return 0;
}
