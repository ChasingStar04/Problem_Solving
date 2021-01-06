//다익스트라 알고리즘을 구현하여 해결합니다.
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

struct Data
{
    int node;
    int cost;
};

vector<Data> edge[1010];
int dist[1010];
priority_queue<Data> pq;

bool operator<(Data a, Data b)
{
    return a.cost>b.cost;
}

int main()
{
    int n, m;
    int sp, ep;  //출발지 도착지

    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int start, node, cost;

        cin>>start>>node>>cost;
        edge[start].push_back({node, cost});
    }
    cin>>sp>>ep;

    memset(dist, 0x3f, sizeof(dist));
    dist[sp] = 0;
    pq.push({sp, 0});
    while(!pq.empty())
    {
        Data now = pq.top();
        pq.pop();

        if(now.cost>dist[now.node])
            continue;
        
        for(int i=0; i<edge[now.node].size(); i++)
        {
            int nextnode = edge[now.node][i].node;
            int nextcost = dist[now.node]+edge[now.node][i].cost;

            if(nextcost<dist[nextnode])
            {
                dist[nextnode] = nextcost;
                pq.push({nextnode, nextcost});
            }
        }
    }

    cout<<dist[ep];

    return 0;
}
