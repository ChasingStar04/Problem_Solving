/*
각 버스를 노드로 생각하면, 이 문제는 노드간 연결 조건이 특이하게 주어진 BFS 문제일 뿐입니다.
두 선분이 만나면 연결되어 있고, 만나지 않는다면 연결되어 있지 않습니다.
시작점과 목적지 또한 노드로 두어, 시작점을 0번 노드, 버스를 1~k번 노드, 목적지를 k+1번 노드로 두고 BFS로 해결했습니다.
두 선분의 만남 여부를 판단하는 것이 제일 힘들었습니다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Spot
{
    int x;
    int y;
} start, dest;

struct Line
{
    int dire; //0==수직(x동일), 1==수평(y동일)
    Spot s1;
    Spot s2;
} bus[5010];

bool SpotToLine(Spot s, Line l)
{
    return (s.x>=l.s1.x && s.x<=l.s2.x && s.y>=l.s1.y && s.y<=l.s2.y);
}

bool LineToLine(Line l1, Line l2)
{
    if (l1.dire==l2.dire)
    {
        if (l1.dire==0)
        {
            if (l1.s1.x!=l2.s2.x) return false;
            return (l1.s1.y>=l2.s1.y && l1.s1.y<=l2.s2.y) || (l1.s2.y>=l2.s1.y && l1.s2.y<=l2.s2.y) || (l1.s1.y<=l2.s1.y && l1.s2.y>=l2.s2.y);
            //l1의 s1이 l2에 포함되거나, l1의 s2가 l2에 포함되거나, l2가 l1에 포함되거나
        }
        else
        {
            if (l1.s1.y!=l2.s2.y) return false;
            return (l1.s1.x>=l2.s1.x && l1.s1.x<=l2.s2.x) || (l1.s2.x>=l2.s1.x && l1.s2.x<=l2.s2.x) || (l1.s1.x<=l2.s1.x && l1.s2.x>=l2.s2.x);
            //l1의 s1이 l2에 포함되거나, l1의 s2가 l2에 포함되거나, l2가 l1에 포함되거나
        }
    }
    else if (l1.dire==0)
        return (l1.s1.x>=l2.s1.x) && (l1.s1.x<=l2.s2.x) && (l2.s1.y>=l1.s1.y) && (l2.s1.y<=l1.s2.y);
    else //l2.dire==0
        return (l1.s1.y>=l2.s1.y) && (l1.s1.y<=l2.s2.y) && (l2.s1.x>=l1.s1.x) && (l2.s1.x<=l1.s2.x);
}

int m, n, k;
vector<int> edge[5010];
bool visit[5010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>m>>n;
    cin>>k;
    for (int i=0; i<k; i++)
    {
        int b;
        Spot s1, s2;

        cin>>b>>s1.x>>s1.y>>s2.x>>s2.y;
        bus[b].s1 = s1;
        bus[b].s2 = s2;
        if (s1.x==s2.x)
        {
            bus[b].dire = 0;
            if (s1.y>s2.y)
                swap(bus[b].s1, bus[b].s2);
        }
        else
        {
            bus[b].dire = 1;
            if (s1.x>s2.x)
                swap(bus[b].s1, bus[b].s2);
        }
    }
    cin>>start.x>>start.y>>dest.x>>dest.y;

    for (int i=1; i<=k; i++) //시작점 <=> 버스
    {
        if (SpotToLine(start, bus[i]))
        {
            edge[0].push_back(i);
            edge[i].push_back(0);
        }
    }

    for (int i=1; i<=k; i++) //버스 <=> 버스
    {
        for (int j=i+1; j<=k; j++)
        {
            if (LineToLine(bus[i], bus[j]))
            {
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }

    for (int i=1; i<=k; i++) //버스 <=> 목적지
    {
        if (SpotToLine(dest, bus[i]))
        {
            edge[k+1].push_back(i);
            edge[i].push_back(k+1);
        }
    }

    if (start.x==dest.x && start.y==dest.y) //시작점 <=> 목적지. 근데 이런 경우가 있을까?
    {
        edge[0].push_back(k+1);
        edge[k+1].push_back(0);
    }

    queue<pair<int, int>> que; //(노드 번호, 환승횟수)
    que.push(make_pair(0, -1));
    visit[0] = true;
    while (!que.empty())
    {
        pair<int, int> now = que.front();
        que.pop();

        if (now.first==k+1)
        {
            cout<<now.second;
            break;
        }

        for (int &i : edge[now.first])
        {
            if (!visit[i])
            {
                que.push(make_pair(i, now.second+1));
                visit[i] = true;
            }
        }
    }
    
    return 0;
}
