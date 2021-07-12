//중복을 고려하지 않고 계산한 다음, 중복을 뺍니다.
//중복을 빼는 방법은 각각의 노드마다 (부모 노드가 있으면 1, 없으면 0)*(자식 노드 수)*(자식 노드 수-1)/2 입니다.
#include <iostream>
#include <vector>

using namespace std;

long long result;
vector<int> edge[300010];
int length[300010];
bool visit[300010];
int n;

void GetLength(int node, int len)
{
    length[node] = len;
    for (int &i : edge[node])
    {
        if (i!=1 && length[i]==0)
            GetLength(i, len+1);
    }
    return;
}

int Delete(int node)
{
    visit[node] = true;
    int child = 1;

    for (int &i : edge[node])
    {
        if (!visit[i])
            child += Delete(i);
    }
    if (child>1)
        result -= (long long)(length[node] ? 1: 0)*child*(child-1)/2;
    return child;
}

int main()
{
    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    GetLength(1, 0);
    for (int i=1; i<=n; i++)
        result += (long long)length[i]*(n-1);
    
    /*for (int i=1; i<=n; i++)
        cout<<length[i]<<' ';
    cout<<'\n'<<result<<'\n';
    */
    Delete(1); //중복 제거

    cout<<result;

    return 0;
}
