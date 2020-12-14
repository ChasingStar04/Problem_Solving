/*
1번 노드에서 dfs를 돌려 가장 멀리 떨어진 노드를 찾은 뒤
그 노드에서 다시 한번 dfs를 돌려 가장 멀리 떨어진 노드와의 거리를 구합니다.
*/
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

vector<pair<int, int>>  edge[100010];  //pair(연결된 노드, 거리)
bool visit[100010];
int farnode;
int farlength;

void dfs(int node, int length)
{
    if(visit[node])
        return;
    
    visit[node] = true;
    if(length>farlength)
    {
        farnode = node;
        farlength = length;
    }

    for(int i=0; i<edge[node].size(); i++)
        dfs(edge[node][i].first, length+edge[node][i].second);
    return;
}

int main()
{
    int v;
    
    cin>>v;
    for(int i=0; i<v; i++)
    {
        int node;
        cin>>node;
        while (true)
        {
            int a;
            cin>>a;
            if(a!=-1)
            {
                int b;
                cin>>b;
                edge[node].push_back(make_pair(a, b));
            }
            else
                break;
        }
    }

    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    dfs(farnode, 0);
    cout<<farlength;

    return 0;
}
