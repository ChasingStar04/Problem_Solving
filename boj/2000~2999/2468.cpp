#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int board[110][110] = {0};
    bool visit[110][110] = {false};
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin>>board[i][j];
    }

    queue<pair<int, int>> que;
    int cnt = 0, maxcnt = 1;
    for (int i=1; i<=99; i++)
    {
        memset(visit, false, sizeof(visit));
        cnt = 0;
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (board[j][k]>i && !visit[j][k])
                {
                    que.push({j, k});
                    while (!que.empty())
                    {
                        pair<int, int> np = que.front();
                        que.pop();

                        for (int l=0; l<4; l++)
                        {
                            int nx = np.second+dx[l];
                            int ny = np.first+dy[l];
                            if (nx>=0 && nx<n && ny>=0 && ny<n && board[ny][nx]>i && !visit[ny][nx])
                            {
                                que.push({ny, nx});
                                visit[ny][nx] = true;
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        maxcnt = max(maxcnt, cnt);
    }

    cout<<maxcnt;

    return 0;
}
