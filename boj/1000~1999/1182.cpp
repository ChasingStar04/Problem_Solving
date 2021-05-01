//dfs로 부분수열을 만들 수 있는 모든 경우를 탐색합니다.
#include <iostream>

using namespace std;

int n, s;
int arr[20];
int cnt;

void dfs(int node, int sum)
{
    if (sum==s)
        cnt++;

    for (int i=node+1; i<n; i++)
    {
        //if (arr[node]<arr[i])
            dfs(i, sum+arr[i]);
    }
    return;
}

int main()
{
    cin>>n>>s;
    for (int i=0; i<n; i++)
        cin>>arr[i];
    
    for (int i=0; i<n; i++)
        dfs(i, arr[i]);
    cout<<cnt;

    return 0;
}
