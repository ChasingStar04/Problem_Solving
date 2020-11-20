/*
선행되어야 하는 건물의 개수를 used에, 자신을 필요로 하는 건물들을 road에 저장합니다.
used가 0인 번호부터 우선순위 큐에 넣습니다.
큐에서 나온 번호를 필요로 하는 번호들의 used를 -1하고, 만약 0이 된다면 우선순위 큐에 넣습니다.
큐에서 나온 번호가 w이면 그 번호의 시간을 출력하고, break합니다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Data
{
    int building;
    int time;
};

bool operator<(Data a, Data b)
{
    return a.time>b.time;
}

int used[1001];  //선행되어야 하는 건물의 개수
int time[1001];  //각 건물을 짓는데 걸리는 시간
priority_queue<Data>  pq;

int main()
{
    int t;

    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, k, w;
        vector<int> road[1001];

        memset(used, 0, sizeof(used));

        cin>>n>>k;
        for(int j=1; j<=n; j++)
            cin>>time[j];
        for(int j=0; j<k; j++)
        {
            int a, b;
            cin>>a>>b;
            road[a].push_back(b);
            used[b]++;
        }
        cin>>w;

        for(int j=1; j<=n; j++)  //선행건물이 필요없는 건물들을 우선순위 큐에 넣어줌
        {
            if(used[j]==0)
                pq.push({j, time[j]});
        while (!pq.empty())
        {
            Data tmp = pq.top();
            pq.pop();

            if(tmp.building==w)
            {
                cout<<tmp.time<<'\n';
                break;
            }
            for(int j=0; j<road[tmp.building].size(); j++)
            {
                used[road[tmp.building][j]]--;
                if(used[road[tmp.building][j]]==0)
                    pq.push({road[tmp.building][j], tmp.time+time[road[tmp.building][j]]});
            }
        }
        
        while(!pq.empty())
            pq.pop();
    }

    return 0;
}
