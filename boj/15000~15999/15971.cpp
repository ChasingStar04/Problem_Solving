//한 점에서 다른 한 점으로 가는 경로는 유일하므로 (경로 길이)-(가장 긴 통로의 길이) 가 답이 될 것입니다.
//DFS 돌려서 구하면 됩니다.
#include <iostream>
#include <vector>

using namespace std;

struct Data
{
    int node;
    int length;
};

int n, r1, r2;
vector<Data> edge[100010];
bool visit[100010];
int result;

int DFS(int node, int len, int max_edge)
{
    if (node==r2)
        return len-max_edge;
    
    for (Data &i : edge[node])
    {
        if (!visit[i.node])
        {
            visit[i.node] = true;
            int res = DFS(i.node, len+i.length, max(max_edge, i.length));
            if (res!=-1)
                return res;
        }
    }

    return -1;
}

int main()
{
    cin>>n>>r1>>r2;
    for (int i=0; i<n-1; i++)
    {
        int n1, n2, len;
        cin>>n1>>n2>>len;
        edge[n1].push_back({n2, len});
        edge[n2].push_back({n1, len});
    }

    visit[r1] = true;
    cout<<DFS(r1, 0, 0);

    return 0;
}
