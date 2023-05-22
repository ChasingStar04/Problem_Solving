/*
�Ÿ��� ���� �ּҰ� �Ǵ� �κ��� ������ �߾Ӱ��Դϴ�.
������ �簢���� �Ű��� �� �־����� ������ ��������� ���� �� ���ٸ�, �� �簢���� ������ �ƴϹǷ� �����̷��� �߾Ӱ��� ���ۿ� �����ϴ�.
������ �� ������ �� ��������.
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
