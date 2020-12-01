/*
bfs를 이용하여 정점을 방문할 때마다 이전 노드와 다른 집합으로 설정해주고
연결되어있는 정점들중 자신과 같은 집합의 노드가 있는지 체크합니다.

주의해야할 점은 연결 그래프가 아닌 경우도 있다는 것입니다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> edge[20010];
int group[20010];

bool bfs(int node)  //bfs돌려서 이분그래프인지 아닌지 확인합니다
{
    queue<int> que;

    group[node] = 1;
    que.push(node);
    while(!que.empty())
    {
        int tmp = que.front();
        que.pop();
        
        for(int i=0; i<edge[tmp].size(); i++)
        {
            if(group[tmp]==group[edge[tmp][i]])
                return false;
            if(group[edge[tmp][i]]==0)
            {
                group[edge[tmp][i]] = (group[tmp]==1 ? 2 : 1);
                que.push(edge[tmp][i]);
            }
        }

    }

    return true;
}

int main()
{
    int k;

    cin>>k;
    for(int i=0; i<k; i++)
    {
        int v, e;
        cin>>v>>e;

        for(int i=1; i<=v; i++)
            edge[i].clear();
        memset(group, 0, sizeof(group));
        for(int j=0; j<e; j++)
        {
            int a, b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        bool bipartite_or_not = true;
        for(int i=1; i<=v; i++)
        {
            if(group[i]==0)
            {
                if(!bfs(i))
                    bipartite_or_not = false;
            }
        }
        if(bipartite_or_not)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
