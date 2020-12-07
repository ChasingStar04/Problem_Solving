//dfs로 1번 컴퓨터와 연결되어있는 컴퓨터의 개수를 출력합니다.
#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[110];
bool visit[110];
int cnt;  //바이러스에 걸리게 되는 컴퓨터의 수(1 포함)

void dfs(int node)
{
    if(visit[node])
        return;
    visit[node] = true;
    cnt++;

    for(int i=0; i<edge[node].size(); i++)
        dfs(edge[node][i]);
    return;
}

int main()
{
    int n, m;  //n=컴퓨터의 수, m=컴퓨터 쌍의 수

    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1);
    cout<<cnt-1;

    return 0;
}
