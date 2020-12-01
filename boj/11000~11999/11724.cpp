//방문하지 않은 노드가 나오면 카운트해주고, dfs를 이용하여 그 노드에서 갈 수 있는 모든 노드의 visit를 1로 바꿔줍니다.
#include <iostream>
#include <vector>

using namespace std;

vector<int> road[1010];
int visit[1010];

void dfs(int node)
{
    if(visit[node])
        return;
    
    visit[node] = 1;
    for(int i=0; i<road[node].size(); i++)
        dfs(road[node][i]);
    return;
}

int main()
{
    int n, m;
    int cnt = 0;

    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(visit[i]==0)
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}
