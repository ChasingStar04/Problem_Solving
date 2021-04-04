//재귀함수를 이용한 간단한 구현 문제입니다.
#include <iostream>
#include <cstring>

using namespace std;

char arr[6600][6600];

void Func(int x1, int x2, int y1, int y2, int mode)
{
    if(mode==0)
        return;
    if(x2-1==x1 && y2-1==y1 && mode)
    {
        arr[y1][x1] = '*';
        return;
    }

    int x_one_third = x1+(x2-x1)/3;
    int x_two_third = x1+(x2-x1)/3*2;
    int y_one_third = y1+(y2-y1)/3;
    int y_two_third = y1+(y2-y1)/3*2;

    Func(x1, x_one_third, y1, y_one_third, 1);
    Func(x_one_third, x_two_third, y1, y_one_third, 1);
    Func(x_two_third, x2, y1, y_one_third, 1);
    Func(x1, x_one_third, y_one_third, y_two_third, 1);
    Func(x_one_third, x_two_third, y_one_third, y_two_third, 0);
    Func(x_two_third, x2, y_one_third, y_two_third, 1);
    Func(x1, x_one_third, y_two_third, y2, 1);
    Func(x_one_third, x_two_third, y_two_third, y2, 1);
    Func(x_two_third, x2, y_two_third, y2, 1);
    return;
}

int main()
{
    int n;

    cin>>n;
    memset(arr, ' ', sizeof(arr));
    Func(0, n, 0, n, 1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<arr[i][j];
        cout<<'\n';
    }

    return 0;
}
