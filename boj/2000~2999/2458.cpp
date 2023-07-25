//큰쪽 작은쪽 DFS두번
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> edge[510][2]; //[][0] -> 나보다 큼, [][2] -> 나보다 작음
bool visit[510];

int Search(int node, int bs)
{
    if (visit[node])
        return 0;
    visit[node] = true;

    int ans = 1;
    for (int &newnode : edge[node][bs])
        ans += Search(newnode, bs);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, res = 0;

    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int s, b;
        cin>>s>>b;
        edge[s][0].push_back(b);
        edge[b][1].push_back(s);
    }

    for (int i=1; i<=n; i++)
    {
        memset(visit, false, sizeof(visit));
        int know = Search(i, 0);
        visit[i] = false;
        know += Search(i, 1);
        if (know-1==n)
            res++;
    }
    cout<<res;

    return 0;
}
