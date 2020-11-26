/*
간단한 dfs 문제입니다.
visit 테이블을 만들어 탐색한 사이클은 체크해줘서
탐색하지 않은 사이클만 탐색하도록 하여 사이클의 개수를 구합니다.
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int road[1001];  //각 노드에서 이어진 간선을 저장
int visit[1001];

int isCycle(int node)
{
    vector<int> stk;

    stk.push_back(node);
    while (road[stk.back()]!=stk.front())
    {
        if(visit[stk.back()])
            return 0;
        stk.push_back(road[stk.back()]);
    }
    
    while (!stk.empty())
    {
        visit[stk.back()] = 1;
        stk.pop_back();
    }
    return 1;
}

int main()
{
    int t;

    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, result = 0;

        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>road[i];
        
        memset(visit, 0, sizeof(visit));
        for(int i=1; i<=n; i++)
        {
            if(visit[i]==0)
                result += isCycle(i);
        }
        cout<<result<<'\n';
    }
}
