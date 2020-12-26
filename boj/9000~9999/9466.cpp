/*
처음에 모든 노드의 팀은 -1입니다.

각각의 노드에서 탐색하여
만약 팀이 0 또는 1인 노드를 만난다면 출발 노드의 팀을 0으로 설정한뒤 cnt를 1 증가시킵니다.
만약 사이클을 만난다면 사이클에 포함되어있는 노드의 팀은 1, 포함되지 않은 노드의 팀은 0으로 설정하고
출발 노드가 사이클에 포함되어 있지 않다면 cnt를 1 증가시킵니다.
*/
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int choose[100010];
int have_team[100010];  //-1 => 정해지지않음, 0 => 팀X, 1 => 팀O
int visit[100010];

//사이클이 있는지 검사하고 있다면 사이클에 있는 노드들의 have_team을 true로 설정해줍니다.
int FindCycle(int node)
{
    stack<int> stk;

    stk.push(node);
    visit[node] = node;
    while(visit[choose[stk.top()]]!=node && have_team[choose[stk.top()]]==-1)  //다음 탐색할 노드가 이미 방문되있거나, 팀이 정해져 있다면 break
    {
        stk.push(choose[stk.top()]);
        visit[stk.top()] = node;
    }
    
    if(have_team[choose[stk.top()]]!=-1)  //이미 확인한 사이클이라면
    {
        have_team[node] = 0;
        return 1;
    }
    else  //확인하지 않은 사이클이라면
    {
        int last = choose[stk.top()];  //사이클에 포함되어있는 마지막 노드
        int team = 1;

        while(!stk.empty())
        {
            int tmp = stk.top();
            stk.pop();
            have_team[tmp] = team;
            if(last==tmp)
                team--;
        }

       if(last==node)
            return 0;
        else
            return 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, cnt = 0;
        
        cin>>n;
        for(int j=1; j<=n; j++)
            cin>>choose[j];
        
        memset(have_team, -1, sizeof(have_team));
        memset(visit, 0, sizeof(visit));
        for(int j=1; j<=n; j++)
        {
            if(have_team[j]==-1)
                cnt += FindCycle(j);
            else if(have_team[j]==0)
                cnt += 1;
        }
        cout<<cnt<<'\n';
    }

    return 0;
}
