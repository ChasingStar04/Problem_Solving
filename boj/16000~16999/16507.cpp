//(1, 1)~(n, m)까지의 합을 저장하는 테이블을 만듭니다.
#include <iostream>

using namespace std;

int sum[1010][1010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, q;

    cin>>r>>c>>q;
    for (int i=1; i<=r; i++)
    {
        int cnt = 0;
        for (int j=1; j<=c; j++)
        {
            int num;
            cin>>num;
            cnt += num;
            sum[i][j] = sum[i-1][j] + cnt;
        }
    }

    int r1, c1, r2, c2, qsum;
    for (int i=0; i<q; i++)
    {
        cin>>r1>>c1>>r2>>c2;
        qsum = sum[r2][c2] + sum[r1-1][c1-1] - sum[r1-1][c2] - sum[r2][c1-1];
        cout<<qsum/((r2-r1+1)*(c2-c1+1))<<'\n';
    }

    return 0;
}
