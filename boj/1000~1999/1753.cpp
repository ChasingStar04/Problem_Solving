//우선순위 큐를 활용한 다익스트라 알고리즘으로 문제를 해결합니다.
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

struct Data
{
    int node;
    int dist;
};

vector<Data> edge[20010];
int dist[20010];
priority_queue<Data> pq;

bool operator<(Data a, Data b)
{
    return a.dist>b.dist;
}

int main()
{
    int v, e;
    int k;

    cin>>v>>e;
    cin>>k;
    for(int i=0; i<e; i++)
    {
        int start, node, dist;
        cin>>start>>node>>dist;
        edge[start].push_back({node, dist});
    }

    memset(dist, 0x3f, sizeof(dist));
    pq.push({k, 0});
    dist[k] = 0;
    while(!pq.empty())
    {
        Data now = pq.top();
        pq.pop();

        if(now.dist>dist[now.node])
            continue;
        
        for(int i=0; i<edge[now.node].size(); i++)
        {
            int nextnode = edge[now.node][i].node;
            int nextdist = dist[now.node]+edge[now.node][i].dist;

            if(nextdist<dist[nextnode])  //새로운 경로가 원래 경로보다 더 짧다면 갱신하고 큐에 넣습니다.
            {
                dist[nextnode] = nextdist;
                pq.push({nextnode, nextdist});
            }
        }
    }

    for(int i=1; i<=v; i++)
    {
        if(dist[i]==INF)
            cout<<"INF\n";
        else
            cout<<dist[i]<<'\n';
    }

    return 0;
}
