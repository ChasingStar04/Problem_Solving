/*
거리의 합이 최소가 되는 부분은 점들의 중앙값입니다.
만나는 사각형을 옮겼을 때 멀어지는 점보다 가까워지는 점이 더 많다면, 그 사각형은 최적이 아니므로 최적이려면 중앙값일 수밖에 없습니다.
정렬을 쓸 생각을 왜 못했을까.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n, m;
    int xspot[10010] = {0}, yspot[10010] = {0};
    int c, xmin = 0, ymin = 0;

    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int y, x;
        cin>>y>>x;
        xspot[x]++;
        yspot[y]++;
    }

    c = 0;
    for (int i=1; i<=n; i++)
    {
        c += xspot[i];
        if (c>=m-c)
        {
            int sc;
            for (int j=1; j<=n; j++)
            {
                sc = xspot[j];
                xmin += (abs(i-j)*sc);
            }
            break;
        }
    }
    c = 0;
    for (int i=1; i<=n; i++)
    {
        c += yspot[i];
        if (c>=m-c)
        {
            int sc;
            for (int j=1; j<=n; j++)
            {
                sc = yspot[j];
                ymin += (abs(i-j)*sc);
            }
            break;
        }
    }

    cout<<xmin+ymin;

    return 0;
}
