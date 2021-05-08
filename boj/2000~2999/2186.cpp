//dfs + 시간 초과를 막기 위해 dp 테이블을 이용합니다.
//dp 테이블은 [y좌표][x좌표][몇 번째로 방문했는지] 로 구성합니다.
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char board[110][110];
int dp[110][110][81];
int n, m, k;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string key;

int dfs(int x, int y, int move)
{
    if (move>=key.length())
        return 1;

    int cnt = 0;
    for (int i=0; i<4; i++)
    {
        for (int j=1; j<=k; j++)
        {
            int nx = x+dx[i]*j;
            int ny = y+dy[i]*j;
            if (nx>=0 && nx<m && ny>=0 && ny<n && board[ny][nx]==key[move])
            {
                if (dp[ny][nx][move+1]!=-1)
                    cnt += dp[ny][nx][move+1];
                else
                {
                    dp[ny][nx][move+1] = dfs(nx, ny, move+1);
                    cnt += dp[ny][nx][move+1];
                }
            }
        }
    }

    return cnt;
}

int main()
{
    int cnt = 0;

    cin>>n>>m>>k;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            scanf(" %c", &board[i][j]);
    }
    cin>>key;
    
    memset(dp, -1, sizeof(dp));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (board[i][j]==key[0])
                cnt += dfs(j, i, 1);
        }
    }

    cout<<cnt;

    return 0;
}
