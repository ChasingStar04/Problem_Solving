//자신보다 작은 학생을 저장하는 인접리스트와, 자신보다 큰 학생을 저장하는 인접리스트를 만듭니다.
//X번 학생에서 탐색하여 자신보다 확실히 작은 학생과 자신보다 확실히 큰 학생을 구합니다.
//나머지 학생들이 모두 자신보다 작을 때가 가장 높은 등수, 나머지 학생들이 모두 자신보다 클 때가 가장 낮은 등수입니다.
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, x;
vector<int> up[100010], down[100010]; //자신 위에 있는 노드, 아래에 있는 노드
bool visit[100010];

int UpSearch(int node)
{
    int cnt = 1;
    visit[node] = true;
    for (int &i : up[node])
    {
        if (!visit[i])
            cnt += UpSearch(i);
    }
    return cnt;
}

int DownSearch(int node)
{
    int cnt = 1;
    visit[node] = true;
    for (int &i : down[node])
    {
        if (!visit[i])
            cnt += DownSearch(i);
    }
    return cnt;
}

int main()
{
    cin>>n>>m>>x;
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        down[a].push_back(b);
        up[b].push_back(a);
    }

    cout<<UpSearch(x)<<' '<<n-DownSearch(x)+1;

    return 0;
}
