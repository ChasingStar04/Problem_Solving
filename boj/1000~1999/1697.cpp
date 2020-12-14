//bfs를 활용하여 최단거리를 구합니다.
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int visit[100010];  //방문했는지 확인 + 최단거리 저장
queue<int> que;

void Push(int num, int time)  //visit체크 + 큐에 push
{
    if(num<0 || num>100000 || visit[num]!=-1)
        return;
    visit[num] = time;
    que.push(num);
    return;
}

int main()
{
    int n, k;

    cin>>n>>k;

    memset(visit, -1, sizeof(visit));
    Push(n, 0);
    while (!que.empty())
    {
        int tmp = que.front();
        que.pop();

        if(tmp==k)
        {
            cout<<visit[tmp];
            break;
        }
        
        Push(tmp-1, visit[tmp]+1);
        Push(tmp+1, visit[tmp]+1);
        Push(tmp*2, visit[tmp]+1);
    }
    
    return 0;
}
