//재귀. memset으로 초기값을 ' '로 해두면, 별을 찍는 것만 고려하면 됩니다.
#include <iostream>
#include <cstring>

using namespace std;

int tri_size[11];
char star[1050][1050]; //[y][x]

void SetStar(int s, int y, int x)
{
    if (s==0)
        star[y][x] = '*';
    else
    {
        SetStar(s-1, y, x);
        SetStar(s-1, y+tri_size[s-1], x);
        SetStar(s-1, y, x+tri_size[s-1]);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin>>n;

    tri_size[0] = 1;
    for (int i=1; i<=n; i++)
        tri_size[i] = tri_size[i-1]*2;
    memset(star, ' ', sizeof(star));

    SetStar(n, 0, 0);
    for (int y=0; y<tri_size[n]; y++)
    {
        for (int x=0; x<tri_size[n]-y; x++)
            cout<<star[y][x];
        cout<<'\n';
    }

    return 0;
}
