//그룹을 설정하는 dfs + 리더를 결정하는 bfs
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
vector<int> edge[110], leader;
int group[110], groupsize[110];
int mintime[110], minnode[110];

struct nt
{
    int n;
    int t;
};

int SetGroup(int node, int g)
{
    int res = 1;
    group[node] = g;
    for (int &i : edge[node])
    {
        if (group[i]==0)
            res += SetGroup(i, g);
    }
    return res;
}

int GetTime(int node, int g)
{
    queue<nt> que;
    int cnt = 0;
    bool visit[110] = {0};
    que.push({node, 0});
    while (!que.empty())
    {
        nt newnt = que.front();
        que.pop();

        if (visit[newnt.n])
            continue;
        visit[newnt.n] = true;
        cnt++;
        if (cnt==groupsize[g])
            return newnt.t;
        for (int &i : edge[newnt.n])
            que.push({i, newnt.t+1});
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int gcnt = 0;
    memset(mintime, 0x3f, sizeof(mintime));
    for (int i=1; i<=n; i++)
    {
        if (group[i]==0)
        {
            gcnt++;
            groupsize[gcnt] = SetGroup(i, gcnt);
        }
        int mygroup = group[i];
        int mt = GetTime(i, mygroup);
        if (mt<mintime[mygroup])
        {
            mintime[mygroup] = mt;
            minnode[mygroup] = i;
        }
    }

    for (int i=1; i<=gcnt; i++)
        leader.push_back(minnode[i]);
    sort(leader.begin(), leader.end());

    cout<<gcnt<<'\n';
    for (int &i : leader)
        cout<<i<<'\n';
    
    return 0;
}
