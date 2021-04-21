//재귀함수를 이용하여 직사각형을 세 조각으로 나눌 수 있는 모든 방법으로 나눠봅니다.
#include <iostream>

using namespace std;

int arr[110][110];

long long Count(int x1, int x2, int y1, int y2)
{
    long long sum = 0;
    for (int i=y1; i<=y2; i++)
    {
        for (int j=x1; j<=x2; j++)
            sum += arr[i][j];
    }
    return sum;
}

long long Func(int x1, int x2, int y1, int y2, int piece)
{
    if (piece==1)
        return Count(x1, x2, y1, y2);
    long long ans = 0;
    for (int i=y1; i<y2; i++)
    {
        if (x1!=x2 || i!=y1)
            ans = max(ans, Func(x1, x2, y1, i, piece-1)*Count(x1, x2, i+1, y2));
        ans = max(ans, Count(x1, x2, y1, i)*Func(x1, x2, i+1, y2, piece-1));
    }
    for (int i=x1; i<x2; i++)
    {
        if (y1!=y2 || i!=x1)
            ans = max(ans, Func(x1, i, y1, y2, piece-1)*Count(i+1, x2, y1, y2));
        ans = max(ans, Count(x1, i, y1, y2)*Func(i+1, x2, y1, y2, piece-1));
    }

    return ans;
}

int main()
{
    int n, m;

    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            scanf("%1d", &arr[i][j]);
    }
    
    cout<<Func(0, m-1, 0, n-1, 3);

    return 0;
}
