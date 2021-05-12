//bfs로 풀수있는 간단한 문제입니다.
#include <iostream>
#include <queue>

using namespace std;

struct Data
{
    int f;
    int move;
};

bool visit[1000010];
queue<Data> que;
int f, s, g, u, d;

int bfs()
{
    que.push({s, 0});
    visit[s] = true;
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if (tmp.f==g)
            return tmp.move;
        
        int nf = tmp.f+u;
        if (nf<=f && !visit[nf])
        {
            que.push({nf, tmp.move+1});
            visit[nf] = true;
        }
        nf = tmp.f-d;
        if (nf>0 && !visit[nf])
        {
            que.push({nf, tmp.move+1});
            visit[nf] = true;
        }
    }

    return -1;
}

int main()
{
    int res;

    cin>>f>>s>>g>>u>>d;
    res = bfs();
    if (res!=-1)
        cout<<res;
    else
        cout<<"use the stairs";
    
    return 0;
}
