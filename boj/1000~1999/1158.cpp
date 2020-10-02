/*
원에서는 자기순서가 지나가면 한바퀴를 돌아야 다시 순서가 옵니다. 즉, 자기순서가 지나가면 가장 마지막 순서가 됩니다.
이걸 큐에서 front값을 맨 뒤에 push한 후 pop해주는 것으로 표현할 수 있습니다.

k-1번 front값을 맨 뒤에 push한후 pop해준 뒤
front값을 출력 후 pop 하는 과정을 큐가 빌 때까지 반복합니다.
*/
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;


int main()
{
    queue<int> qu;
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        qu.push(i);
    cout<<'<';
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<k; j++)
        {
            qu.push(qu.front());
            qu.pop();
        }
        cout<<qu.front();
        qu.pop();
        if(i!=n-1)  cout<<", ";
    }
    cout<<'>';
    return 0;
}
