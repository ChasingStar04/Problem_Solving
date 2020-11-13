//https://chasingstar.tistory.com/17
//DP+DFS를 이용한 풀이
#include <iostream>
#include <cstring>

using namespace std;

int map[500][500], dp[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n;

int dfs(int y, int x)
{
    if(dp[y][x]!=-1)
        return dp[y][x];
    
    dp[y][x] = 0;
    for(int i=0; i<4; i++)
    {
        int newx = x+dx[i];
        int newy = y+dy[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m && map[y][x]>map[newy][newx])
            dp[y][x] += dfs(newy, newx);
    }

    return dp[y][x];
}

int main()
{
    cin>>m>>n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cin>>map[i][j];
    }

    memset(dp, -1, sizeof(dp));
    dp[m-1][n-1] = 1;
    cout<<dfs(0, 0);
    
    return 0;
}

/*
//DP+정렬을 이용한 풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    int x;
    int y;
    int height;
};

vector<Data> blocks;  //각 칸의 좌표와 높이 저장

bool cmp(Data a, Data b)
{
    return a.height>b.height;
}

int main()
{
    int m, n, map[502][502] = {0}, dp[502][502] = {0};
    cin>>m>>n;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>map[i][j];
            blocks.push_back({j, i, map[i][j]});
        }
    }

    sort(blocks.begin(), blocks.end(), cmp);

    dp[1][1] = 1;
    for(int i=0; i<blocks.size(); i++)
    {
        int x = blocks[i].x, y = blocks[i].y;

        if(map[y][x]<map[y][x+1])
            dp[y][x] += dp[y][x+1];
        if(map[y][x]<map[y][x-1])
            dp[y][x] += dp[y][x-1];
        if(map[y][x]<map[y-1][x])
            dp[y][x] += dp[y-1][x];
        if(map[y][x]<map[y+1][x])
            dp[y][x] += dp[y+1][x];
    }

    cout<<dp[m][n];

    return 0;
}
*/
