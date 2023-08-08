/*
따로 visit테이블을 만들지 않고, 입력받은 board를 visit테이블로 사용합니다.
(큐에서 하나 꺼내기) -> (탈출여부&잘못된 이동 여부 확인) -> (board를 자신의 알파벳(F J)으로 채우기) -> (상하좌우 큐에 push) 과정으로 동작합니다.
현재 위치가 보드판에서 '.'가 아니라면 잘못된 이동으로 간주하고,
처음에 F를 J보다 먼저 넣으므로써 F와 J가 동시에 도달하는 문제도 해결할 수 있습니다.
*/
#include <iostream>
#include <queue>

using namespace std;

struct yxtc
{
    int y;
    int x;
    int t;
    char c;
};

int r, c;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char board[1010][1010];
queue<yxtc> que;

void Func()
{
    while (!que.empty())
    {
        int ny = que.front().y;
        int nx = que.front().x;
        int nt = que.front().t;
        char nc = que.front().c;
        que.pop();
        //cout<<ny<<' '<<nx<<' '<<nt<<' '<<nc<<'\n';

        if (ny<0 || ny>=r || nx<0 || nx>=c)
        {
            if (nc=='J')
            {
                cout<<nt;
                return;
            }
            else
                continue;
        }
        if (board[ny][nx]!='.')
            continue;
        
        board[ny][nx] = nc;
        for (int i=0; i<4; i++)
            que.push({ny+dy[i], nx+dx[i], nt+1, nc});
    }

    cout<<"IMPOSSIBLE";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>r>>c;
    for (int i=0; i<r; i++)
    {
        cin>>board[i];
        for (int j=0; j<c; j++)
        {
            if (board[i][j]=='F')
            {
                que.push({i, j, 0, 'F'});
                board[i][j] = '.';
            }
        }
    }
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            if (board[i][j]=='J')
            {
                que.push({i, j, 0, 'J'});
                board[i][j] = '.';
            }
        }
    }

    Func();

    return 0;
}
