/*
전위: 출력 -> 왼쪽호출 -> 오른쪽호출
중위: 왼쪽호출 -> 출력 -> 오른쪽호출
후위: 왼쪽호출 -> 오른쪽호출 -> 출력
재귀함수로 구현합니다.
*/
#include <iostream>
#include <utility>

using namespace std;

pair<int, int> edge[30];  //1->A, 2->B, ...

void PreOrder(int node)
{
    printf("%c", (char)node-1+'A');
    if(edge[node].first)  PreOrder(edge[node].first);
    if(edge[node].second)  PreOrder(edge[node].second);
    return;
}

void InOrder(int node)
{
    if(edge[node].first)  InOrder(edge[node].first);
    printf("%c", (char)node-1+'A');
    if(edge[node].second)  InOrder(edge[node].second);
    return;
}

void PostOrder(int node)
{
    if(edge[node].first)  PostOrder(edge[node].first);
    if(edge[node].second)  PostOrder(edge[node].second);
    printf("%c", (char)node-1+'A');
    return;
}

int main()
{
    int n;
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        char node, a, b;
        cin>>node>>a>>b;
        if(a!='.')  edge[node-'A'+1].first = a-'A'+1;
        if(b!='.')  edge[node-'A'+1].second = b-'A'+1;
    }
    
    PreOrder(1);
    cout<<'\n';
    InOrder(1);
    cout<<'\n';
    PostOrder(1);

    return 0;
}
