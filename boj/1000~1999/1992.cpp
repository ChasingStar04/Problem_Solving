/*
함수로 주어진 범위에 수가 모두 같으면 그 수를 출력하고
아니라면 범위를 네 부분으로 나눠 위 과정을 반복합니다.
*/
#include <iostream>

using namespace std;

char map[64][64];

bool AllSame(int x1, int x2, int y1, int y2)
{
    char s = map[y1][x1];
    for(int i=y1; i<y2; i++)
    {
        for(int j=x1; j<x2; j++)
        {
            if(map[i][j]!=s)
                return false;
        }
    }
    return true;
}

void Divide(int x1, int x2, int y1, int y2)
{
    if(AllSame(x1, x2, y1, y2))
        cout<<map[y1][x1];
    else
    {
        cout<<'(';
        Divide(x1, (x1+x2)/2, y1, (y1+y2)/2);
        Divide((x1+x2)/2, x2, y1, (y1+y2)/2);
        Divide(x1, (x1+x2)/2, (y1+y2)/2, y2);
        Divide((x1+x2)/2, x2, (y1+y2)/2, y2);
        cout<<')';
    }
    return;
}

int main()
{
    int n;

    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin>>map[i][j];
    }
    
    Divide(0, n, 0, n);

    return 0;
}
