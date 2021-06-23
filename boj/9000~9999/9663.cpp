//x축과 양 대각선을 체크테이블로 하여 dfs를 돌립니다.
#include <iostream>

using namespace std;

int n, ans;
bool x[15], di1[30], di2[30]; //x축, \대각선, /대각선

void dfs(int y)
{
    if (y>=n)
    {
        ans++;
        return;
    }

    for (int i=0; i<n; i++)
    {
        if (x[i] || di1[i+y] || di2[y-i+n-1])
            continue;
        x[i] = true;
        di1[i+y] = true;
        di2[y-i+n-1] = true;
        dfs(y+1);
        x[i] = false;
        di1[i+y] = false;
        di2[y-i+n-1] = false;
    }
    return;
}

int main()
{
    cin>>n;
    
    dfs(0);
    cout<<ans;

    return 0;
}
