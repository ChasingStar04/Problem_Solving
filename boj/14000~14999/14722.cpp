//생각보다 까다로웠다
//한 지점에서는 같은 행과 열의 가게들만 보기 때문에 DP 테이블을 행과 열 단위로 만들었습니다.
#include <iostream>

using namespace std;

int n, res;
int milk[1010][1010];
int maxx[1010][3], maxy[1010][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cin>>milk[i][j];
    }

    for (int x=1; x<=n; x++)
    {
        for (int y=1; y<=n; y++)
        {
            int m = milk[x][y];

            for (int i=0; i<3; i++)
            {
                maxx[x][i] = max(maxx[x][i], maxy[y][i]);
                maxy[y][i] = max(maxx[x][i], maxy[y][i]);
            }

            int newmax = max(maxx[x][(m+2)%3], maxy[y][(m+2)%3]);
            if (m==0 || newmax>0)
            {
                maxx[x][m] = max(maxx[x][m], newmax+1);
                maxy[y][m] = max(maxy[y][m], newmax+1);
                res = max(res, max(maxx[x][m], maxy[y][m]));
            }
        }
    }

    cout<<res;
    
    return 0;
}
