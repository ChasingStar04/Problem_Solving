//AC -> 에디토리얼 보고 최적화(코드길이 단축)
//조각의 위치를 나타내는 문자열을 key값으로 하여 BFS를 돌립니다.
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[10];

int main()
{
    int m;
    cin>>m;
    for (int i=0; i<m; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }

    string start = "000000000"; //s[i] = i번째 노드에 있는 조각. 0은 조각이 없음을 의미한다.
    for (int i=1; i<=8; i++)
    {
        int p;
        cin>>p;
        start[p-1] = i+'0';
    }
    
    map<string, int> visit;
    queue<string> que;
    que.push(start);
    visit[start] = 0;
    while (!que.empty())
    {
        string tmp = que.front();
        que.pop();

        if (tmp=="123456780")
        {
            cout<<visit[tmp];
            return 0;
        }

        int empty;
        for (int i=1; i<=9; i++)
            if (tmp[i-1]=='0')
                empty = i;
        
        for (int &i : edge[empty])
        {
            string ns = tmp;
            swap(ns[empty-1], ns[i-1]);
            if (visit.count(ns)==0)
            {
                que.push(ns);
                visit[ns] = visit[tmp]+1;
            }
        }
    }
    cout<<-1;

    return 0;
}
