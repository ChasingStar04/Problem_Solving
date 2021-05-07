//dfs로 갈 수 있는 최장경로를 탐색합니다.
//이때 visit 테이블은 좌표가 아닌 알파벳으로 설정합니다.
#include <iostream>
#include <algorithm>

using namespace std;

char board[21][21];
bool visit[26];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int r, c;

int dfs(int x, int y, int move)
{
    if (visit[board[y][x]-'A'])
        return 0;
    
    int result = move;
    visit[board[y][x]-'A'] = true;
    for (int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx>=0 && nx<c && ny>=0 && ny<r)
            result = max(result, dfs(nx, ny, move+1));
    }
    visit[board[y][x]-'A'] = false;
    return result;
}

int main()
{
    cin>>r>>c;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
            cin>>board[i][j];
    }

    cout<<dfs(0, 0, 1);

    return 0;
}
