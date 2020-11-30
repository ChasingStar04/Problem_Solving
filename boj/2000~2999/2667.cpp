//dfs이용하여 연결되어있는 모든 집을 카운트해주고 0으로 바꿔줍니다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int map[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

int FloodFill(int y, int x)
{
    if(y<0 || y>=n || x<0 || x>=n || map[y][x]==0)
        return 0;
    
    int result = 1;
    map[y][x] = 0;
    for(int i=0; i<4; i++)
        result += FloodFill(y+dy[i], x+dx[i]);
    return result;
}

int main()
{
    vector<int> danji;  //각 단지내 집의 수
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j])
                danji.push_back(FloodFill(i, j));
        }
    }

    sort(danji.begin(), danji.end());
    cout<<danji.size()<<'\n';
    for(int i=0; i<danji.size(); i++)
        cout<<danji[i]<<'\n';
    
    return 0;
}
