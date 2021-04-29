//dfs를 이용하여 갈 수 있는 모든 경로를 탐색합니다.
#include <iostream>

#define INF 0x3f3f3f3f

using namespace std;

int w[10][10];
bool check[10];
int n;

int dfs(int node, int visit, int cost) //현재 도시, 방문한 도시 수(현재도시포함), 비용
{
    if (visit==n)
        return (w[node][0]>0) ? cost+w[node][0] : INF; //한바퀴를 돌아야 하므로 현재노드->0번노드 까지의 비용을 더해줌
    
    check[node] = true;

    int result = INF;
    for (int i=0; i<n; i++)
    {
        if (w[node][i] && !check[i])
            result = min(result, dfs(i, visit+1, cost+w[node][i]));
    }
    check[node] = false;

    return result;
}

int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin>>w[i][j];
    }

    cout<<dfs(0, 1, 0); //0번노드에서 출발

    return 0;
}
