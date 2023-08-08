#include <iostream>

using namespace std;

int n, cnt, rgcnt;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char board[110][110];
bool visit[110][110], rgvisit[110][110];

void DFS(int y, int x, char c)
{
    if (y<0 || y>=n || x<0 || x>=n || visit[y][x] || board[y][x]!=c) return;

    visit[y][x] = true;
    for (int i=0; i<4; i++)
        DFS(y+dy[i], x+dx[i], c);
}

void rgDFS(int y, int x, char c)
{
    if (y<0 || y>=n || x<0 || x>=n || rgvisit[y][x]) return;
    if ((board[y][x]=='B' || c=='B') && board[y][x]!=c) return;

    rgvisit[y][x] = true;
    for (int i=0; i<4; i++)
        rgDFS(y+dy[i], x+dx[i], c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>board[i];
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (!visit[i][j])
            {
                cnt++;
                DFS(i, j, board[i][j]);
            }
            if (!rgvisit[i][j])
            {
                rgcnt++;
                rgDFS(i, j, board[i][j]);
            }
        }
    }
    cout<<cnt<<' '<<rgcnt<<'\n';

    return 0;
}
