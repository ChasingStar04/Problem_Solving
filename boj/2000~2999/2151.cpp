/*
bfs로 풀 수 있습니다
한쪽 문에서 출발하여 !를 만날 때마다 가던방향, 왼쪽으로 꺾은방향, 오른쪽으로 꺾은방향으로 큐에 push합니다
자세한 내용은 코드를 참고하세요
*/
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Data
{
    int x;
    int y;
    int dire;
    int cnt;
};

int dic[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};  //동0서1남2북3
char house[50][50];
int check[50][50];

int func(int n, int x, int y)
{
    queue<Data> que;
    int result = 0x3f3f3f3f;

    memset(check, -1, sizeof(check));

    if(x==0)  que.push({x, y, 0, 0});
    if(x==n-1)  que.push({x, y, 1, 0});
    if(y==0)  que.push({x, y, 2, 0});
    if(y==n-1)  que.push({x, y, 3, 0});
    while(!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        do
        {
            tmp.x += dic[tmp.dire][0];
            tmp.y += dic[tmp.dire][1];
        } while (house[tmp.y][tmp.x]=='.');

        if(house[tmp.y][tmp.x]=='!' && (check[tmp.y][tmp.x]==-1 || tmp.cnt<check[tmp.y][tmp.x]))
        {
            check[tmp.y][tmp.x] = tmp.cnt;
            que.push({tmp.x, tmp.y, tmp.dire, tmp.cnt});
            if(tmp.dire<=1)
            {
                que.push({tmp.x, tmp.y, 2, tmp.cnt+1});
                que.push({tmp.x, tmp.y, 3, tmp.cnt+1});
            }
            else
            {
                que.push({tmp.x, tmp.y, 0, tmp.cnt+1});
                que.push({tmp.x, tmp.y, 1, tmp.cnt+1});
            }
        }
        else if(house[tmp.y][tmp.x]=='#' && (tmp.x!=x || tmp.y!=y))
            result = min(result, tmp.cnt);
    }

    return result;
}

int main()
{
    int n, x, y;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>house[i][j];
            if(house[i][j]=='#')
            {
                x = j;
                y = i;
            }
        }
    }
    cout<<func(n, x, y);

    return 0;
}