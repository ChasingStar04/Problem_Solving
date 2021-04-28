//bfs를 이용하여 a에서 b까지 가는 데 필요한 최소한의 명령어를 구합니다.
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Data
{
    int num;
    string command;
};

string bfs(int a, int b)
{
    queue<Data> que;
    bool visit[10000] = {false};
    string s = "";
    
    que.push({a, s});
    visit[a] = true;
    while (!que.empty())
    {
        Data tmp = que.front();
        que.pop();

        if (tmp.num==b)
            return tmp.command;
        
        int next = tmp.num*2%10000;
        if (!visit[next])
        {
            que.push({next, tmp.command+'D'});
            visit[next] = true;
        }
        next = (tmp.num-1>=0) ? tmp.num-1 : 9999;
        if (!visit[next])
        {
            que.push({next, tmp.command+'S'});
            visit[next] = true;
        }
        next = (tmp.num*10%10000)+(tmp.num-tmp.num%1000)/1000;
        if (!visit[next])
        {
            que.push({next, tmp.command+'L'});
            visit[next] = true;
        }
        next = (tmp.num/10)+(tmp.num%10)*1000;
        if (!visit[next])
        {
            que.push({next, tmp.command+'R'});
            visit[next] = true;
        }
    }

    return s="warning"; //warning뜨는거 보기싫어서 넣은 코드
}

int main()
{
    int t;

    cin>>t;
    for (int i=0; i<t; i++)
    {
        int a, b;

        cin>>a>>b;
        cout<<bfs(a, b)<<'\n';
    }

    return 0;
}
