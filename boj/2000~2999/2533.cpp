/*
트리에서 어떤 노드와 연결되어 있는 노드는 부모 노드와 자식 노드 뿐입니다.
서브트리의 루트 노드가 인플루언서가 아니라면 직접 이어져 있는 자식 노드는 모두 인플루언서여야 하고,
인플루언서라면 직접 이어져 있는 자식 노드의 인플루언서의 여부는 상관 없습니다.

1번 노드를 루트 노드 삼아 탑다운 방식으로 탐색하고
메모이제이션을 이용하면 2000000번 이내에 구할 수 있습니다.
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> edge[1000010];
int isinf[1000010], notinf[1000010];
bool visit[1000010];

int MinInf(int root); //min(MinIsInf, MinNotInf)
int MinIsInf(int root); //root가 인플루언서인 서브트리의 최소 인플루언서 수
int MinNotInf(int root); //root가 인플루언서가 아닌 서브트리의 최소 인플루언서 수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    memset(isinf, -1, sizeof(isinf));
    memset(notinf, -1, sizeof(notinf));
    
    cout<<MinInf(1);

    return 0;
}

int MinInf(int root) //min(MinIsInf, MinNotInf)
{
    if (visit[root])
        return 0;
    
    int mii = MinIsInf(root);
    int mni = MinNotInf(root);
    return min(mii, mni);
}

int MinIsInf(int root) //root가 인플루언서인 서브트리의 최소 인플루언서 수
{
    if (visit[root])
        return 0;
    if (isinf[root]!=-1)
        return isinf[root];
    visit[root] = true;

    int ans = 1;
    for (int &i : edge[root])
        ans += MinInf(i);
    
    visit[root] = false;
    isinf[root] = ans;

    return ans;
}

int MinNotInf(int root) //root가 인플루언서가 아닌 서브트리의 최소 인플루언서 수
{
    if (visit[root])
        return 0;
    if (notinf[root]!=-1)
        return notinf[root];
    visit[root] = true;

    int ans = 0;
    for (int &i : edge[root])
        ans += MinIsInf(i);
    
    visit[root] = false;
    notinf[root] = ans;

    return ans;
}
