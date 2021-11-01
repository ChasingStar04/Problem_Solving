//AC
//연결된 노드 수가 n-1개인 노드가 있는지 확인합니다.
#include <iostream>

using namespace std;

int cnt[100010];

int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }

    for (int i=1; i<=n; i++)
    {
        if (cnt[i]==n-1)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";

    return 0;
}
