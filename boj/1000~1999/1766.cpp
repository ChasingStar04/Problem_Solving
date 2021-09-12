//위상 정렬 + pq
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> edge[32010];
int table[32010];

int main()
{
    int n, m;

    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a].push_back(b);
        table[b]++;
    }

    for (int i=1; i<=n; i++)
    {
        if (table[i]==0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int tmp = pq.top();
        pq.pop();

        cout<<tmp<<' ';
        for (int &i : edge[tmp])
        {
            table[i]--;
            if (table[i]==0)
                pq.push(i);
        }
    }

    return 0;
}
