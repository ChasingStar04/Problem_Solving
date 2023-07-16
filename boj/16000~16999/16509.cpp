#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

struct rct
{
    int r;
    int c;
    int t;
};


int table[10][9];
int dire[8][2] = {{3, 2}, {3, -2}, {-3, 2}, {-3, -2}, {2, 3}, {2, -3}, {-2, 3}, {-2, -3}};
int r1, c1, r2, c2;
queue<rct> que;

bool CanMove(int r, int c, int d)
{
    if (table[r][c]!=-1)
        return false;
    if (r<0 || r>=10 || c<0 || c>=9)
        return false;
    int kr = dire[d][0]/abs(dire[d][0]);
    int kc = dire[d][1]/abs(dire[d][1]);
    if ((r-kr)==r2 && (c-kc)==c2)
        return false;
    if ((r-kr*2)==r2 && (c-kc*2)==c2)
        return false;
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>r1>>c1;
    cin>>r2>>c2;

    memset(table, -1, sizeof(table));
    que.push({r1, c1, 0});
    table[r1][c1] = 0;
    while (!que.empty())
    {
        int nr = que.front().r;
        int nc = que.front().c;
        int nt = que.front().t;
        que.pop();

        for (int i=0; i<8; i++)
        {
            if (CanMove(nr+dire[i][0], nc+dire[i][1], i))
            {
                que.push({nr+dire[i][0], nc+dire[i][1], nt+1});
                table[nr+dire[i][0]][nc+dire[i][1]] = nt+1;
            }
        }
    }

    cout<<table[r2][c2];

    return 0;
}
