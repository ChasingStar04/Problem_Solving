/*
1부터 dfs를 돌리면서
방문한 노드와 연결되어있고 부모가 설정되지 않은 노드들의 부모를 자신으로 해줍니다.
*/ 
#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[100010];
int parent[100010];  //각 노드의 부모 노드
int n;

void dfs(int node)
{
    for(int i=0; i<edge[node].size(); i++)
    {
        if(parent[edge[node][i]]==0)
        {
            parent[edge[node][i]] = node;
            dfs(edge[node][i]);
        }
    }
    return;
}

int main()
{
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    parent[1] = -1;
    dfs(1);
    for(int i=2; i<=n; i++)
        cout<<parent[i]<<'\n';
    
    return 0;
}
