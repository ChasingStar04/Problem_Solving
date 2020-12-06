/*
풀이 1.
dfs로 루트 노드에서 가장 멀리 떨어진 노드를 구한 후
그 노드에서 가장 멀리 떨어진 노드까지의 거리를 구합니다.
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Data
{
    int ver;  //목적지 노드
    int wei;  //가중치
};

vector<Data> edge[10010];
int visit[10010];
int far;  //루트노드에서 가장 멀리 떨어진 노드
int farlength;  //트리에서 가장 긴 경로

void dfs(int node, int wei)
{
    visit[node] = 1;

    if(farlength<wei)
    {
        far = node;
        farlength = wei;
    }
    for(int i=0; i<edge[node].size(); i++)
    {
        if(visit[edge[node][i].ver]==0)
            dfs(edge[node][i].ver, wei+edge[node][i].wei);
    }
    return;
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int a, b, wei;
        cin>>a>>b>>wei;
        edge[a].push_back({b, wei});
        edge[b].push_back({a, wei});
    }

    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    dfs(far, 0);
    cout<<farlength;

    return 0;
}
/*
풀이 2.
트리의 지름을 이루는 두 정점은 모두 단말 노드일 것이므로
단말 노드 - 부모 노드 - 단말 노드 의 형태로 이어진 형태일 것입니다.
dfs를 돌려 방문한 노드에서 단말 노드까지 가는 경로중 가장 긴 두개를 더해, 이전의 최댓값과 비교하고 더 크다면 갱신합니다.
이렇게 하여 구한 최댓값을 출력합니다.
원래 생각했던 풀이로, 위 코드에 비하면 비효율적입니다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Data
{
    int ver;
    int weight;
};

vector<Data> edge[10010];
int visit[10010];
int maxwei;  //트리에서 가장 긴 경로

int dfs(int node)
{
    visit[node] = 1;
    vector<int> weis;  //단말 노드-현재 노드까지의 거리 모음
    weis.push_back(0);
    for(int i=0; i<edge[node].size(); i++)
    {
        if(visit[edge[node][i].ver]==0)
            weis.push_back(dfs(edge[node][i].ver)+edge[node][i].weight);
    }
    sort(weis.begin(), weis.end(), greater<int>());
    if(weis.size()>=2)
        maxwei = max(maxwei, weis[0]+weis[1]);
    else
        maxwei = max(maxwei, weis[0]);
    
    return weis[0];
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int a, b, weight;
        
        cin>>a>>b>>weight;
        edge[a].push_back({b, weight});
        edge[b].push_back({a, weight});
    }

    dfs(1);
    cout<<maxwei;

    return 0;
}
*/
