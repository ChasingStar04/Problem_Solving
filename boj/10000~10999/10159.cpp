/*
먼저 자신보다 큰 값을 저장하는 벡터와 작은 값을 저장하는 벡터를 만듭니다.
어떤 물건과의 비교 결과를 알려면, 자신보다 확실히 크거나 자신보다 확실히 작아야 하므로
큰 쪽으로 DFS를 돌려 지나간 노드의 개수를 구하고, 작은 쪽으로도 DFS를 돌려 지나간 노드의 개수를 구합니다.
두 값의 합이 자신과 비교할 수 있는 물건의 개수입니다.
따라서 비교할 수 없는 물건의 개수는 n-(두 값의 합)-1 입니다.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> big[110], small[110]; //자기보다 더 큰거, 더 작은거

int visit[110];
int now;

int BigDFS(int node)
{
    int ans = 0;
    visit[node] = now;

    for (int &i : big[node])
    {
        if (visit[i]!=now)
        {
            ans++;
            ans += BigDFS(i);
        }
    }
    return ans;
}

int SmallDFS(int node)
{
    int ans = 0;
    visit[node] = -now;

    for (int &i : small[node])
    {
        if (visit[i]!=-now)
        {
            ans++;
            ans += SmallDFS(i);
        }
    }
    return ans;
}

int main()
{
    int n, m;

    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        big[b].push_back(a);
        small[a].push_back(b);
    }

    for (int i=1; i<=n; i++)
    {
        now = i;
        cout<<n-BigDFS(i)-SmallDFS(i)-1<<'\n';
    }
    
    return 0;
}
